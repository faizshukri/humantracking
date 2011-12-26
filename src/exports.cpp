#include "exports.h"
#include "ui_exports.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QtCore>
#include <QThreadPool>

using namespace cv;

//static int i = 0, j = 0;

Exports::Exports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exports),
    totalProgress(0),
    curFrame(0),
    count(0)

{
    //this->_timer = new QTimer(this);
    ui->setupUi(this);

    showProgressBar(false);

    //Hide the group by at initialization
    ui->groupEdge->hide();
    ui->groupFlip->hide();
    ui->groupHumanDetect->hide();

    ui->txtThresh->setValidator(new QIntValidator(0,100, this));
    ui->txtThresh->setFixedWidth(30);

    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(browseVideos()));
    connect(ui->btnExport, SIGNAL(clicked()), this, SLOT(timerTick()));
    //connect(this->_timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    connect(ui->checkEdge, SIGNAL(toggled(bool)), this, SLOT(toggleEdge(bool)));
    connect(ui->checkFlip, SIGNAL(toggled(bool)), this, SLOT(toggleFlip(bool)));
    connect(ui->checkHuman, SIGNAL(toggled(bool)), this, SLOT(toggleHumanDetec(bool)));
    connect(ui->slideThresh, SIGNAL(valueChanged(int)), this, SLOT(setThresh(int)));
    connect(ui->txtThresh, SIGNAL(textChanged(QString)), this, SLOT(setThresh(QString)));

    this->effect = new Effects();
    this->setting = Settings::getInstance(this);

}

void Exports::setupThread(QThread &thread){
    connect(&thread, SIGNAL(started()),this, SLOT(timerTick()));
}

void Exports::setCurFrame(int cur){
    this->curFrame++;
    ui->progressBarTotal->setValue(this->curFrame);
    if(ui->progressBarTotal->value() == this->totalProgress){
        ui->btnBrowse->setDisabled(false);
        int ret = QMessageBox::information(this, "Export Result", "Your videos have been processed successfully.", QMessageBox::Open | QMessageBox::Ok);

        if(ret == QMessageBox::Open){
            QProcess::startDetached("explorer " + this->setting->getExportPath());
        }
    }
}

Exports::~Exports()
{
    delete ui;
    this->reBrowse();
    delete capture;
}

void Exports::toggleEdge(bool state){
    if(state) ui->groupEdge->show();
    else ui->groupEdge->hide();
}

void Exports::toggleFlip(bool state){
    if(state) ui->groupFlip->show();
    else ui->groupFlip->hide();
}

void Exports::toggleHumanDetec(bool state){
    if(state) ui->groupHumanDetect->show();
    else ui->groupHumanDetect->hide();
}

void Exports::reBrowse(){
    for(int i = 0; i < this->count; i++){
        capture[i]->release();
        delete capture[i];
        delete thread[i];

        capture[i] = 0;
        thread[i] = 0;
    }
   // writer->~VideoWriter();
    this->count = 0;
    this->totalProgress = 0;
    this->curFrame = 0;
    this->fileName.clear();
    ui->listVideos->clear();
    ui->progressBarTotal->setValue(0);
}

void Exports::browseVideos(){

    QStringList path = QFileDialog::getOpenFileNames(this,"Select video files to export", "", "Video Files (*.avi)");

    if(!path.isEmpty()){

        if(this->count != 0) //if the list already have item, reset it
            this->reBrowse();

        ui->listVideos->addItems(path);

        this->count = path.count();
        this->capture = new cv::VideoCapture*[this->count];
        this->thread = new processThread*[this->count];

        for(int i = 0; i < this->count; i++){
            this->capture[i] = new cv::VideoCapture(path.at(i).toStdString());
            this->totalProgress += capture[i]->get(CV_CAP_PROP_FRAME_COUNT);

            QFileInfo pathInfo( path.at(i) );
            this->fileName.append(pathInfo.fileName());
        }

        ui->progressBarTotal->setMaximum(this->totalProgress);

        //ui->checkFlip->setText(this->fileName.at(this->count - 1));

        //ui->checkEdge->setText(QString::number(this->count));
    }
}

void Exports::showProgressBar(bool state){
    if(state) {
        ui->lblTotalProgress->show();
        ui->progressBarTotal->show();
    } else {
        ui->lblTotalProgress->hide();
        ui->progressBarTotal->hide();
    }

}

void Exports::setThresh(int val){
    ui->txtThresh->setText(QString::number(val));
}

void Exports::setThresh(QString val){
    ui->slideThresh->setValue(val.toInt());
}


void Exports::timerTick(){

    showProgressBar(true);
    ui->btnBrowse->setDisabled(true);

    cv::Mat img;

    for(int i = 0; i < this->count; i++){

        this->capture[i]->operator >>( img );
        if(!img.data) break;
        string path = this->setting->getExportPath().toStdString() + "\\" + this->fileName.at(i).toStdString();
       // this->writer = new cv::VideoWriter(path, CV_FOURCC('D','I','V','X'), this->capture[i]->get(CV_CAP_PROP_FPS), img.size(), true);

        this->thread[i] = new processThread(this,this->capture[i],path);
        connect(this->thread[i], SIGNAL(currentFrame(int)), this, SLOT(setCurFrame(int)));
        setInitialProp(this->thread[i]);


        QThreadPool::globalInstance()->start(new MyTask(thread[i]));
        //this->thread[i]->start();

    }
}


void Exports::setInitialProp(processThread *athread){

    if(ui->checkHuman->isChecked() && ui->radioSurf->isChecked()){
        //effect->SurfD(img);
        athread->surf = true;
    } else if(ui->checkHuman->isChecked() && ui->radioHog->isChecked()){
       // effect->HogD(img);
        athread->hog = true;
    }

    //Check Edge Detection state
    if(ui->checkEdge->isChecked() && ui->checkEdgeInvert->isChecked()){
        //effect->Edge(img, img, ui->slideThresh->value(), true);
        athread->edge = true; athread->edgeInvert = true; athread->edgeThresh = ui->slideThresh->value();
    } else if(ui->checkEdge->isChecked()){
        //effect->Edge(img, img, ui->slideThresh->value(), false);
        athread->edge = true; athread->edgeInvert = true;
    }

    //Check Flip state
    if(ui->checkFlip->isChecked() && ui->checkFlipHor->isChecked() && ui->checkFlipVer->isChecked()){
        //effect->Flip(img, img, -1); //Both
        athread->flip = true; athread->flipCode = -1;
    } else if(ui->checkFlip->isChecked() && ui->checkFlipVer->isChecked()){
        //effect->Flip(img, img, 0); //Ver
        athread->flip = true; athread->flipCode = 0;
    } else if(ui->checkFlip->isChecked()  && ui->checkFlipHor->isChecked()){
        //effect->Flip(img, img, 1); //Hor
        athread->flip = true; athread->flipCode = 1;
    }

    //we need the writer
    athread->setWriter( true );
}

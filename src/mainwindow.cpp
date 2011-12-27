#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QDialog>
#include <QThreadPool>
#include <QMutex>
#include <QProgressBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    curFrame(0),
    totalFrame(0),
    captureFrame(false),
    captureFrames(false),
    hasVideo(false)
{
    ui->setupUi(this);
    ui->txtThresh->setValidator(new QIntValidator(0, 100, this));
    ui->txtThresh->setFixedWidth(30);
    toggleDetectHuman(ui->checkHuman->isChecked());
    toggleEdge(ui->checkEdge->isChecked());
    toggleFlip(ui->checkFlip->isChecked());

    //Connect all the element
    connect(ui->checkHuman, SIGNAL(toggled(bool)), this, SLOT(toggleDetectHuman(bool)));
    connect(ui->slideTimeline, SIGNAL(sliderMoved(int)), this, SLOT(setTimeline(int)));
    connect(ui->btnSnap, SIGNAL(clicked()), this, SLOT(toggleCaptureFrame()));
    connect(ui->btnPlayPause, SIGNAL(clicked()), this, SLOT(togglePlayPause()));
    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(loadFile()));

    //Check the effect setting

    this->exports = new Exports(this);
    this->settings = Settings::getInstance(this);
    this->aboutUs = new About(this);
    this->effect = new Effects();

    aboutUs->setFixedSize(400, 180);
    //set of action
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExports, SIGNAL(triggered()), exports, SLOT(open()));
    connect(ui->actionGlobal_Settings, SIGNAL(triggered()), settings, SLOT(open()));
    connect(ui->actionAbout_Us, SIGNAL(triggered()), aboutUs, SLOT(open()));
    connect(ui->actionCapture_all_frames, SIGNAL(triggered()), this, SLOT(toggleCaptureFrames()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleDetectHuman(bool state){

    if(state){
        ui->groupAlgorithm->show();
        if(ui->radioSurf->isChecked()) toggleSurf(true);
        if(ui->radioHog->isChecked()) toggleHog(true);
    } else {
        ui->groupAlgorithm->hide();
        toggleSurf(false);
        toggleHog(false);
    }
}


void MainWindow::toggleEdge(bool state){
    if(state){
        ui->groupThresh->show();
        mThread->edge = true;
        if(ui->checkEdgeInvert->isChecked()) mThread->edgeInvert = true;
    } else {
        ui->groupThresh->hide();
        mThread->edge = false;
        mThread->edgeInvert = false;
    }
}

void MainWindow::toggleEdgeInvert(bool state){
    if(state) mThread->edgeInvert = true;
    else mThread->edgeInvert = false;
}

void MainWindow::toggleFlip(bool state){
    if(state){
        ui->groupFlip->show();
        if(!ui->checkFlipHor->isChecked() && !ui->checkFlipVer->isChecked()){ mThread->flip = false; }
        else { mThread->flip = true; }
    } else {
        mThread->flip = false;
        ui->groupFlip->hide();
    }
}

void MainWindow::toggleFlipHor(bool state)
{
    if(state){
         mThread->flip = true;
        if(ui->checkFlipVer->isChecked()) { mThread->flipCode = -1; }  //Both
        else { mThread->flipCode = 1; } //Hor only
    } else {
        if(ui->checkFlipVer->isChecked()) { mThread->flip = true; mThread->flipCode = 0; } //Ver only
        else { mThread->flip = false; }
    }
}

void MainWindow::toggleFlipVer(bool state)
{
    if(state){
         mThread->flip = true;
        if(ui->checkFlipHor->isChecked()){ mThread->flipCode = -1; } //Both
        else { mThread->flipCode = 0; } //Ver only
    } else {
        if(ui->checkFlipHor->isChecked()) { mThread->flip = true; mThread->flipCode = 1; } //Hor only
        else { mThread->flip = false; }
    }
}


void MainWindow::togglePlayPause(){
    if(!this->mThread->pause){
        this->mThread->pause = true;
        ui->btnPlayPause->setIcon(QIcon(":/images/play"));
    } else {
        mThread->pause = false;
        QThreadPool::globalInstance()->start(new MyTask(this->mThread));
        ui->btnPlayPause->setIcon(QIcon(":/images/pause"));
    }

}

void MainWindow::toggleSurf(bool state)
{
    if(state && ui->checkHuman->isChecked())
        mThread->surf = true;
    else
        mThread->surf = false;
}

void MainWindow::toggleHog(bool state)
{
    if(state && ui->checkHuman->isChecked())
        mThread->hog = true;
    else
        mThread->hog = false;
}

void MainWindow::toggleCaptureFrame(){
    this->captureFrame = true;
}

void MainWindow::toggleCaptureFrames(){


    this->curFrame = 0;
    this->capture->set(CV_CAP_PROP_POS_FRAMES, 0);
    this->captureFrames = true;

    QDateTime timestem = QDateTime::currentDateTime();
    this->folderPath = this->settings->getSnapPath() + "/" + (timestem.toString("yy-MM-dd hh-mm-ss"));

    QDir dir(this->folderPath);

    if(!dir.exists(this->folderPath)){
        dir.mkdir(this->folderPath);
    }

    this->dialogSnaps = new dialogSnapFrames(this, this->totalFrame);
    this->dialogSnaps->setFixedWidth(300);
    this->dialogSnaps->open();
}

void MainWindow::setThresh(int val){
    ui->txtThresh->setText(QString::number(val));
    mThread->edgeThresh = val;
}

void MainWindow::setThresh(QString val){
    ui->slideThresh->setValue(val.toInt());
    mThread->edgeThresh = val.toInt();
}

void MainWindow::setTimeline(int val){
    //mThread->pauseAt = val;
    emit setCurPos(val);
    curFrame = val;
}

void MainWindow::saveToFolder(Mat &img){
    QDateTime timestem = QDateTime::currentDateTime();
    string path = this->settings->getSnapPath().toStdString() + "/" + (timestem.toString("yy-MM-dd hh-mm-ss")).toStdString() + ".jpg";
    cv::imwrite(path, img);
    QMessageBox msgBox;
    msgBox.setText("The frame has been saved.");
    msgBox.setWindowTitle("Information");
    msgBox.exec();
    this->captureFrame = false;
}

void MainWindow::snapAllFrames(Mat &img){

    string fileName = this->folderPath.toStdString() + "/" + QString::number(this->curFrame).toStdString() + ".jpg";
    cv::imwrite(fileName, img);

    emit displayCurProgress(this->curFrame, this->totalFrame);
}


//Connect all the effect button and display that want to be send to thread
void MainWindow::initEffectAndGui(){
    //To passing object Mat via signal and slot
    typedef Mat AMAT;
    qRegisterMetaType<AMAT>("Mat");

    connect(this->mThread, SIGNAL(currentFrame(int,Mat)), this, SLOT(displayResult(int,Mat)));
    connect(ui->radioSurf, SIGNAL(toggled(bool)), this, SLOT(toggleSurf(bool)));
    connect(ui->radioHog, SIGNAL(toggled(bool)), this, SLOT(toggleHog(bool)));
    connect(ui->checkEdge, SIGNAL(toggled(bool)), this, SLOT(toggleEdge(bool)));
    connect(ui->checkEdgeInvert, SIGNAL(toggled(bool)), this, SLOT(toggleEdgeInvert(bool)));
    connect(ui->slideThresh, SIGNAL(valueChanged(int)), this, SLOT(setThresh(int)));
    connect(ui->txtThresh, SIGNAL(textChanged(QString)), this, SLOT(setThresh(QString)));
    connect(ui->checkFlip, SIGNAL(toggled(bool)), this, SLOT(toggleFlip(bool)));
    connect(ui->checkFlipHor, SIGNAL(toggled(bool)), this, SLOT(toggleFlipHor(bool)));
    connect(ui->checkFlipVer, SIGNAL(toggled(bool)), this, SLOT(toggleFlipVer(bool)));

}

void MainWindow::loadFile(){

    this->curFrame = 0;
    const QString path = QFileDialog::getOpenFileName(this, "Select files", "", "Video Files (*.avi)");
    if(!path.isEmpty()){

        //Check if the thread already run
        QMutex mutex;
        mutex.lock();
        if(this->hasVideo){
            //this->mThread->stop = true;
            this->mThread->destroy();
            //delete this->mThread;
//            disconnect(this->mThread, SIGNAL(currentFrame(int,Mat)), this, SLOT(displayResult(int,Mat)));
//            disconnect(ui->radioSurf, SIGNAL(toggled(bool)), this, SLOT(toggleSurf(bool)));
//            disconnect(ui->radioHog, SIGNAL(toggled(bool)), this, SLOT(toggleHog(bool)));
//            QThreadPool::globalInstance()->~QObject();
            delete this->mThread;
            //delete this->capture;
            this->mThread = 0;
            //this->capture = 0;
        }
        mutex.unlock();


        this->capture = new cv::VideoCapture(path.toStdString());
        this->mThread = new processThread(this, this->capture, "");

        //Connect all the effect button
        this->initEffectAndGui();

        this->totalFrame = (int)this->capture->get(CV_CAP_PROP_FRAME_COUNT);
        ui->slideTimeline->setMaximum(this->totalFrame);
     //   this->_timer->start(this->settings->getVideoFrame());
        ui->btnPlayPause->setIcon(QIcon(":/images/pause"));

        this->setInitialProp();
        //this->mThread->start();

        this->hasVideo = true;
        //mThread->stop = false;

        QThreadPool::globalInstance()->start(new MyTask(this->mThread));
    }
}

void MainWindow::setInitialProp(){
    //Check Human Detection
    if(ui->checkHuman->isChecked() && ui->radioSurf->isChecked()){
        //effect->SurfD(img);
        this->mThread->surf = true;
    } else if(ui->checkHuman->isChecked() && ui->radioHog->isChecked()){
       // effect->HogD(img);
        this->mThread->hog = true;
    }

    //Check Edge Detection state
    if(ui->checkEdge->isChecked() && ui->checkEdgeInvert->isChecked()){
        //effect->Edge(img, img, ui->slideThresh->value(), true);
        this->mThread->edge = true; this->mThread->edgeInvert = true; this->mThread->edgeThresh = ui->slideThresh->value();
    } else if(ui->checkEdge->isChecked()){
        //effect->Edge(img, img, ui->slideThresh->value(), false);
        this->mThread->edge = true; this->mThread->edgeInvert = true;
    }

    //Check Flip state
    if(ui->checkFlip->isChecked() && ui->checkFlipHor->isChecked() && ui->checkFlipVer->isChecked()){
        //effect->Flip(img, img, -1); //Both
        this->mThread->flip = true; this->mThread->flipCode = -1;
    } else if(ui->checkFlip->isChecked() && ui->checkFlipVer->isChecked()){
        //effect->Flip(img, img, 0); //Ver
        this->mThread->flip = true; this->mThread->flipCode = 0;
    } else if(ui->checkFlip->isChecked()  && ui->checkFlipHor->isChecked()){
        //effect->Flip(img, img, 1); //Hor
        this->mThread->flip = true; this->mThread->flipCode = 1;
    }

    this->mThread->fps = this->settings->getVideoFrame();

}

void MainWindow::displayResult(int cur, Mat img)
{
    ui->labelDisplay->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols, img.rows, img.step, QImage::Format_RGB888)).scaled(ui->labelDisplay->size(), Qt::KeepAspectRatio));
    ui->slideTimeline->setValue(cur);
    ui->labelTimeline->setText(QString::number(cur) + "/" + QString::number(this->totalFrame) + "\n" + QString::number(cur / 30) + "/" + QString::number((int)this->totalFrame/30));
}


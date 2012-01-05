#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QValidator>
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QDialog>
#include <QThreadPool>
#include <QProcess>
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
    ui->btnPlayPause->setEnabled(false); //Disable on load. no video
    ui->actionCapture_all_frames->setEnabled(false); //Disable on load. no video
    ui->actionCapture_current_frame->setEnabled(false); //Disable on load. no video
    ui->btnSnap->setEnabled(false); //Disable on load. no video
    ui->btnSnapAllFrame->setEnabled(false);

    toggleDetectHuman(ui->checkHuman->isChecked());
    toggleEdge(ui->checkEdge->isChecked());
    toggleFlip(ui->checkFlip->isChecked());

    //Check the effect setting
    this->exports = new Exports(this);
    this->settings = Settings::getInstance(this);
    this->aboutUs = new About(this);
    aboutUs->setFixedSize(490, 360);


    //Connect all the element
    connect(ui->checkHuman, SIGNAL(toggled(bool)), this, SLOT(toggleDetectHuman(bool)));
    connect(ui->btnSnap, SIGNAL(clicked()), this, SLOT(toggleCaptureFrame()));
    connect(ui->btnPlayPause, SIGNAL(clicked()), this, SLOT(togglePlayPause()));
    connect(ui->btnBrowse, SIGNAL(clicked()), this, SLOT(loadFile()));
    connect(ui->btnSnapAllFrame, SIGNAL(clicked()), this, SLOT(toggleCaptureFrames()));
    connect(ui->btnExport, SIGNAL(clicked()), exports, SLOT(open()));

    //set of action
    connect(ui->actionCapture_current_frame, SIGNAL(triggered()), this, SLOT(toggleCaptureFrame()));
    connect(ui->actionOpen_File, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExports, SIGNAL(triggered()), exports, SLOT(open()));
    connect(ui->actionGlobal_Settings, SIGNAL(triggered()), settings, SLOT(open()));
    connect(ui->actionAbout_Us, SIGNAL(triggered()), aboutUs, SLOT(open()));
    connect(ui->actionCapture_all_frames, SIGNAL(triggered()), this, SLOT(toggleCaptureFrames()));
    connect(ui->actionExport, SIGNAL(triggered()), this, SLOT(openDirExport()));
    connect(ui->actionSnapshot, SIGNAL(triggered()), this,SLOT(openDirSnap()));

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

    //if the video is finish playing and user press restart
    if (!this->mThread->pause && this->curFrame == this->totalFrame){
        this->curFrame = 1;
        this->capture->set(CV_CAP_PROP_POS_FRAMES,0);
        //this->mThread->setValueJ(0);
        this->mThread->stop = false;
        this->mThread->pauseAt = 1;
        ui->btnPlayPause->setIcon(QIcon(":/images/pause"));
        QThreadPool::globalInstance()->start(new MyTask(this->mThread));
            //if the video is still playing and user press pause
    } else if(!this->mThread->pause){
        this->mThread->pause = true;
        ui->btnPlayPause->setIcon(QIcon(":/images/play"));
        //if the video is at pause condition and user press play
    }  else {
        this->mThread->pause = false;
        ui->btnPlayPause->setIcon(QIcon(":/images/pause"));
        QThreadPool::globalInstance()->start(new MyTask(this->mThread));
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
    if(this->curFrame == this->totalFrame || this->mThread->pause)
        QMessageBox::information(this, "Snapshot", "You can't capture screen when video is pause or stop.", QMessageBox::Ok);
    else
        this->captureFrame = true;
}

void MainWindow::toggleCaptureFrames(){

    //this->curFrame = 1;//baru tambah
    this->capture->set(CV_CAP_PROP_POS_FRAMES, 0);
    this->mThread->setValueJ(0);
    this->mThread->frameToSkip = this->settings->getFrameToSkip();
    this->captureFrames = true;

    QDateTime timestem = QDateTime::currentDateTime();
    this->folderPath = this->settings->getSnapPath() + "/" + (timestem.toString("yy-MM-dd hh-mm-ss"));

    QDir dir(this->folderPath);

    if(!dir.exists(this->folderPath)){
        dir.mkdir(this->folderPath);
    }

    this->dialogSnaps = new dialogSnapFrames(this, this->totalFrame - (this->totalFrame % this->settings->getFrameToSkip()));
    this->dialogSnaps->setFixedWidth(300);
    this->dialogSnaps->open();

    //if user press capture frame when the video is pause or finish playing
    if(this->mThread->pause || (!this->mThread->pause && this->curFrame == this->totalFrame)){
        ui->btnPlayPause->setIcon(QIcon(":/images/pause"));
        this->mThread->pause = false;
        this->mThread->stop = false;
        QThreadPool::globalInstance()->start(new MyTask(this->mThread));
    }

}

void MainWindow::setThresh(int val){
    ui->txtThresh->setText(QString::number(val));
    mThread->edgeThresh = val;
}

void MainWindow::setThresh(QString val){
    ui->slideThresh->setValue(val.toInt());
    mThread->edgeThresh = val.toInt();
}

void MainWindow::saveToFolder(Mat &img){
    this->captureFrame = false;
    QDateTime timestem = QDateTime::currentDateTime();
    string path = this->settings->getSnapPath().toStdString() + "/" + (timestem.toString("yy-MM-dd hh-mm-ss")).toStdString() + ".jpg";
    cv::imwrite(path, img);
    QMessageBox msgBox;
    msgBox.setText("The frame has been saved.");
    msgBox.setWindowTitle("Information");
    msgBox.exec();
}

void MainWindow::snapAllFrames(Mat &img){

    string fileName = this->folderPath.toStdString() + "/" + QString::number(this->curFrame).toStdString() + ".jpg";
    cv::imwrite(fileName, img);

    //to update to the progress dialog
    emit displayCurProgress(this->curFrame, this->totalFrame);
}


//Connect all the effect button and display that want to be send to thread
void MainWindow::initEffectAndGui(){
    //To passing object Mat via signal and slot
    typedef Mat AMAT;
    qRegisterMetaType<AMAT>("Mat");
    qRegisterMetaType<IpVec>("IpVec");

    connect(this->mThread, SIGNAL(currentFrame(int,Mat)), this, SLOT(displayResult(int,Mat)));
    connect(this->mThread, SIGNAL(finishProcess(bool)), this, SLOT(finishProcess(bool)));
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

    const QString path = QFileDialog::getOpenFileName(this, "Select files", "", "Video Files (*.avi)");
    if(!path.isEmpty()){

        //Set the important button enabled back after video has been load
        if(!ui->btnPlayPause->isEnabled())
            ui->btnPlayPause->setEnabled(true);
        if(!ui->actionCapture_all_frames->isEnabled())
            ui->actionCapture_all_frames->setEnabled(true);
        if(!ui->actionCapture_current_frame->isEnabled())
            ui->actionCapture_current_frame->setEnabled(true);
        if(!ui->btnSnap->isEnabled())
            ui->btnSnap->setEnabled(true);
        if(!ui->btnSnapAllFrame->isEnabled())
            ui->btnSnapAllFrame->setEnabled(true);

        //Check if the thread already run
        if(this->hasVideo){
            delete this->mThread;
            delete this->capture;
            this->mThread = 0;
            this->capture = 0;
        }

        this->curFrame = 0;
        this->capture = new cv::VideoCapture(path.toStdString());
        this->mThread = new processThread(this, this->capture, false, 0, "");

        //Connect all the effect button
        this->initEffectAndGui();

        this->totalFrame = (int)this->capture->get(CV_CAP_PROP_FRAME_COUNT);
        ui->slideTimeline->setMaximum(this->totalFrame);
        ui->btnPlayPause->setIcon(QIcon(":/images/pause"));

        this->setInitialProp();

        this->hasVideo = true;

        QThreadPool::globalInstance()->start(new MyTask(this->mThread));
    }
}

void MainWindow::setInitialProp(){
    //Check Human Detection
    if(ui->checkHuman->isChecked() && ui->radioSurf->isChecked()){
        this->mThread->surf = true;
    } else if(ui->checkHuman->isChecked() && ui->radioHog->isChecked()){
        this->mThread->hog = true;
    }

    //Check Edge Detection state
    if(ui->checkEdge->isChecked() && ui->checkEdgeInvert->isChecked()){
        this->mThread->edge = true; this->mThread->edgeInvert = true; this->mThread->edgeThresh = ui->slideThresh->value();
    } else if(ui->checkEdge->isChecked()){
        this->mThread->edge = true; this->mThread->edgeInvert = true;
    }

    //Check Flip state
    if(ui->checkFlip->isChecked() && ui->checkFlipHor->isChecked() && ui->checkFlipVer->isChecked()){
        this->mThread->flip = true; this->mThread->flipCode = -1; //Both
    } else if(ui->checkFlip->isChecked() && ui->checkFlipVer->isChecked()){
        this->mThread->flip = true; this->mThread->flipCode = 0; //Ver
    } else if(ui->checkFlip->isChecked()  && ui->checkFlipHor->isChecked()){
        this->mThread->flip = true; this->mThread->flipCode = 1; //Hor
    }

    this->mThread->fps = this->settings->getVideoFrame();

}

void MainWindow::displayResult(int cur, Mat img)
{
    this->curFrame = cur;

    if(this->captureFrames){
        this->snapAllFrames(img);
    }

    if(this->captureFrame){ this->saveToFolder(img); } //if user snap a frame, save it then play as usual
    ui->labelDisplay->setPixmap(QPixmap::fromImage(QImage(img.data,img.cols, img.rows, img.step, QImage::Format_RGB888)).scaled(ui->labelDisplay->size(), Qt::KeepAspectRatio));
    ui->slideTimeline->setValue(cur);
    ui->labelTimeline->setText(QString::number(cur) + "/" + QString::number(this->totalFrame) + "\n" + QString::number(cur / 30) + "/" + QString::number((int)this->totalFrame/30));

}

//Condition where the video has been finish processing
void MainWindow::finishProcess(bool state)
{
    //force the cur frame to be same with total frame. to enable restart after snap all frame
    this->curFrame = this->totalFrame;
    ui->slideTimeline->setValue(this->curFrame);
    if (state){
        ui->btnPlayPause->setIcon(QIcon(":/images/repeat"));

        if(this->captureFrames){
            dialogSnaps->setCurProgress(this->curFrame, this->totalFrame);
            dialogSnaps->setButtonEnable(true);
            this->captureFrames = false;
        }
    }
}

void MainWindow::openDirExport()
{
    QProcess::startDetached("explorer " + this->settings->getExportPath());
}

void MainWindow::openDirSnap()
{
    QProcess::startDetached("explorer " + this->settings->getSnapPath());
}

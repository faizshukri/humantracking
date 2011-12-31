#include "settings.h"
#include "ui_settings.h"
#include <QIntValidator>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

Settings* Settings::instance = NULL;

Settings* Settings::getInstance(QWidget *parent){
    if(instance == NULL){
        instance = new Settings(parent);
    }
    return instance;
}

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{

    ui->setupUi(this);
    ui->txtVideoFrame->setValidator(new QIntValidator(0, 50 , this));
    ui->txtVideoFrame->setFixedWidth(30);

    ui->txtFrameToSkip->setValidator(new QIntValidator(1, 9999, this));
    ui->txtFrameToSkip->setFixedWidth(40);

    //Set the settings filename

    QSettings env(QSettings::UserScope, "Microsoft", "Windows");
    env.beginGroup("CurrentVersion/Explorer/Shell Folders");
    this->FileName = env.value("Personal").toString() + "/Human Detect and Track/settings.ini";


   // myProgSetting = new Settings(this);
    //Fill the combobox video codec

    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnSave, SIGNAL(clicked(bool)), this, SLOT(saveSetting(bool)));
    connect(ui->btnReset, SIGNAL(clicked()), this, SLOT(resetDefault()));
    connect(ui->btnBrowseSnap, SIGNAL(clicked()), this, SLOT(browseSnap()));
    connect(ui->btnBrowseExport, SIGNAL(clicked()), this, SLOT(browseExport()));

    //Load the application setting file
    if(QFile::exists(this->FileName)){
        initUserSetting();
    } else {
        initDefault();
    }
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::getSnapPath(){
    QSettings settings(this->FileName, QSettings::IniFormat, this);
    return settings.value("snap_path").toString();
}

QString Settings::getExportPath(){
    QSettings settings(this->FileName, QSettings::IniFormat, this);
    return settings.value("export_path").toString();
}


int Settings::getVideoFrame(){
    QSettings settings(this->FileName, QSettings::IniFormat, this);
    return settings.value("video_frame").toInt();
}

int Settings::getFrameToSkip(){
    QSettings settings(this->FileName, QSettings::IniFormat, this);
    return settings.value("frame_to_skip").toInt();
}


void Settings::initDefault(){

    QSettings env(QSettings::UserScope, "Microsoft", "Windows");
    env.beginGroup("CurrentVersion/Explorer/Shell Folders");


    QString orig = env.value("Personal").toString() + "/Human Detect and Track";
    QDir path(orig);
    path = QDir(orig);
    if(!path.exists(orig)){
        path.mkdir(orig);
    }

    QString dir = orig + "/exports";
    ui->txtExport->setText(path.toNativeSeparators(dir));
    path = QDir(dir);
    if(!path.exists(dir)){
        path.mkdir(dir);
    }

    dir = orig + "/snapshots";
    ui->txtSnap->setText(path.toNativeSeparators(dir));
    path = QDir(dir);
    if(!path.exists(dir)){
        path.mkdir(dir);
    }

    ui->txtVideoFrame->setText("30");
    ui->txtFrameToSkip->setText("30");

    this->saveSetting(true);

}

void Settings::initUserSetting(){
    ui->txtExport->setText(this->getExportPath());
    ui->txtSnap->setText(this->getSnapPath());
    ui->txtVideoFrame->setText(QString::number(this->getVideoFrame()));
    ui->txtFrameToSkip->setText(QString::number(this->getFrameToSkip()));
}

void Settings::saveSetting(bool click){

    QDir path(ui->txtExport->text());
    if(!path.exists())
        path.mkdir(ui->txtExport->text());

    path = QDir(ui->txtSnap->text());
    if(!path.exists())
        path.mkdir(ui->txtSnap->text());

    QSettings settings(this->FileName, QSettings::IniFormat, this);

    settings.setValue("video_frame", ui->txtVideoFrame->text().toInt());
    settings.setValue("export_path", ui->txtExport->text());
    settings.setValue("snap_path", ui->txtSnap->text());
    settings.setValue("frame_to_skip", ui->txtFrameToSkip->text().toInt());

    if(!click)
         QMessageBox::information(this, "Information saved", "Your settings have been saved!", QMessageBox::Ok);
}

void Settings::resetDefault(){
    this->initDefault();
    this->saveSetting(true);

    QMessageBox::information(this, "Information saved", "Your settings have been restored to default", QMessageBox::Ok);
}


void Settings::browseExport(){
    QString path = QFileDialog::getExistingDirectory(this, "Select directory", QDir::currentPath());
    if(!path.isEmpty()){
        QDir directory(path);
        directory.toNativeSeparators(path);
        if(directory.exists()){
            ui->txtExport->setText(path);
        }
    }
}


void Settings::browseSnap(){
    QString path = QFileDialog::getExistingDirectory(this, "Select directory", QDir::currentPath());
    if(!path.isEmpty()){
        QDir directory(path);
        directory.toNativeSeparators(path);
        if(directory.exists()){
            ui->txtSnap->setText(path);
        }
    }
}

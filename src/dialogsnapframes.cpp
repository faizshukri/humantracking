#include "dialogsnapframes.h"
#include "ui_dialogsnapframes.h"
#include "settings.h"

dialogSnapFrames::dialogSnapFrames(QWidget *parent, int progMax) :
    QDialog(parent),
    ui(new Ui::dialogSnapFrames)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(progMax);
    ui->btnCancel->setEnabled(false);

    connect(parent, SIGNAL(displayCurProgress(int, int)), this, SLOT(setCurProgress(int, int)));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

dialogSnapFrames::~dialogSnapFrames()
{
    delete ui;
}

void dialogSnapFrames::setCurProgress(int cur, int total){
    ui->progressBar->setValue(cur);
    ui->labelProgress->setText(QString::number(cur) + " processed from " + QString::number(total -  Settings::getInstance(this)->getFrameToSkip() + 1) + " frames.");
}

void dialogSnapFrames::setButtonEnable(bool)
{
    ui->btnCancel->setEnabled(true);
}

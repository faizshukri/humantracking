#include "dialogsnapframes.h"
#include "ui_dialogsnapframes.h"

dialogSnapFrames::dialogSnapFrames(QWidget *parent, int progMax) :
    QDialog(parent),
    ui(new Ui::dialogSnapFrames)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(progMax);

    connect(parent, SIGNAL(displayCurProgress(int, int)), this, SLOT(setCurProgress(int, int)));
}

dialogSnapFrames::~dialogSnapFrames()
{
    delete ui;
}

void dialogSnapFrames::setCurProgress(int cur, int total){
    ui->progressBar->setValue(cur);
    ui->labelProgress->setText(QString::number(cur) + " processed from " + QString::number(total) + " frames.");
}

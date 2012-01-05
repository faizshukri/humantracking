#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->labelPic->setPixmap(QPixmap(":/images/about"));
    connect(ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

About::~About()
{
    delete ui;
}

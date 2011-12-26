#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    connect(ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

About::~About()
{
    delete ui;
}

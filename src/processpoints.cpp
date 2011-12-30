#include "processpoints.h"

processPoints::processPoints(QObject *parent, IpVec point, QString fileName) :
    QObject(parent)
{
//    QString abu = QString::number(this->points.at(2).dx);
    this->points = point;
//    float b = this->points.at(0).x;
    this->myFile = new QFile(fileName); // filename is including the frame no (current frame)
    this->myFile->open(QIODevice::WriteOnly | QIODevice::Text);
    this->out = new QTextStream(this->myFile);

    for(int i = 0; i < this->points.size(); i++){
        this->out->operator <<(QString::number((double)this->points.at(i).dx) + "," + QString::number((double)this->points.at(i).dy) + "," +
                               QString::number((double)this->points.at(i).laplacian) + "," + QString::number((double)this->points.at(i).orientation) + "," + QString::number((double)this->points.at(i).scale) + "," +
                               QString::number((double)this->points.at(i).x) + "," + QString::number((double)this->points.at(i).y) +
                               "\n");
    }
    this->myFile->close();
}

processPoints::~processPoints(){
    delete this->myFile;
    delete this->out;
    this->myFile = 0;
    this->out = 0;
}

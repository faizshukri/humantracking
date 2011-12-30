#include "processpoints.h"

processPoints::processPoints(QObject *parent, IpVec point, QString fileName) :
    QObject(parent)
{
    this->points = point;
    this->myFile = new QFile(fileName); // filename is including the frame no (current frame)
    processSurf();
}

processPoints::processPoints(QObject *parent, vector<Rect> point, QString fileName) :
    QObject(parent)
{
    this->rectHog = point;
    this->myFile = new QFile(fileName); // filename is including the frame no (current frame)
    processHog();
}

void processPoints::processSurf(){
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

void processPoints::processHog(){
    this->myFile->open(QIODevice::WriteOnly | QIODevice::Text);
    this->out = new QTextStream(this->myFile);

    for(int i = 0; i < this->rectHog.size(); i++){
        this->out->operator <<( QString::number(this->rectHog.at(i).height) + "," + QString::number(this->rectHog.at(i).width) + "," +
                                QString::number(this->rectHog.at(i).x) + "," + QString::number(this->rectHog.at(i).y) + "," +
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

#ifndef PROCESSPOINTS_H
#define PROCESSPOINTS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <opencv2/opencv.hpp>
#include "surf/ipoint.h"

class processPoints : public QObject
{
    Q_OBJECT
public:
     // param fileName is including the frame no (current frame)
    explicit processPoints(QObject *parent = 0, IpVec point = 0, QString fileName = "");
    ~processPoints();

signals:

public slots:

private:
    IpVec points;
    QFile *myFile;
    QTextStream *out;

};

#endif // PROCESSPOINTS_H

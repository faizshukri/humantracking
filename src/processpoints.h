#ifndef PROCESSPOINTS_H
#define PROCESSPOINTS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <opencv2/opencv.hpp>
#include "surf/ipoint.h"
using namespace cv;

class processPoints : public QObject
{
    Q_OBJECT
public:
     // param fileName is including the frame no (current frame)
    explicit processPoints(QObject *parent = 0, IpVec point = 0, QString fileName = "");
    explicit processPoints(QObject *parent = 0, vector<Rect> point = 0, QString fileName = "");
    ~processPoints();

signals:

public slots:

private:
    IpVec points;
    vector<Rect> rectHog;
    QFile *myFile;
    QTextStream *out;

    void processSurf();
    void processHog();
};

#endif // PROCESSPOINTS_H

#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QThread>
#include <QRunnable>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "effects.h"
#include "settings.h"
#include "processpoints.h"

class processThread : public QThread
{
    Q_OBJECT
public:
    explicit processThread(QObject *parent = 0, cv::VideoCapture *cap = 0,
                           bool writeVideo = false, bool extractPoint = false, string fileName = "");
    ~processThread();
    void run();
    void destroy();

    bool stop;
   //Flip
    bool flip;
    int flipCode;

    //Edge
    bool edge;
    bool edgeInvert;
    int edgeThresh;

    //Hog
    bool hog;

    //Surf
    bool surf;

    //Other Setting
    string fileName;
    int fps;
    bool pause;
    int pauseAt; //if user pause, where it is
    int cur;
    bool move;
    int frameToSkip;

public slots:
    void setValueJ(int);

private:
    cv::VideoCapture *capture;
    cv::VideoWriter *writer;
    Effects *effect;
    processPoints **points;
    int count; //use to count current frame
    bool isWrite; //is writer needed?
    bool exportPoints; //check if exportsPoint is set. use this at exports.cpp. only when user check extract point

signals:
    void currentFrame(int);
    void currentFrame(int, Mat);
    void finishProcess(bool);
    void numOfExtPointSurf(IpVec);

public slots:
    void showNumOfExtPointSurf(IpVec);

};

class MyTask: public QRunnable{

public:
    MyTask(QThread* abc) : aThread(abc){}
    void run(){
        this->aThread->start();
    }


private:
    QThread *aThread;

};

#endif // PROCESSTHREAD_H

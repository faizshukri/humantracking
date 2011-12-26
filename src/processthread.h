#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QThread>
#include <QRunnable>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "effects.h"

class processThread : public QThread
{
    Q_OBJECT
public:
    explicit processThread(QObject *parent = 0, cv::VideoCapture *cap = 0, string fileName = "");
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
    bool isWrite; //is writer needed?
    void setWriter(bool);
    string fileName;
    int fps;
    bool pause;
    int pauseAt; //if user pause, where it is
    int cur;
    bool move;

public slots:
    void setValueJ(int);

private:
    cv::VideoCapture *capture;
    cv::VideoWriter *writer;
    Effects *effect;

signals:
    void currentFrame(int);
    void currentFrame(int, Mat);

public slots:

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

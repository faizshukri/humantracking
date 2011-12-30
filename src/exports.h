#ifndef EXPORTS_H
#define EXPORTS_H

#include <QDialog>
//#include <QTimer>
#include <opencv2/opencv.hpp>
#include "settings.h"
#include "effects.h"
#include "processthread.h"

namespace Ui {
    class Exports;
}

class Exports : public QDialog
{
    Q_OBJECT

public:
    explicit Exports(QWidget *parent = 0);
    ~Exports();
    void setupThread(QThread&);

protected slots:
    void browseVideos();
    void showProgressBar(bool);
    void toggleEdge(bool);
    void toggleFlip(bool);
    void toggleHumanDetec(bool);
    void toggleHog(bool);
    void toggleSurf(bool);
    void setThresh(int);
    void setThresh(QString);
    void timerTick();
    void setCurFrame(int);

private:
    Ui::Exports *ui;
    cv::VideoCapture** capture;
    QStringList fileName; //store the video output filename
    cv::VideoWriter* writer;

    Settings *setting;
    Effects* effect;

    processThread **thread;


    int totalProgress; //store total progress frames
    int curFrame; //keep track of current frame for display total progress

    void reBrowse();
    void setInitialProp(processThread *);

    int count; //store number of videos

};

#endif // EXPORTS_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QTimer>
#include <QImage>
#include <QDateTime>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "effects.h"
#include "exports.h"
#include "settings.h"
#include "about.h"
#include "dialogsnapframes.h"
#include "processthread.h"

namespace Ui {
    class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void toggleFlip(bool);
    void toggleFlipHor(bool);
    void toggleFlipVer(bool);
    void toggleDetectHuman(bool);
    void toggleEdge(bool);
    void toggleEdgeInvert(bool);
    void togglePlayPause();
    void setThresh(int);
    void setThresh(QString);
    void setTimeline(int);
    void toggleCaptureFrame();
    void toggleCaptureFrames();

    void toggleSurf(bool);
    void toggleHog(bool);

    void loadFile();

    void displayResult(int, Mat img);
    void initEffectAndGui(); //this is the button connect that must be set after thread be set


   // void setTimeline(int);

signals:
    void displayCurProgress(int, int);
    void setCurPos(int);


private:
    Ui::MainWindow *ui;
 //   QTimer *_timer;
    cv::VideoCapture *capture;

    Effects *effect;
    Exports *exports;
    About *aboutUs;
    Settings *settings;
    dialogSnapFrames *dialogSnaps;
    processThread *mThread;

    int curFrame; //keep track of the current frame
    int totalFrame;
    bool captureFrame; //if the button capture trigger
    bool captureFrames; //if the button capture all trigger
  //  bool play; // state for play or pause
    void saveToFolder(Mat &img);
    void snapAllFrames(Mat &img);
    void setInitialProp();
    bool hasVideo;


    QString folderPath; //folder for snap all frames
};



#endif // MAINWINDOW_H

#ifndef EFFECTS_H
#define EFFECTS_H

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "surf/surflib.h"
//#include "surf/kmeans.h"
#include <QObject>
using namespace cv;

class Effects : public QObject
{
    Q_OBJECT
public:
    explicit Effects(QObject *parent = 0);
    ~Effects();
    void Flip(cv::Mat &img, cv::Mat &out, int code);
    void Edge(cv::Mat &img, cv::Mat &out, int thresh, bool invert);
    void SurfD(cv::Mat &img);
    void HogD(cv::Mat &img);

    //bool savePoint; //Save the points. 0 for Surf, 1 for Hog

signals:
    void vectorOfExtractPoint(IpVec);
    void vectorOfExtractPoint(vector <Rect>);

public slots:

};

#endif // EFFECTS_H

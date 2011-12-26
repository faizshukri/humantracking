#ifndef EFFECTS_H
#define EFFECTS_H

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

class Effects
{

public:
    Effects();
    void Flip(cv::Mat &img, cv::Mat &out, int code);
    void Edge(cv::Mat &img, cv::Mat &out, int thresh, bool invert);
    void SurfD(cv::Mat &img);
    void HogD(cv::Mat &img);

};

#endif // EFFECTS_H

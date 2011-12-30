#include "effects.h"

Effects::Effects(QObject *parent) :
    QObject(parent),
    savePoint(-1)
{
}

Effects::~Effects(){

}

void Effects::Flip(cv::Mat &img, cv::Mat &out, int code){
    cv::flip(img,out,code);
}

void Effects::Edge(cv::Mat &img, cv::Mat &out, int thresh, bool invert = true){
    cv::cvtColor(img,out,CV_BGR2GRAY);
    cv::Canny(out, out, (double)thresh, (double)3*thresh);
    if(invert)
        cv::threshold(out, out, 128, 256, CV_THRESH_BINARY_INV);
    else
        cv::threshold(out, out, 128, 256, CV_THRESH_BINARY);
    cv::cvtColor(out,out,CV_GRAY2BGR);
}

void Effects::SurfD(cv::Mat &img){
    // SurfFeatureDetector abu;

     IpVec ipts;
     IplImage img2=img;

     // Extract surf points
     surfDetDes(&img2, ipts, false, 4, 4, 2, 0.004f);

     // Draw the detected points
     drawIpoints(&img2, ipts);

     img = cv::Mat(&img2);

     //emit numOfExtPointSurf(ipts);
     emit vectorOfExtractPoint(ipts);
}

void Effects::HogD(Mat &img){
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    vector<Rect> found, found_filtered;
    hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);

    size_t i, j;

    Rect r;
    for(i =0; i < found.size(); i++){

        r = found[i];
        for(j = 0; j < found.size(); j++){
            if(j!=i && (r & found[j]) == r)
                   break;
        }

        if(j == found.size()){
            found_filtered.push_back(r);
        }
    }

    for (i=0; i<found_filtered.size(); i++){
          r = found_filtered[i];
          r.x += cvRound(r.width*0.1);
               r.width = cvRound(r.width*0.8);
               r.y += cvRound(r.height*0.07);
               r.height = cvRound(r.height*0.8);
               rectangle(img, r.tl(), r.br(), Scalar(0,255,0), 2);
    }

    emit vectorOfExtractPoint(found);
}

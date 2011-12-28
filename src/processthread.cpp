#include "processthread.h"

processThread::processThread(QObject *parent, cv::VideoCapture *cap, string fileName) :
    QThread(parent),
    flip(false),
    flipCode(0),
    edge(false),
    edgeInvert(false),
    edgeThresh(0),
    hog(false),
    surf(false),
    writer(0),
    isWrite(false),
    fps(0),
    stop(false),
    pause(false),
    pauseAt(1),
    move(false),
    cur(0),
    frameToSkip(0)
{
    this->effect = new Effects();
    this->capture = cap;
    this->fileName = fileName;

    connect(parent, SIGNAL(setCurPos(int)), this, SLOT(setValueJ(int)));
}

void processThread::setWriter(bool state){
    if(state){
        this->isWrite = true;
        Mat img;
        this->capture->operator >>( img );
        if(img.data)
        this->writer = new cv::VideoWriter(this->fileName, CV_FOURCC('D','I','V','X'),this->capture->get(CV_CAP_PROP_FPS),img.size(),true);
    }
}

void processThread::run(){

    Mat img;

        for(int j = pauseAt; j <= this->capture->get(CV_CAP_PROP_FRAME_COUNT); j++){

            if(this->stop)
                break;

            if(this->pause){
                this->pauseAt = j;
                break;
            }

            if(move){
                move = false;
                j = cur;
                this->capture->set(CV_CAP_PROP_POS_FRAMES, j);
            }

            emit currentFrame(j);
            this->capture->operator >>( img );

            if(img.data){

                //============ START Effect ============//


                    //Check Human Detect state
                    if(this->surf){
                        effect->SurfD(img);
                    } else if(this->hog){
                        effect->HogD(img);
                    }

                    //Check Edge Detection state
                    if(this->edge){
                        effect->Edge(img, img, edgeThresh, edgeInvert);
                    }

                    //Check Flip state
                    if(this->flip){
                        effect->Flip(img,img,flipCode);
                    }

                //============ END Effect ============//

                if(isWrite){ //if writer needed
                    writer->operator <<( img );
                } else { //prevent emit if writer is on
                    emit currentFrame(j, img);
                    msleep((unsigned long)Settings::getInstance(0)->getVideoFrame());
                }

                for(int i = 0; i < frameToSkip - 1; i++){
                    this->capture->operator >>( img );
                    j++;
                    if(!img.data){ stop = true; break; }
                }

            }
        }
        if(!this->pause)
            this->stop = true;

        this->frameToSkip = 0; //reset back frame to skip to 0

        if(isWrite) //if writer needed
            this->writer->~VideoWriter();

}

void processThread::destroy()
{
    this->stop = true;
    this->terminate();
}

void processThread::setValueJ(int val){
    move = true;
    this->cur = val;
}

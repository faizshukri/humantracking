#include "processthread.h"
#include <QDir>

processThread::processThread(QObject *parent, cv::VideoCapture *cap, bool writeVideo, bool extractPoint, string fileName) :
    QThread(parent),
    flip(false),
    flipCode(0),
    edge(false),
    edgeInvert(false),
    edgeThresh(0),
    hog(false),
    surf(false),
    writer(0),
    isWrite(writeVideo),
    fps(0),
    stop(false),
    pause(false),
    pauseAt(1),
    move(false),
    cur(0),
    frameToSkip(0),
    count(0),
    exportPoints(extractPoint),
    fileName(fileName)
{
    this->effect = new Effects(this);
    this->capture = cap;

    //If the user check the export point, then initialize the object points
    if(this->exportPoints){
        int totalFrame = this->capture->get(CV_CAP_PROP_FRAME_COUNT);
        this->points = new processPoints*[totalFrame];
    }

    //If the user check the need the video writer, then initialize the object writer
    if(this->isWrite){
        Mat img;
        this->capture->operator >>( img );
        if(img.data){
            this->writer = new cv::VideoWriter(this->fileName, CV_FOURCC('D','I','V','X'),this->capture->get(CV_CAP_PROP_FPS),img.size(),true);
        }
    }


    qRegisterMetaType<IpVec>("IpVec");

    connect(parent, SIGNAL(setCurPos(int)), this, SLOT(setValueJ(int)));
    connect(this->effect, SIGNAL(numOfExtPointSurf(IpVec)), this, SLOT(showNumOfExtPointSurf(IpVec)));
}

//Destructor
processThread::~processThread(){
    if(isWrite){
        delete writer;
        writer = 0;
    }

    if(exportPoints){
        for(int i = 0; i < this->capture->get(CV_CAP_PROP_FRAME_COUNT); i++){
            delete [] points[i];
            points[i] = 0;
        }
        delete [] points;
        points = 0;
    }
    this->capture->release();
    this->destroy();
}


void processThread::run(){

    Mat img;
    int totalFrame = this->capture->get(CV_CAP_PROP_FRAME_COUNT);

        for(int j = pauseAt; j <= totalFrame; j++){

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
                        //if(this->savePoint) effect->savePoint = 0;
                    } else if(this->hog){
                        effect->HogD(img);
                        //if(this->savePoint) effect->savePoint = 1;
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

            } else { break; }
        }

        if(!this->pause)
            this->stop = true;

        this->frameToSkip = 0; //reset back frame to skip to 0

        if(isWrite){ //if writer needed
            this->writer->~VideoWriter();
        }

        emit finishProcess(true);

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

void processThread::showNumOfExtPointSurf(IpVec val)
{
    QString extractPointDir = QString::fromStdString(this->fileName) + "_POINTS\\";
    QDir path(extractPointDir);
    if(!path.exists(extractPointDir)){
        path.mkdir(extractPointDir);
    }

    if(this->exportPoints){
        this->points[this->count] = new processPoints(this, val, extractPointDir + QString::number(this->count) + ".txt");
    }
    ++count;
}

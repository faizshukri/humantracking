#-------------------------------------------------
#
# Project created by QtCreator 2011-12-12T21:20:22
#
#-------------------------------------------------

QT       += core gui

TARGET = FYP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    effects.cpp \
    surf/utils.cpp \
    surf/surf.cpp \
    surf/ipoint.cpp \
    surf/integral.cpp \
    surf/fasthessian.cpp \
    exports.cpp \
    settings.cpp \
    about.cpp \
    dialogsnapframes.cpp \
    processthread.cpp

HEADERS  += mainwindow.h \
    effects.h \
    surf/utils.h \
    surf/surflib.h \
    surf/surf.h \
    surf/responselayer.h \
    surf/kmeans.h \
    surf/ipoint.h \
    surf/integral.h \
    surf/fasthessian.h \
    exports.h \
    settings.h \
    about.h \
    dialogsnapframes.h \
    processthread.h

FORMS    += mainwindow.ui \
    exports.ui \
    settings.ui \
    about.ui \
    dialogsnapframes.ui

INCLUDEPATH += D:\OpenCV2.3MinGW\include\

LIBS += -LD:\OpenCV2.3MinGW\lib \
    -llibopencv_core231 \
    -llibopencv_highgui231 \
    -llibopencv_imgproc231 \
    -llibopencv_features2d231 \
    -llibopencv_calib3d231 \
    -llibopencv_flann231 \
    -llibopencv_video231 \
    -llibopencv_objdetect231 \
    -llibopencv_ml231 \
    -llibopencv_contrib231

#LIBS += -LD:\OpenCV2.3MinGW\lib \
#    -llibopencv_core231d \
#    -llibopencv_highgui231d \
#    -llibopencv_imgproc231d \
#    -llibopencv_features2d231d \
#    -llibopencv_calib3d231d \
#    -llibopencv_flann231d \
#    -llibopencv_video231d \
#    -llibopencv_objdetect231d \
#    -llibopencv_ml231d \
#    -llibopencv_contrib231d

RESOURCES += \
    Resources.qrc






























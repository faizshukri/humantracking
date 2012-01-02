#-------------------------------------------------
#
# Project created by QtCreator 2011-12-12T21:20:22
#
#-------------------------------------------------

QT       += core gui

TARGET = FYP
TEMPLATE = app


SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/effects.cpp \
    src/surf/utils.cpp \
    src/surf/surf.cpp \
    src/surf/ipoint.cpp \
    src/surf/integral.cpp \
    src/surf/fasthessian.cpp \
    src/exports.cpp \
    src/settings.cpp \
    src/about.cpp \
    src/dialogsnapframes.cpp \
    src/processthread.cpp \
    src/processpoints.cpp

HEADERS  += src/mainwindow.h \
    src/effects.h \
    src/surf/utils.h \
    src/surf/surflib.h \
    src/surf/surf.h \
    src/surf/responselayer.h \
    src/surf/kmeans.h \
    src/surf/ipoint.h \
    src/surf/integral.h \
    src/surf/fasthessian.h \
    src/exports.h \
    src/settings.h \
    src/about.h \
    src/dialogsnapframes.h \
    src/processthread.h \
    src/processpoints.h

FORMS    += forms/mainwindow.ui \
    forms/exports.ui \
    forms/settings.ui \
    forms/about.ui \
    forms/dialogsnapframes.ui

INCLUDEPATH += D:\OpenCV2.3MinGW\include\

LIBS += -LD:\OpenCV2.3MinGW\lib \
    -llibopencv_core231 \
    -llibopencv_highgui231 \
    -llibopencv_imgproc231 \
    -llibopencv_calib3d231 \
    -llibopencv_objdetect231 \
    -llibopencv_flann231d \
    -llibopencv_features2d231d

#LIBS += -LD:\OpenCV2.3MinGW\lib \
#    -llibopencv_core231d \
#    -llibopencv_highgui231d \
#    -llibopencv_imgproc231d \
#    -llibopencv_calib3d231d \
#    -llibopencv_objdetect231d \
#    -llibopencv_flann231d \
#    -llibopencv_features2d231d \
#    -llibopencv_video231d \
#    -llibopencv_ml231d

RESOURCES += \
    Resources.qrc

RC_FILE = myapp.rc


































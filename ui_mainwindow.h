/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Dec 26 00:13:42 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExports;
    QAction *actionExit;
    QAction *actionGlobal_Settings;
    QAction *actionOpen_File;
    QAction *actionAbout_Us;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionCapture_current_frame;
    QAction *actionCapture_all_frames;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btnBrowse;
    QPushButton *btnSnap;
    QFrame *line;
    QLabel *label_2;
    QFrame *line_2;
    QCheckBox *checkFlip;
    QGroupBox *groupFlip;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkFlipHor;
    QCheckBox *checkFlipVer;
    QCheckBox *checkEdge;
    QGroupBox *groupThresh;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSlider *slideThresh;
    QLineEdit *txtThresh;
    QCheckBox *checkEdgeInvert;
    QCheckBox *checkHuman;
    QGroupBox *groupAlgorithm;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioHog;
    QRadioButton *radioSurf;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelDisplay;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnPlayPause;
    QSlider *slideTimeline;
    QLabel *labelTimeline;
    QMenuBar *menuBar;
    QMenu *menuFiles;
    QMenu *menuSetting;
    QMenu *menuHelp;
    QMenu *menuVideos;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(824, 477);
        actionExports = new QAction(MainWindow);
        actionExports->setObjectName(QString::fromUtf8("actionExports"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionGlobal_Settings = new QAction(MainWindow);
        actionGlobal_Settings->setObjectName(QString::fromUtf8("actionGlobal_Settings"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionAbout_Us = new QAction(MainWindow);
        actionAbout_Us->setObjectName(QString::fromUtf8("actionAbout_Us"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionCapture_current_frame = new QAction(MainWindow);
        actionCapture_current_frame->setObjectName(QString::fromUtf8("actionCapture_current_frame"));
        actionCapture_all_frames = new QAction(MainWindow);
        actionCapture_all_frames->setObjectName(QString::fromUtf8("actionCapture_all_frames"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnBrowse = new QPushButton(centralWidget);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));

        verticalLayout->addWidget(btnBrowse);

        btnSnap = new QPushButton(centralWidget);
        btnSnap->setObjectName(QString::fromUtf8("btnSnap"));

        verticalLayout->addWidget(btnSnap);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        checkFlip = new QCheckBox(centralWidget);
        checkFlip->setObjectName(QString::fromUtf8("checkFlip"));

        verticalLayout->addWidget(checkFlip);

        groupFlip = new QGroupBox(centralWidget);
        groupFlip->setObjectName(QString::fromUtf8("groupFlip"));
        verticalLayout_5 = new QVBoxLayout(groupFlip);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        checkFlipHor = new QCheckBox(groupFlip);
        checkFlipHor->setObjectName(QString::fromUtf8("checkFlipHor"));

        verticalLayout_5->addWidget(checkFlipHor);

        checkFlipVer = new QCheckBox(groupFlip);
        checkFlipVer->setObjectName(QString::fromUtf8("checkFlipVer"));

        verticalLayout_5->addWidget(checkFlipVer);


        verticalLayout->addWidget(groupFlip);

        checkEdge = new QCheckBox(centralWidget);
        checkEdge->setObjectName(QString::fromUtf8("checkEdge"));

        verticalLayout->addWidget(checkEdge);

        groupThresh = new QGroupBox(centralWidget);
        groupThresh->setObjectName(QString::fromUtf8("groupThresh"));
        verticalLayout_3 = new QVBoxLayout(groupThresh);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        slideThresh = new QSlider(groupThresh);
        slideThresh->setObjectName(QString::fromUtf8("slideThresh"));
        slideThresh->setMaximum(100);
        slideThresh->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(slideThresh);

        txtThresh = new QLineEdit(groupThresh);
        txtThresh->setObjectName(QString::fromUtf8("txtThresh"));
        txtThresh->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(txtThresh);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        checkEdgeInvert = new QCheckBox(groupThresh);
        checkEdgeInvert->setObjectName(QString::fromUtf8("checkEdgeInvert"));

        verticalLayout_3->addWidget(checkEdgeInvert);


        verticalLayout->addWidget(groupThresh);

        checkHuman = new QCheckBox(centralWidget);
        checkHuman->setObjectName(QString::fromUtf8("checkHuman"));

        verticalLayout->addWidget(checkHuman);

        groupAlgorithm = new QGroupBox(centralWidget);
        groupAlgorithm->setObjectName(QString::fromUtf8("groupAlgorithm"));
        verticalLayout_4 = new QVBoxLayout(groupAlgorithm);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioHog = new QRadioButton(groupAlgorithm);
        radioHog->setObjectName(QString::fromUtf8("radioHog"));

        verticalLayout_4->addWidget(radioHog);

        radioSurf = new QRadioButton(groupAlgorithm);
        radioSurf->setObjectName(QString::fromUtf8("radioSurf"));

        verticalLayout_4->addWidget(radioSurf);


        verticalLayout->addWidget(groupAlgorithm);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelDisplay = new QLabel(centralWidget);
        labelDisplay->setObjectName(QString::fromUtf8("labelDisplay"));

        verticalLayout_2->addWidget(labelDisplay);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnPlayPause = new QPushButton(centralWidget);
        btnPlayPause->setObjectName(QString::fromUtf8("btnPlayPause"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/Play-Disabled-icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlayPause->setIcon(icon);

        horizontalLayout_2->addWidget(btnPlayPause);

        slideTimeline = new QSlider(centralWidget);
        slideTimeline->setObjectName(QString::fromUtf8("slideTimeline"));
        slideTimeline->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(slideTimeline);

        labelTimeline = new QLabel(centralWidget);
        labelTimeline->setObjectName(QString::fromUtf8("labelTimeline"));

        horizontalLayout_2->addWidget(labelTimeline);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 10);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 824, 21));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuVideos = new QMenu(menuBar);
        menuVideos->setObjectName(QString::fromUtf8("menuVideos"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuSetting->menuAction());
        menuBar->addAction(menuVideos->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFiles->addAction(actionOpen_File);
        menuFiles->addAction(actionExports);
        menuFiles->addSeparator();
        menuFiles->addAction(actionExit);
        menuSetting->addAction(actionGlobal_Settings);
        menuHelp->addAction(actionAbout_Us);
        menuVideos->addAction(actionPlay);
        menuVideos->addAction(actionPause);
        menuVideos->addAction(actionStop);
        menuVideos->addSeparator();
        menuVideos->addAction(actionCapture_current_frame);
        menuVideos->addAction(actionCapture_all_frames);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExports->setText(QApplication::translate("MainWindow", "Exports", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionGlobal_Settings->setText(QApplication::translate("MainWindow", "Global Settings", 0, QApplication::UnicodeUTF8));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", 0, QApplication::UnicodeUTF8));
        actionOpen_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionAbout_Us->setText(QApplication::translate("MainWindow", "About Us", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        actionCapture_current_frame->setText(QApplication::translate("MainWindow", "Capture current frame", 0, QApplication::UnicodeUTF8));
        actionCapture_all_frames->setText(QApplication::translate("MainWindow", "Capture all frames", 0, QApplication::UnicodeUTF8));
        btnBrowse->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        btnSnap->setText(QApplication::translate("MainWindow", "Snapshot", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Properties", 0, QApplication::UnicodeUTF8));
        checkFlip->setText(QApplication::translate("MainWindow", "Flip", 0, QApplication::UnicodeUTF8));
        groupFlip->setTitle(QApplication::translate("MainWindow", "Properties", 0, QApplication::UnicodeUTF8));
        checkFlipHor->setText(QApplication::translate("MainWindow", "Horizontal", 0, QApplication::UnicodeUTF8));
        checkFlipVer->setText(QApplication::translate("MainWindow", "Vertical", 0, QApplication::UnicodeUTF8));
        checkEdge->setText(QApplication::translate("MainWindow", "Edge Detector", 0, QApplication::UnicodeUTF8));
        groupThresh->setTitle(QApplication::translate("MainWindow", "Threshold", 0, QApplication::UnicodeUTF8));
        txtThresh->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        checkEdgeInvert->setText(QApplication::translate("MainWindow", "Invert", 0, QApplication::UnicodeUTF8));
        checkHuman->setText(QApplication::translate("MainWindow", "Human Detect", 0, QApplication::UnicodeUTF8));
        groupAlgorithm->setTitle(QApplication::translate("MainWindow", "Algorithm", 0, QApplication::UnicodeUTF8));
        radioHog->setText(QApplication::translate("MainWindow", "HOG Descriptor", 0, QApplication::UnicodeUTF8));
        radioSurf->setText(QApplication::translate("MainWindow", "SURF Descriptor", 0, QApplication::UnicodeUTF8));
        labelDisplay->setText(QString());
        btnPlayPause->setText(QString());
        labelTimeline->setText(QApplication::translate("MainWindow", "label", 0, QApplication::UnicodeUTF8));
        menuFiles->setTitle(QApplication::translate("MainWindow", "Files", 0, QApplication::UnicodeUTF8));
        menuSetting->setTitle(QApplication::translate("MainWindow", "Setting", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuVideos->setTitle(QApplication::translate("MainWindow", "Videos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

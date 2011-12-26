/********************************************************************************
** Form generated from reading UI file 'exports.ui'
**
** Created: Mon Dec 26 00:13:42 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTS_H
#define UI_EXPORTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Exports
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listVideos;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnBrowse;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;
    QCheckBox *checkFlip;
    QGroupBox *groupFlip;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkFlipHor;
    QCheckBox *checkFlipVer;
    QCheckBox *checkEdge;
    QGroupBox *groupEdge;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QSlider *slideThresh;
    QLineEdit *txtThresh;
    QCheckBox *checkEdgeInvert;
    QCheckBox *checkHuman;
    QGroupBox *groupHumanDetect;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioHog;
    QRadioButton *radioSurf;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblTotalProgress;
    QProgressBar *progressBarTotal;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExport;
    QPushButton *btnCancel;

    void setupUi(QDialog *Exports)
    {
        if (Exports->objectName().isEmpty())
            Exports->setObjectName(QString::fromUtf8("Exports"));
        Exports->resize(536, 430);
        verticalLayout = new QVBoxLayout(Exports);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listVideos = new QListWidget(Exports);
        listVideos->setObjectName(QString::fromUtf8("listVideos"));

        horizontalLayout->addWidget(listVideos);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnBrowse = new QPushButton(Exports);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));

        verticalLayout_2->addWidget(btnBrowse);

        line = new QFrame(Exports);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label = new QLabel(Exports);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        line_2 = new QFrame(Exports);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        checkFlip = new QCheckBox(Exports);
        checkFlip->setObjectName(QString::fromUtf8("checkFlip"));

        verticalLayout_2->addWidget(checkFlip);

        groupFlip = new QGroupBox(Exports);
        groupFlip->setObjectName(QString::fromUtf8("groupFlip"));
        verticalLayout_6 = new QVBoxLayout(groupFlip);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        checkFlipHor = new QCheckBox(groupFlip);
        checkFlipHor->setObjectName(QString::fromUtf8("checkFlipHor"));

        verticalLayout_6->addWidget(checkFlipHor);

        checkFlipVer = new QCheckBox(groupFlip);
        checkFlipVer->setObjectName(QString::fromUtf8("checkFlipVer"));

        verticalLayout_6->addWidget(checkFlipVer);


        verticalLayout_2->addWidget(groupFlip);

        checkEdge = new QCheckBox(Exports);
        checkEdge->setObjectName(QString::fromUtf8("checkEdge"));

        verticalLayout_2->addWidget(checkEdge);

        groupEdge = new QGroupBox(Exports);
        groupEdge->setObjectName(QString::fromUtf8("groupEdge"));
        verticalLayout_5 = new QVBoxLayout(groupEdge);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        slideThresh = new QSlider(groupEdge);
        slideThresh->setObjectName(QString::fromUtf8("slideThresh"));
        slideThresh->setMaximum(100);
        slideThresh->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(slideThresh);

        txtThresh = new QLineEdit(groupEdge);
        txtThresh->setObjectName(QString::fromUtf8("txtThresh"));
        txtThresh->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(txtThresh);

        horizontalLayout_5->setStretch(0, 1);

        verticalLayout_5->addLayout(horizontalLayout_5);

        checkEdgeInvert = new QCheckBox(groupEdge);
        checkEdgeInvert->setObjectName(QString::fromUtf8("checkEdgeInvert"));

        verticalLayout_5->addWidget(checkEdgeInvert);


        verticalLayout_2->addWidget(groupEdge);

        checkHuman = new QCheckBox(Exports);
        checkHuman->setObjectName(QString::fromUtf8("checkHuman"));

        verticalLayout_2->addWidget(checkHuman);

        groupHumanDetect = new QGroupBox(Exports);
        groupHumanDetect->setObjectName(QString::fromUtf8("groupHumanDetect"));
        verticalLayout_4 = new QVBoxLayout(groupHumanDetect);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioHog = new QRadioButton(groupHumanDetect);
        radioHog->setObjectName(QString::fromUtf8("radioHog"));

        verticalLayout_4->addWidget(radioHog);

        radioSurf = new QRadioButton(groupHumanDetect);
        radioSurf->setObjectName(QString::fromUtf8("radioSurf"));

        verticalLayout_4->addWidget(radioSurf);


        verticalLayout_2->addWidget(groupHumanDetect);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 2);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lblTotalProgress = new QLabel(Exports);
        lblTotalProgress->setObjectName(QString::fromUtf8("lblTotalProgress"));
        lblTotalProgress->setMinimumSize(QSize(90, 0));
        lblTotalProgress->setBaseSize(QSize(0, 0));
        lblTotalProgress->setScaledContents(false);

        horizontalLayout_3->addWidget(lblTotalProgress);

        progressBarTotal = new QProgressBar(Exports);
        progressBarTotal->setObjectName(QString::fromUtf8("progressBarTotal"));
        progressBarTotal->setMinimumSize(QSize(250, 0));
        progressBarTotal->setValue(24);

        horizontalLayout_3->addWidget(progressBarTotal);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnExport = new QPushButton(Exports);
        btnExport->setObjectName(QString::fromUtf8("btnExport"));

        horizontalLayout_2->addWidget(btnExport);

        btnCancel = new QPushButton(Exports);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Exports);

        QMetaObject::connectSlotsByName(Exports);
    } // setupUi

    void retranslateUi(QDialog *Exports)
    {
        Exports->setWindowTitle(QApplication::translate("Exports", "Export Videos", 0, QApplication::UnicodeUTF8));
        btnBrowse->setText(QApplication::translate("Exports", "Browse", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Exports", "Properties", 0, QApplication::UnicodeUTF8));
        checkFlip->setText(QApplication::translate("Exports", "Flip", 0, QApplication::UnicodeUTF8));
        groupFlip->setTitle(QApplication::translate("Exports", "Orientation", 0, QApplication::UnicodeUTF8));
        checkFlipHor->setText(QApplication::translate("Exports", "Horizontal", 0, QApplication::UnicodeUTF8));
        checkFlipVer->setText(QApplication::translate("Exports", "Vertical", 0, QApplication::UnicodeUTF8));
        checkEdge->setText(QApplication::translate("Exports", "Edge Detection", 0, QApplication::UnicodeUTF8));
        groupEdge->setTitle(QApplication::translate("Exports", "Threshold", 0, QApplication::UnicodeUTF8));
        txtThresh->setText(QApplication::translate("Exports", "0", 0, QApplication::UnicodeUTF8));
        checkEdgeInvert->setText(QApplication::translate("Exports", "Invert", 0, QApplication::UnicodeUTF8));
        checkHuman->setText(QApplication::translate("Exports", "Human Detection", 0, QApplication::UnicodeUTF8));
        groupHumanDetect->setTitle(QApplication::translate("Exports", "Algorithm", 0, QApplication::UnicodeUTF8));
        radioHog->setText(QApplication::translate("Exports", "Hog Descriptor", 0, QApplication::UnicodeUTF8));
        radioSurf->setText(QApplication::translate("Exports", "Surf Descriptor", 0, QApplication::UnicodeUTF8));
        lblTotalProgress->setText(QApplication::translate("Exports", "Total Progress", 0, QApplication::UnicodeUTF8));
        btnExport->setText(QApplication::translate("Exports", "Export", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("Exports", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Exports: public Ui_Exports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTS_H

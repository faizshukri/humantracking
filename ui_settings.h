/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Mon Dec 26 00:13:42 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txtSnap;
    QPushButton *btnBrowseSnap;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *txtFrameToSkip;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *txtExport;
    QPushButton *btnBrowseExport;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *txtExtractPoint;
    QPushButton *btnBrowsePoint;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboCodec;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *txtVideoFrame;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QPushButton *btnReset;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(483, 259);
        verticalLayout = new QVBoxLayout(Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(label);

        txtSnap = new QLineEdit(Settings);
        txtSnap->setObjectName(QString::fromUtf8("txtSnap"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtSnap->sizePolicy().hasHeightForWidth());
        txtSnap->setSizePolicy(sizePolicy);
        txtSnap->setMinimumSize(QSize(250, 0));

        horizontalLayout_2->addWidget(txtSnap);

        btnBrowseSnap = new QPushButton(Settings);
        btnBrowseSnap->setObjectName(QString::fromUtf8("btnBrowseSnap"));

        horizontalLayout_2->addWidget(btnBrowseSnap);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(Settings);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(120, 0));

        horizontalLayout_7->addWidget(label_6);

        txtFrameToSkip = new QLineEdit(Settings);
        txtFrameToSkip->setObjectName(QString::fromUtf8("txtFrameToSkip"));
        sizePolicy.setHeightForWidth(txtFrameToSkip->sizePolicy().hasHeightForWidth());
        txtFrameToSkip->setSizePolicy(sizePolicy);
        txtFrameToSkip->setMinimumSize(QSize(20, 0));

        horizontalLayout_7->addWidget(txtFrameToSkip);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 0));

        horizontalLayout_3->addWidget(label_2);

        txtExport = new QLineEdit(Settings);
        txtExport->setObjectName(QString::fromUtf8("txtExport"));
        sizePolicy.setHeightForWidth(txtExport->sizePolicy().hasHeightForWidth());
        txtExport->setSizePolicy(sizePolicy);
        txtExport->setMinimumSize(QSize(250, 0));

        horizontalLayout_3->addWidget(txtExport);

        btnBrowseExport = new QPushButton(Settings);
        btnBrowseExport->setObjectName(QString::fromUtf8("btnBrowseExport"));

        horizontalLayout_3->addWidget(btnBrowseExport);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(Settings);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(120, 0));

        horizontalLayout_6->addWidget(label_5);

        txtExtractPoint = new QLineEdit(Settings);
        txtExtractPoint->setObjectName(QString::fromUtf8("txtExtractPoint"));
        sizePolicy.setHeightForWidth(txtExtractPoint->sizePolicy().hasHeightForWidth());
        txtExtractPoint->setSizePolicy(sizePolicy);
        txtExtractPoint->setMinimumSize(QSize(250, 0));

        horizontalLayout_6->addWidget(txtExtractPoint);

        btnBrowsePoint = new QPushButton(Settings);
        btnBrowsePoint->setObjectName(QString::fromUtf8("btnBrowsePoint"));

        horizontalLayout_6->addWidget(btnBrowsePoint);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(Settings);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 0));

        horizontalLayout_4->addWidget(label_3);

        comboCodec = new QComboBox(Settings);
        comboCodec->setObjectName(QString::fromUtf8("comboCodec"));

        horizontalLayout_4->addWidget(comboCodec);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(Settings);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(120, 0));

        horizontalLayout_5->addWidget(label_4);

        txtVideoFrame = new QLineEdit(Settings);
        txtVideoFrame->setObjectName(QString::fromUtf8("txtVideoFrame"));
        sizePolicy.setHeightForWidth(txtVideoFrame->sizePolicy().hasHeightForWidth());
        txtVideoFrame->setSizePolicy(sizePolicy);
        txtVideoFrame->setMinimumSize(QSize(20, 0));

        horizontalLayout_5->addWidget(txtVideoFrame);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(Settings);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(Settings);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        btnReset = new QPushButton(Settings);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        horizontalLayout->addWidget(btnReset);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Global Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "Snapshot Path", 0, QApplication::UnicodeUTF8));
        btnBrowseSnap->setText(QApplication::translate("Settings", "Browse", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Settings", "Frames To Skip", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Exports Path", 0, QApplication::UnicodeUTF8));
        btnBrowseExport->setText(QApplication::translate("Settings", "Browse", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Settings", "Point Extraction Path", 0, QApplication::UnicodeUTF8));
        btnBrowsePoint->setText(QApplication::translate("Settings", "Browse", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "Video Codec", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Settings", "Video Frame", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("Settings", "Save", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("Settings", "Reset to default", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H

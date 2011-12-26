/********************************************************************************
** Form generated from reading UI file 'dialogsnapframes.ui'
**
** Created: Mon Dec 26 00:13:43 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSNAPFRAMES_H
#define UI_DIALOGSNAPFRAMES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogSnapFrames
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelProgress;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;

    void setupUi(QDialog *dialogSnapFrames)
    {
        if (dialogSnapFrames->objectName().isEmpty())
            dialogSnapFrames->setObjectName(QString::fromUtf8("dialogSnapFrames"));
        dialogSnapFrames->resize(346, 89);
        verticalLayout = new QVBoxLayout(dialogSnapFrames);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        progressBar = new QProgressBar(dialogSnapFrames);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        labelProgress = new QLabel(dialogSnapFrames);
        labelProgress->setObjectName(QString::fromUtf8("labelProgress"));

        horizontalLayout->addWidget(labelProgress);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(dialogSnapFrames);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(dialogSnapFrames);

        QMetaObject::connectSlotsByName(dialogSnapFrames);
    } // setupUi

    void retranslateUi(QDialog *dialogSnapFrames)
    {
        dialogSnapFrames->setWindowTitle(QApplication::translate("dialogSnapFrames", "Dialog", 0, QApplication::UnicodeUTF8));
        labelProgress->setText(QApplication::translate("dialogSnapFrames", "progress", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("dialogSnapFrames", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialogSnapFrames: public Ui_dialogSnapFrames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSNAPFRAMES_H

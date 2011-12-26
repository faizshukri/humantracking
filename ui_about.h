/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Mon Dec 26 00:13:43 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QPushButton *btnClose;
    QLabel *label_2;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(398, 171);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(200);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        About->setSizeGripEnabled(false);
        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 341, 111));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        btnClose = new QPushButton(About);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(310, 140, 75, 23));
        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 150, 231, 16));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About Us", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("About", "HG DnT is a short form for Human Gait Detection and Tracking. It was created for our Final Year Project Multimedia University 2011 / 2012.", 0, QApplication::UnicodeUTF8));
        btnClose->setText(QApplication::translate("About", "Close", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("About", "Created by: Ahmad Faiz | Muhammad Afiq", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H

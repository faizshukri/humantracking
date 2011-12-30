#ifndef DIALOGSNAPFRAMES_H
#define DIALOGSNAPFRAMES_H

#include <QDialog>

namespace Ui {
    class dialogSnapFrames;
}

class dialogSnapFrames : public QDialog
{
    Q_OBJECT

public:
    explicit dialogSnapFrames(QWidget *parent = 0, int progMax = 100);
    ~dialogSnapFrames();
    void setButtonEnable(bool);

public slots:
    void setCurProgress(int, int);


private:
    Ui::dialogSnapFrames *ui;
};

#endif // DIALOGSNAPFRAMES_H

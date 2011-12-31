#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>

namespace Ui {
    class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    ~Settings();
    QString getSnapPath();
    QString getExportPath();
    QString getExtractPointPath();
    int getVideoFrame();
    int getFrameToSkip();
    static Settings *getInstance(QWidget *parent);


protected slots:
    void saveSetting(bool);
    void resetDefault();
    void browseSnap();
    void browseExport();
    void browseExtractPoint();

private:
    //explicit Settings(QWidget *parent = 0); //constructor is private for singleton
    Settings(QWidget *parent);
    Ui::Settings *ui;
    Settings *myProgSetting;
    QString FileName;
    void initUserSetting();
    void initDefault();
    static Settings *instance;
};

#endif // SETTINGS_H

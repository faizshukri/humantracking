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
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    QString getSnapPath();
    QString getExportPath();
    QString getExtractPointPath();
    int getVideoCodec();
    int getVideoFrame();
    int getFrameToSkip();


protected slots:
    void saveSetting(bool);
    void resetDefault();
    void browseSnap();
    void browseExport();
    void browseExtractPoint();

private:
    Ui::Settings *ui;
    Settings *myProgSetting;
    QString FileName;
    void initUserSetting();
    void initDefault();
};

#endif // SETTINGS_H

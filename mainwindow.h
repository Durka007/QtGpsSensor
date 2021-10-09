#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
#include <QTimer>
#include <QtSensors>

#include "gpstrackstat.h"
#include "gpsinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    GPSTrackStat t1;
    GPSInfo s1;


private slots:
        void TimerSlot();
};


#endif // MAINWINDOW_H

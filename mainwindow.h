#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>
#include <QTimer>
#include <QtSensors>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class SensorInfo : public QObject
{
    Q_OBJECT
public:
    double x=0;
    qreal y=0;
    qreal z=0;

public:
    SensorInfo(QObject *parent = 0)
        : QObject(parent)
    {
          // QSensor *sensor= QSensor::co
           connect(sensor, SIGNAL(readingChanged()), this, SLOT(SensorsUpdated(QGyroscope)));
           sensor->start();

    }
private slots:
    void SensorsUpdated(const QGyroscope &info)
    {
        x= info.reading()->x();
        y= info.reading()->y();
        z= info.reading()->z();
    }
};



class GPSInfo : public QObject
{
    Q_OBJECT
public:
    double nowGroundSpeed=0.0;
    double nowVerticalSpeed=0.0;
    double nowMagneticVariation=0.0;
    double nowHorizontalAccuracy=0.0;
    double nowVerticalAccuracy=0.0;
    double nowLongitude=0.0;
    double nowLatitude=0.0;
    double nowDirection=0.0;
    QString nowTimes="";
public:
    GPSInfo(QObject *parent = 0)
        : QObject(parent)
    {
        QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
        if (source) {
            connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                    this, SLOT(positionUpdated(QGeoPositionInfo)));
            source->setUpdateInterval(10);// Установить время обновления в миллисекундах
            source->startUpdates();// Запускаем устройство

        }
    }

private slots://Реализовано в слот функцииGPSЧастичное чтение информации
    void positionUpdated(const QGeoPositionInfo &info)
    {
        nowLongitude = info.coordinate().longitude();// Долгота
        nowLatitude = info.coordinate().latitude();// Широта
        nowDirection = info.attribute(QGeoPositionInfo::Direction);
        nowGroundSpeed = info.attribute(QGeoPositionInfo::GroundSpeed);
        nowVerticalSpeed = info.attribute(QGeoPositionInfo::VerticalSpeed);
        nowMagneticVariation = info.attribute(QGeoPositionInfo::MagneticVariation);
        nowHorizontalAccuracy = info.attribute(QGeoPositionInfo::HorizontalAccuracy);
        nowVerticalAccuracy = info.attribute(QGeoPositionInfo::VerticalAccuracy);
        nowTimes = info.timestamp().toString();
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    GPSInfo t1;
    SensorInfo s1;
private slots:
        void TimerSlot();
};


#endif // MAINWINDOW_H

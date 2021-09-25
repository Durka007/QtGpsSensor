#ifndef GPSINFO_H
#define GPSINFO_H

#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>

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
    QGeoCoordinate Cordinate() const
    {
        return QGeoCoordinate(nowLatitude,nowLongitude);
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

#endif // GPSINFO_H

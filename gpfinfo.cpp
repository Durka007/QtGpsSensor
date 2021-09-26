#include "gpsinfo.h"

#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>

GPSInfo::GPSInfo(QObject *parent)
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
double GPSInfo::Latitude() const
{
    return nowLatitude;
}
double GPSInfo::Longitude() const
{
    return nowLongitude;
}

QGeoCoordinate GPSInfo::Cordinate() const
{

    return QGeoCoordinate(nowLatitude,nowLongitude);

}

void GPSInfo::positionUpdated(const QGeoPositionInfo &info)
{
    nowLongitude = info.coordinate().longitude();// Долгота
    nowLatitude = info.coordinate().latitude();// Широта
}

#ifndef GPSINFO_H
#define GPSINFO_H

#include <QGeoPositionInfoSource>
#include <QGeoCoordinate>

class GPSInfo : public QObject
{
    Q_OBJECT
private:
    double nowLongitude=0.0;
    double nowLatitude=0.0;
public:
    explicit GPSInfo(QObject *parent = 0);

    double Longitude() const;
    double Latitude() const;

    QGeoCoordinate Cordinate() const;

private slots:
    void positionUpdated(const QGeoPositionInfo &info);
};

#endif // GPSINFO_H

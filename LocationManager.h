#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H

#include <QObject>
#include <QtCore/private/qandroidextras_p.h>
#include <QGeoPositionInfoSource>

class LocationManager: public QObject
{
    Q_OBJECT
public:
    LocationManager();
    bool gpsAvailble();
    void enableGps();
    Q_SLOT void onApplicationStateChanged(Qt::ApplicationState state);
    Q_SIGNAL void applicationActived();
    void registerUpdateLocation();
    Q_SIGNAL void locationChanged(double longitude, double latitude);

private :
    Q_SLOT void positionUpdated(QGeoPositionInfo gpsPos);
    Q_SLOT void positionError(QGeoPositionInfoSource::Error e);
};

#endif // LOCATIONMANAGER_H

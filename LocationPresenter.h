#ifndef LOCATIONPRESENTER_H
#define LOCATIONPRESENTER_H

#include <QObject>
#include "SingletonTemplate.hpp"
#include "LocationManager.h"

class LocationPresenter : public QObject
{
    Q_OBJECT
public:
    LocationPresenter();
    Q_INVOKABLE bool gpsAvailble();
    Q_SLOT void onApplicationActived() { emit applicationActived(); }
    Q_SIGNAL void applicationActived();
    Q_INVOKABLE void enableGps();
    Q_INVOKABLE void registerUpdateLocation();
    Q_SLOT void onLocationChanged(double longitude, double latitude) { emit locationChanged(longitude, latitude); }
    Q_SIGNAL void locationChanged(double longitude, double latitude);
};

#endif // LOCATIONPRESENTER_H

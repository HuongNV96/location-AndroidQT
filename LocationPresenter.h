#ifndef LOCATIONPRESENTER_H
#define LOCATIONPRESENTER_H

#include <QObject>
#include <QGeoPositionInfoSource>

class LocationPresenter : public QObject
{
    Q_OBJECT
public:
    LocationPresenter();
    Q_INVOKABLE bool gpsAvailble() {
        auto methods = QGeoPositionInfoSource::createDefaultSource(this)->supportedPositioningMethods();
        return (methods == QGeoPositionInfoSource::SatellitePositioningMethods) || (methods == QGeoPositionInfoSource::AllPositioningMethods);
    }
};

#endif // LOCATIONPRESENTER_H

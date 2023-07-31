#include "LocationManager.h"

LocationManager::LocationManager()
{

}

bool LocationManager::gpsAvailble() {
    auto methods = QGeoPositionInfoSource::createDefaultSource(this)->supportedPositioningMethods();
    return (methods == QGeoPositionInfoSource::SatellitePositioningMethods) || (methods == QGeoPositionInfoSource::AllPositioningMethods);
}

void LocationManager::onApplicationStateChanged(Qt::ApplicationState state) {
    if (state == Qt::ApplicationState::ApplicationActive) {
        emit applicationActived();
    }
}

void LocationManager::enableGps() {
    QJniEnvironment env;
    auto  ACTION_SETTINGS = QJniObject::getStaticField<jstring>(env.findClass("android/provider/Settings"),
                                                               "ACTION_LOCATION_SOURCE_SETTINGS");
    QJniObject intent(env.findClass("android/content/Intent"),
                      "(Ljava/lang/String;)V",
                      ACTION_SETTINGS.object());
    QtAndroidPrivate::startActivity(intent.object(), 0);
}

void LocationManager::registerUpdateLocation() {
    auto location = QGeoPositionInfoSource::createDefaultSource(this);
    connect(location, &QGeoPositionInfoSource::positionUpdated,
            this, &LocationManager::positionUpdated);
    connect(location, &QGeoPositionInfoSource::errorOccurred,
            this, &LocationManager::positionError);
    location->startUpdates();
}


void LocationManager::positionUpdated(QGeoPositionInfo gpsPos)
{
    auto coord = gpsPos.coordinate();
    emit locationChanged(coord.longitude(), coord.latitude());
}

void LocationManager::positionError(QGeoPositionInfoSource::Error e)
{
    qDebug() << "positionError : " << e;
}

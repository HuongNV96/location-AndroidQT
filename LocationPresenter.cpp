#include "LocationPresenter.h"

LocationPresenter::LocationPresenter()
{
    auto & manager = SingletonTemplate<LocationManager>::getInstance();
    connect(&manager, &LocationManager::applicationActived, this, &LocationPresenter::onApplicationActived);
    connect(&manager, &LocationManager::locationChanged, this, &LocationPresenter::onLocationChanged);
}

bool LocationPresenter::gpsAvailble() {
    auto & manager = SingletonTemplate<LocationManager>::getInstance();
    return manager.gpsAvailble();
}

void LocationPresenter::enableGps() {
    auto & manager = SingletonTemplate<LocationManager>::getInstance();
    manager.enableGps();
}

void LocationPresenter::registerUpdateLocation() {
    auto & manager = SingletonTemplate<LocationManager>::getInstance();
    manager.registerUpdateLocation();
}


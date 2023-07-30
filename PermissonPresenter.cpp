#include "PermissonPresenter.h"

PermissonPresenter::PermissonPresenter() {
    auto & manager = SingletonTemplate<PermissionManager>::getInstance();
    connect(&manager, &PermissionManager::currentPermissonStatus, this, &PermissonPresenter::currentPermissonStatus);
    connect(&manager, &PermissionManager::applicationActived, this, &PermissonPresenter::applicationActived);
}

void PermissonPresenter::checkPermisson(QString permisson) {
    auto & manager = SingletonTemplate<PermissionManager>::getInstance();
    return manager.checkPermisson(permisson);
}

QList<QString> PermissonPresenter::getAllPermissons() {
    auto & manager = SingletonTemplate<PermissionManager>::getInstance();
    return manager.getAllPermissons();
}

QString PermissonPresenter::getPermissonsToRequest() {
    auto & manager = SingletonTemplate<PermissionManager>::getInstance();
    return manager.getPermissonsToRequest();
}

#ifndef PERMISSONPRESENTER_H
#define PERMISSONPRESENTER_H

#include "PermissionManager.h"
#include "SingletonTemplate.hpp"

class PermissonPresenter : public QObject{
    Q_OBJECT
public :
    PermissonPresenter();
    Q_SIGNAL void currentPermissonStatus(bool status);
    Q_SLOT void onCurrentPermissonStatus(bool status) { emit currentPermissonStatus(status); }

    Q_SIGNAL void applicationActived();
    Q_SLOT void onApplicationActived() { emit applicationActived(); }

    Q_INVOKABLE void checkPermisson(QString permisson, bool force);
    Q_INVOKABLE QList<QString> getAllPermissons();
    Q_INVOKABLE QString getPermissonsToRequest();
};

#endif // PERMISSONPRESENTER_H

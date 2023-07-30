#ifndef PERMISSIONMANAGER_H
#define PERMISSIONMANAGER_H

#include <QObject>
#include <QtCore/private/qandroidextras_p.h>
#include <QPermissions>
#include <QTimer>

class PermissionManager : public QObject
{
    Q_OBJECT
public:
    PermissionManager();
    Q_SLOT void onApplicationStateChanged(Qt::ApplicationState state);
    Q_SIGNAL void currentPermissonStatus(bool status);
    Q_SIGNAL void applicationActived();
    void checkPermisson(QString permisson);
    QList<QString> getAllPermissons();
    QString getPermissonsToRequest();
private :
    QMap<QString, QPermission> mPermissions {{"location permisson", QLocationPermission() },
                                            {"microphone permisson", QMicrophonePermission()}};
    QString currentPermisson;

    void openSettingDetails();
    void onCurrentPermissionStatus();
    qint64 startPoint;
};

#endif // PERMISSIONMANAGER_H

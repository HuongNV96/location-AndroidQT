#include "PermissionManager.h"
#include <QDateTime>

PermissionManager::PermissionManager()
{
}

void PermissionManager::openSettingDetails() {
    QJniEnvironment env;
    auto  ACTION_SETTINGS = QJniObject::getStaticField<jstring>(env.findClass("android/provider/Settings"),
                                                               "ACTION_APPLICATION_DETAILS_SETTINGS");
    QJniObject javaMessage = QJniObject::fromString("package:com.qtproject.location");
    auto uri = QJniObject::callStaticMethod<jobject>(env.findClass("android/net/Uri"), "parse", "(Ljava/lang/String;)Landroid/net/Uri;", javaMessage.object<jstring>());
    //auto test = uri.callObjectMethod("toString", "()Ljava/lang/String;");
    //qDebug() << "DKM vvvdhdhdhdhdh " << ACTION_SETTINGS.toString() << "   " << test.toString();
    QJniObject intent(env.findClass("android/content/Intent"),
                      "(Ljava/lang/String;Landroid/net/Uri;)V",
                      ACTION_SETTINGS.object() , uri.object());
    QtAndroidPrivate::startActivity(intent.object(), 0);
}

void PermissionManager::onApplicationStateChanged(Qt::ApplicationState state) {
    if (state == Qt::ApplicationState::ApplicationActive) {
        emit applicationActived();
    }

}
void PermissionManager::onCurrentPermissionStatus() {
    qint64 stopPoint = QDateTime::currentMSecsSinceEpoch();
    if (stopPoint - startPoint < 1000) {
        openSettingDetails();
    } else {
        emit currentPermissonStatus(qApp->checkPermission(mPermissions.value(currentPermisson)) == Qt::PermissionStatus::Granted);
    }
}

void PermissionManager::checkPermisson(QString permisson) {
    currentPermisson = permisson;
    if (qApp->checkPermission(mPermissions.value(permisson)) != Qt::PermissionStatus::Granted) {
        startPoint = QDateTime::currentMSecsSinceEpoch();
        qApp->requestPermission(mPermissions.value(permisson), this, &PermissionManager::onCurrentPermissionStatus);
    } else {
        emit currentPermissonStatus(true);
    }
}

QList<QString> PermissionManager::getAllPermissons() {
    return mPermissions.keys();
}

QString PermissionManager::getPermissonsToRequest() {
    for (auto & permisson : mPermissions.keys()) {
        if (qApp->checkPermission(mPermissions.value(permisson)) != Qt::PermissionStatus::Granted) {
            return permisson;
        }
    }
    return "";
}

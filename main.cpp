#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "PermissonPresenter.h"
#include "PermissionManager.h"
#include "LocationPresenter.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    auto & manager = SingletonTemplate<PermissionManager>::getInstance();
    QObject::connect(&app, &QGuiApplication::applicationStateChanged, &manager, &PermissionManager::onApplicationStateChanged);

    qmlRegisterType<PermissonPresenter>("App", 1, 0, "PermissonPresenter");
    qmlRegisterType<LocationPresenter>("App", 1, 0, "LocationPresenter");
    qmlRegisterType(QUrl("qrc:/App/PermissonsView.qml"), "App", 1, 0, "PermissonsView");
    qmlRegisterType(QUrl("qrc:/App/LocationView.qml"), "App", 1, 0, "LocationView");

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(QStringLiteral("qrc:/App/Main.qml"));

    return app.exec();
}

#ifndef ACTIVITYHANDLER_H
#define ACTIVITYHANDLER_H


#include <QObject>
#include <QtCore/private/qandroidextras_p.h>

class ActivityHandler : public QObject
{
    Q_OBJECT

public:
    ActivityHandler(QObject *parent = nullptr);
    static ActivityHandler *instance() { return m_instance; }

    Q_INVOKABLE void showSecondActivity();
    void activityReceiver(int requestCode, int resultCode, const QJniObject &data);

signals:
    void receiveFromActivityResult(const QString &message);

private:
    static ActivityHandler *m_instance;
};

#endif // ACTIVITYHANDLER_H


#include "activityhandler.h"


const int REQUEST_CODE = 123;
const jint RESULT_OK = QJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
ActivityHandler *ActivityHandler::m_instance = nullptr;

ActivityHandler::ActivityHandler(QObject *parent) : QObject(parent)
{
    m_instance = this;
}

void ActivityHandler::showSecondActivity()
{
    QAndroidIntent activityIntent(QtAndroidPrivate::androidActivity().object(),
                                  "org/qtproject/example/activityhandler/CustomActivity");
    QAndroidIntent(QtAndroidPrivate::androidActivity().object(), "com.example.MyService");

    QtAndroidPrivate::startActivity(
        activityIntent.handle(), REQUEST_CODE,
        [this](int requestCode, int resultCode, const QJniObject &data) {
            activityReceiver(requestCode, resultCode, data);
        });
}

void ActivityHandler::activityReceiver(int requestCode, int resultCode, const QJniObject &data)
{
    if (requestCode == REQUEST_CODE) {
        if (resultCode == RESULT_OK) {
            const QJniObject key = QJniObject::fromString("message");
            const QJniObject message = data.callObjectMethod(
                "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;", key.object());
            if (message.isValid())
                emit ActivityHandler::instance()->receiveFromActivityResult(message.toString());
        } else {
            emit ActivityHandler::instance()->receiveFromActivityResult("Rejected!");
        }
    }
}

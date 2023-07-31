import QtQuick
import QtQuick.Window
import QtQuick.Controls
import App 1.0
Window {
    id : mainWindow
    visible: true
    visibility: Window.FullScreen
    title: qsTr("hello world")

    Component {
        id : locationComponent
        LocationView {
            onGpsAvailble : {
            }
            onCancelCheckGps : {
            }
        }
    }

    Component {
        id : permissonComponent
        PermissonsView {
            onEndPermissons : {
                mainStack.push(locationComponent)
            }
        }
    }

    StackView {
        id: mainStack
        anchors.fill: parent
        initialItem: permissonComponent
    }
}

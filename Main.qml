import QtQuick
import QtQuick.Window
import QtQuick.Controls
import App 1.0
Window {
    id : mainWindow
    visible: true
    visibility: Window.FullScreen
    title: qsTr("hello world")

    PermissonsView {
        id : permissonsView
    }

    LocationView {
        id : locationView
    }

    Connections {
        target: permissonsView
        onEndPermissons : {
            console.log('gjgjgjgj')
            permissonsView.destroy()

        }
    }


}

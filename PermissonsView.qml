import QtQuick
import QtQuick.Controls
import App 1.0

Item {
    anchors.fill: parent
    property var permissonsToRequest: ""
    property var permissonPresenter: PermissonPresenter {
        onCurrentPermissonStatus: (status) => {
            if (status) {
               checkPermissons();
            }
        }

        onApplicationActived: {
           checkPermissons()
        }
    }
    Component.onCompleted: {
        checkPermissons()
    }

    function checkPermissons() {
        permissonsToRequest = permissonPresenter.getPermissonsToRequest()
        if (permissonsToRequest !== "") {
            preCondition.visible = true
            permissonPresenter.checkPermisson(permissonsToRequest);
        } else {
            endPermissons()
        }
    }

    signal endPermissons()

    Rectangle {
        id : preCondition
        visible: false
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.width / 2
        Column {
            anchors.fill: parent
            Text {
                width: parent.width
                text: qsTr("Enable " + permissonsToRequest)
                wrapMode: Text.WordWrap

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Button {
                width: parent.width
                text: "RETRY"
                onClicked: {
                    permissonPresenter.checkPermisson(permissonsToRequest);
                }
            }
        }
    }
}

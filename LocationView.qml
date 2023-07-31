import QtQuick
import QtQuick.Controls
import App 1.0

Item {
    anchors.fill: parent
    property var longitudePostion: 0
    property var latitudePostion: 0

    property var locationPresenter: LocationPresenter {
        onApplicationActived : {
            checkGpsAvailble(false)
        }

        onLocationChanged: (longitude, latitude) => {
            longitudePostion = longitude
            latitudePostion = latitude
        }
    }

    Component.onCompleted: {
        checkGpsAvailble(false)
    }

    function checkGpsAvailble(force) {
        if (!locationPresenter.gpsAvailble()) {
            preCondition.visible = true
            if (force) {
                locationPresenter.enableGps()
            }
        } else {
            preCondition.visible = false
            gpsAvailble()
            locationPresenter.registerUpdateLocation()
            locationData.visible = true
        }
    }

    signal gpsAvailble()
    signal cancelCheckGps()

    Rectangle {
        visible: false
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.width / 4

        id : locationData

        Column {
            anchors.fill : parent
            Row {
                spacing: 20
                width: parent.width

                Text {
                    width: parent.width * 0.45
                    text: qsTr("longitude")
                    wrapMode: Text.WordWrap

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    width: parent.width * 0.45
                    text: longitudePostion
                    wrapMode: Text.WordWrap

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            Row {
                spacing: 20
                width: parent.width

                Text {
                    width: parent.width * 0.45
                    text: qsTr("latitude")
                    wrapMode: Text.WordWrap

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    width: parent.width * 0.45
                    text: latitudePostion
                    wrapMode: Text.WordWrap

                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }
    }

    Rectangle {
        id : preCondition
        visible: false
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.width / 2
        Column {
            anchors.fill: parent
            Text {
                id : labelEnable
                width: parent.width
                text: qsTr("Enable Location Setting")
                wrapMode: Text.WordWrap

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Row {
                width: parent.width
                anchors.top : labelEnable.bottom

                spacing: 20
                Button {
                    width: parent.width * 0.45
                    anchors.left: parent.left
                    text: "YES"
                    onClicked: {
                        checkGpsAvailble(true)
                    }
                }

                Button {
                    width: parent.width * 0.45
                    anchors.right: parent.right
                    text: "NO"
                    onClicked: {
                        preCondition.visible = false
                        cancelCheckGps()
                        locationPresenter.registerUpdateLocation()
                        locationData.visible = true
                    }
                }
            }
        }
    }
}

import QtQuick
import QtQuick.Controls
import App 1.0

Item {
    property var locationPresenter: LocationPresenter {}
    Component.onCompleted: {
        console.log(locationPresenter.gpsAvailble())
    }
}

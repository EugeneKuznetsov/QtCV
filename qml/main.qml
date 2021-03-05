import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

ApplicationWindow {
    visible: true
    minimumWidth: 800
    minimumHeight: 600

    VideoOutput {
        anchors.fill: parent

        source: webCam
    }

    Camera {
        id: webCam

        deviceId: QtMultimedia.availableCameras[QtMultimedia.availableCameras.length - 1].deviceId
    }
}

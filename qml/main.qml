import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtMultimedia 5.15
import Eugene.QtCV.Filters 1.0

ApplicationWindow {
    readonly property string cameraId: QtMultimedia.availableCameras[QtMultimedia.availableCameras.length - 1].deviceId

    visible: true
    minimumWidth: 800
    minimumHeight: 600

    VideoOutput {
        id: cameraOutput

        anchors.fill: parent

        source: Camera {
            deviceId: cameraId
        }
        filters: [
            HelloWorldFilter {
                onSayHelloWorld: {
                    let face = cameraOutput.mapRectToItem(Qt.rect(x, y, w, h))
                    userFace.x = face.x
                    userFace.y = face.y
                    userFace.width = face.width
                    userFace.height = face.height
                    userFace.visible = true
                }

                onShutUp: {
                    userFace.visible = false
                }
            }
        ]
    }

    Rectangle {
        id: userFace

        color: "transparent"
        border.width: 3
        border.color: "blue"
        visible: false
    }
}

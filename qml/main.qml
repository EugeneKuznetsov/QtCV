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
        anchors.fill: parent

        fillMode: Image.PreserveAspectCrop
        source: Camera {
            deviceId: cameraId
        }
        filters: [
            HelloWorldFilter {
                onSayHelloWorld: {
                    userLabel.visible = true
                    userLabel.x = x + w
                    userLabel.y = y
                }

                onShutUp: {
                    userLabel.visible = false
                }
            }
        ]
    }

    Pane {
        id: userLabel

        visible: false

        Label {
            anchors.fill: parent

            text: "Hello World"
        }
    }
}

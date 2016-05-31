import QtQuick 2.6
import QtQuick.Layouts 1.0
import Qt.labs.controls 1.0
import QtMultimedia 5.6

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    MediaPlayer {
        id: mediaplayer
        source: "/home/micc/DRZ/code/learning-qml/MoviePlayer/example.mp4"
    }

    VideoOutput {
        anchors.fill: parent
        source: mediaplayer
    }

    MouseArea {
        id: playArea
        anchors.fill: parent
        onPressed: mediaplayer.play();
    }

}

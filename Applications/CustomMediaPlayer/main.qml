import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.0
import QtMultimedia 5.6
import QtQuick.Controls 2.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "black"
    title: "Movie Player"

    Button {
        text: "click me"
        onClicked: {
            myplayer.playDemo()
        }
    }

    VideoOutput {
        anchors.fill: parent
        source: myplayer
    }



}

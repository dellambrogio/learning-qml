import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.0
import QtMultimedia 5.6
import QtQuick.Layouts 1.0
import Qt.labs.controls 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    FileDialog {
        id: fileDialogID
        visible: false
        modality: Qt.WindowModal
        title: "Please choose a file"
        folder: shortcuts.home
        selectFolder: false
        selectExisting: true
        selectMultiple: false
        onAccepted: {
            filenameID.text = fileDialogID.fileUrl
            mediaplayer.source = fileDialogID.fileUrl
            mediaplayer.play();
        }
        onRejected: {
            filenameID.text = ""
        }
    }

    Button {
        id: openDialogID
        text: "Choose"
        width: 60
        onClicked: {
            fileDialogID.open()
        }
    }

    Text {
        id: filenameID
        width: 520
        text: "here the filename"
        anchors.left: openDialogID.right
    }

    Text {
        anchors.top: openDialogID.bottom
        text: mediaplayer.duration
    }


    MediaPlayer {
        id: mediaplayer
        source: ""
    }

    VideoOutput {
        anchors.fill: parent
        source: mediaplayer
    }


    Slider {
        anchors.bottom: parent.bottom
        value: mediaplayer.position / mediaplayer.duration
        property bool isChanging;

        onPressedChanged: {
            if (pressed) {
                isChanging = true;
                mediaplayer.pause();
            } else {
                isChanging = false;
                mediaplayer.play();
            }
        }

        onValueChanged: {
           console.log(mediaplayer.status)
           if (isChanging)
           {
               var newPosition = value * mediaplayer.duration
               mediaplayer.seek(newPosition)
           }
        }
    }





    //    MouseArea {
    //        id: playArea
    //        anchors.fill: parent
    //        onPressed: mediaplayer.play();
    //    }

}

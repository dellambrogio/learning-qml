import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.0

import QtMultimedia 5.6

import Qt.labs.controls 1.0


Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "black"
    title: "Movie Player"

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
            window.title = fileDialogID.fileUrl
            mediaplayer.source = fileDialogID.fileUrl
            mediaplayer.play();
        }
        onRejected: {
            window.title = "Movie Player"
        }
    }

    //    MouseArea {
    //        enabled: true
    //        anchors.fill: parent
    //        onPressed: fileDialogID.open()
    //    }

    MediaPlayer {
        id: mediaplayer
        source: ""
    }

    VideoOutput {
        anchors.fill: parent
        source: mediaplayer
    }

    Rectangle {
        anchors.top: parent.top
        color: "lightgray"

        Row {
        }
    }


    Rectangle {
        anchors.bottom: parent.bottom
        height: 40
        width: 400
        x: (parent.width / 2) - (width / 2)
        color: "lightblue"

        Row {
            anchors.centerIn: parent

            Slider {
                id: timeSlider
                value: mediaplayer.position / mediaplayer.duration

                property bool isChanging

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
                    //console.log(mediaplayer.status)
                    if (isChanging)
                    {
                        var newPosition = value * mediaplayer.duration
                        mediaplayer.seek(newPosition)
                    }
                }
            }

            Button {
                id: openDialogID
                text: "Choose"
                width: 120
                height: 30
                onClicked: {
                    fileDialogID.open()
                }
            }

//            Text {
//                width: 200
//                height: 30
//                text: mediaplayer.duration
//            }

        }
    }









}

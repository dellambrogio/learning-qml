import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    color: "lightgray"

    Row {
        spacing: 2

        Rectangle {
            id: currentDisc
            x: 4
            y: 4
            width: 60
            height: 60
            radius: width*0.5
            color: "transparent"
        }

        Rectangle {
            id: gameSwitcher
            color: "lightblue"
            width: 60
            height: 60

            Text {
                anchors.centerIn: parent
                text: "Start"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    board.state = "BLACK"
                }
            }
        }

        Rectangle {
            width: 200
            height: 60
            Text {
                anchors.centerIn: parent
                id: stateLabel
                text: ""
            }
            color: "lightyellow"
        }
    }

    Board {
        id: board
        anchors.centerIn: parent

//        state: "NEW"

//        states: [
//            State {
//                name: "NEW"
//                PropertyChanges { target: stateLabel; text: "please start..."}
//                PropertyChanges { target: currentDisc; color: "transparent"}
//            },
//            State {
//                name: "BLACK"
//                PropertyChanges { target: stateLabel; text: "black is playing..."}
//                PropertyChanges { target: currentDisc; color: "black"}
//            },
//            State {
//                name: "WHITE"
//                PropertyChanges { target: stateLabel; text: "white is playing..."}
//                PropertyChanges { target: currentDisc; color: "white"}
//            },
//            State {
//                name: "END"
//                PropertyChanges { target: stateLabel; text: "end"}
//                PropertyChanges { target: currentDisc; color: "transparent"}
//            }
//        ]
    }

}


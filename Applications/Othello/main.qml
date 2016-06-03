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

//                    Rectangle {
//                        id: disc
//                        x: 4
//                        y: 4
//                        width: 60
//                        height: 60
//                        radius: width*0.5
//                        color: {
//                            //var row = Math.floor(index / 8);
//                            //var column = index % 8
//                            //repeater.model[index] ? "black" : "white";
//                            if (repeater.model[index] === undefined)
//                                return 'transparent'

//                            if (repeater.model[index])
//                                return 'white'
//                            else
//                                return 'black'
//                        }

//                        MouseArea {
//                            anchors.fill: parent
//                            onClicked: {
//                                //var x = index % 8;
//                                //var y = Math.floor(index/8);

//                                var squares = repeater.model
//                                squares[index] = true;
//                                repeater.model = squares;
//                            }
//                        }
//                    }

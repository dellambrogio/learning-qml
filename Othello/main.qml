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


    Rectangle {
        id: board
        anchors.centerIn: parent
        width: (grid.width + grid.x*2)
        height: (grid.height + grid.y*2)
        color: "darkgray"

        Grid {
            id: grid
            x: 10
            y: 10
            rows: 8
            columns: 8
            spacing: 2
            Repeater {
                id: repeater
                model: {
                    var data = []
                    for (var i = 0; i < 64; ++i)
                        data[i] = undefined;

                    data[27] = true;
                    data[28] = false;
                    data[35] = false;
                    data[36] = true;

                    data;
                }

                Rectangle {
                    width: (disc.width + disc.x*2)
                    height: (disc.height + disc.y*2)
                    color: "green"

                    Rectangle {
                        id: disc
                        x: 4
                        y: 4
                        width: 60
                        height: 60
                        radius: width*0.5
                        color: {
                            //var row = Math.floor(index / 8);
                            //var column = index % 8
                            //repeater.model[index] ? "black" : "white";
                            if (repeater.model[index] === undefined)
                                return 'transparent'

                            if (repeater.model[index])
                                return 'white'
                            else
                                return 'black'
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            //var x = index % 8;
                            //var y = Math.floor(index/8);

                            var squares = repeater.model
                            squares[index] = true;
                            repeater.model = squares;
                        }
                    }
                }
            }
        }

        state: "NEW"

        states: [
            State {
                name: "NEW"
                PropertyChanges { target: stateLabel; text: "please start..."}
                PropertyChanges { target: currentDisc; color: "transparent"}
            },
            State {
                name: "BLACK"
                PropertyChanges { target: stateLabel; text: "black is playing..."}
                PropertyChanges { target: currentDisc; color: "black"}
            },
            State {
                name: "WHITE"
                PropertyChanges { target: stateLabel; text: "white is playing..."}
                PropertyChanges { target: currentDisc; color: "white"}
            },
            State {
                name: "END"
                PropertyChanges { target: stateLabel; text: "end"}
                PropertyChanges { target: currentDisc; color: "transparent"}
            }
        ]
    }

}

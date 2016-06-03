import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    color: "lightgray"

    Rectangle
    {
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
                    var board = []
                    for (var i = 0; i < 64; ++i)
                        board[i] = false;
                    board;
                }

                Rectangle {
                    width: 70
                    height: 70
                    color: "green"

                    Rectangle {
                        x: 4
                        y: 4
                        width: (parent.width - (2*x))
                        height: (parent.height - (2*y))
                        radius: width*0.5
                        color: {
                            //var row = Math.floor(index / 8);
                            //var column = index % 8
                            repeater.model[index] ? "black" : "white";
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
    }
}

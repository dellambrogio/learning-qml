import QtQuick 2.5

Rectangle {
    id: root
    width: 514
    height: 514
    color: "darkgray"
    property bool currentPlayer

    Grid {
        id: grid
        x: 10
        y: 10
        rows: 8
        columns: 8
        spacing: 2

        Repeater {
            id: repeater

            BoardCell {
                Disc {
                    id: disc
                    onPressed: {
                        var squares = repeater.model;
                        var player = root.currentPlayer;
                        squares[index] = player;
                        if (player)
                            root.state = "BLACK_IS_PLAYING"
                        else
                            root.state = "WHITE_IS_PLAYING"
                        repeater.model = squares;
                    }
                    state: {
                        if (repeater.model[index] === undefined)
                            return 'NONE'

                        if (repeater.model[index])
                            return 'WHITE'
                        else
                            return 'BLACK'
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        reset()
    }

    function reset() {
        var data = []
        for (var i = 0; i < 64; ++i)
            data[i] = undefined;

        data[27] = true;
        data[28] = false;
        data[35] = false;
        data[36] = true;

        repeater.model = data;
    }

    state: "BLACK_IS_PLAYING"

    states: [
        State {
            name: "NOGAME"
            PropertyChanges { target: root; currentPlayer: true}
        },
        State {
            name: "BLACK_IS_PLAYING"
            PropertyChanges { target: root; currentPlayer: false}
        },
        State {
            name: "WHITE_IS_PLAYING"
            PropertyChanges { target: root; currentPlayer: true}
        }
    ]
}

import QtQuick 2.5

Rectangle {
    id: root
    width: 60
    height: 60
    radius: width*0.5

    signal pressed()

    MouseArea {
        anchors.fill: parent
        onPressed: {
            if (parent.state === "NONE")
            {
                root.pressed()
            }
        }
    }

    state: "NONE"

    states: [
        State {
            name: "NONE"
            PropertyChanges { target: root; color: "transparent"}
        },
        State {
            name: "BLACK"
            PropertyChanges { target: root; color: "black"}
        },
        State {
            name: "WHITE"
            PropertyChanges { target: root; color: "white"}
        }
    ]
}

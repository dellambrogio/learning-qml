import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    color: "gray"

    Rectangle
    {
        id: semaphoreID
        anchors.centerIn: parent
        width: 120
        height: 340
        color: "black"
        radius: 10

        Rectangle {
            id: redID
            x: 10
            y: 10
            width: 100
            height: width
            color: "light gray"
            radius: 30
        }

        Rectangle {
            x: 10
            y: 120
            id: yellowID
            width: 100
            height: width
            color: "light gray"
            radius: 30
        }

        Rectangle {
            x: 10
            y: 230
            id: greenID
            width: 100
            height: width
            color: "light gray"
            radius: 30
        }

        state: "STOP"

        states: [
            State {
                name: "STOP"
                PropertyChanges { target: redID; color: "red"}
                PropertyChanges { target: yellowID; color: "light gray"}
                PropertyChanges { target: greenID; color: "light gray"}
            },
            State {
                name: "READY"
                PropertyChanges { target: redID; color: "light gray"}
                PropertyChanges { target: yellowID; color: "yellow"}
                PropertyChanges { target: greenID; color: "light gray"}
            },
            State {
                name: "GO"
                PropertyChanges { target: redID; color: "light gray"}
                PropertyChanges { target: yellowID; color: "light gray"}
                PropertyChanges { target: greenID; color: "green"}
            }
        ]

        transitions: [
            Transition {
                from: "STOP"
                to: "READY"
                reversible: true
                ColorAnimation { target: redID; duration: 500}
                ColorAnimation { target: yellowID; duration: 500}
            },
            Transition {
                from: "READY"
                to: "GO"
                reversible: true
                ColorAnimation { target: yellowID; duration: 500}
                ColorAnimation { target: greenID; duration: 500}
            },
            Transition {
                from: "GO"
                to: "STOP"
                reversible: true
                ColorAnimation { target: greenID; duration: 500}
                ColorAnimation { target: redID; duration: 500}
            }
        ]
    }

    MouseArea {
        anchors.fill: parent

        onClicked: {
            if (semaphoreID.state == "STOP")
                semaphoreID.state = "READY"
            else if (semaphoreID.state == "READY")
                semaphoreID.state = "GO"
            else
                semaphoreID.state = "STOP"
        }

    }
}

import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    color: "lightgray"

    Rectangle
    {
        anchors.centerIn: parent
        width: 650
        height: 650
        color: "black"

        Grid {
            x: 10
            y: 10
            rows: 8
            columns: 8
            spacing: 10
            Repeater {
                model: 64

                Rectangle {
                    width: 70
                    height: 70
                    color: "darkgreen"
                }
            }
        }
    }
}

import QtQuick 2.7
import QtQuick.Window 2.2

Window {
	id: appWindow
	width: 800
	height: 600
	visible: true
	color: "#494949"


    Rectangle {
        id: augs
        color: "lightgray"
        width: 120
        height: parent.height

        ListView {
            anchors.fill: parent
            clip: true

            model: ctrl.augmentations

            delegate: augsDelegate

            focus: true

        }
    }

    Component {
        id: augsDelegate
        Item {
            width: 120
            height: 60
            Column {
                Text {
                    text: index
                }
                Text {
                    text: model.modelData.name
                }
            }
        }
    }

    Rectangle {
        color: "lightgray"
        width: 120
        anchors.right: parent.right
        height: parent.height

        ListView {
            anchors.fill: parent
            clip: true

            model: ctrl.augmentations2

            delegate: augsDelegate2

            focus: true

        }
    }

    Component {
        id: augsDelegate2
        Item {
            width: 120
            height: 60
            Column {
                Text {
                    text: index
                }
                Text {
                    text: name
                }
            }
        }
    }


}

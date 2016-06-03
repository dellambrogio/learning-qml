import QtQuick 2.3
import QtQuick.Window 2.2

Window {
  visible: true

  property color color1: "yellow"
  property color color2: "red"
  property color color3: "grey"

  Rectangle {
    width: 600
    height: 400

    Image {
      id: mapImage
      source: "CH.jpg"
      x: 0
      y: 0
      width: 364
      height: 227


      MouseArea {
        anchors.fill: parent
        drag.target: mapImage
        drag.axis: Drag.XandYAxis
      }
    }

    Image {
      id: theme
      source: "Bev.png"

      width: 364
      height: 227

      anchors.left: mapImage.left;
      anchors.top: mapImage.top;
    }

    Rectangle {
      id: zoomIn
      width: 30
      height: 30
      color: color1
      opacity: 0.8
      Text {
        anchors.centerIn: parent
        text: "+"
      }
      MouseArea {
        anchors.fill: parent
        onClicked: {
          mapImage.width = mapImage.width * 1.2
          mapImage.height = mapImage.height * 1.2
          theme.width = theme.width * 1.2
          theme.height = theme.height * 1.2
        }
        hoverEnabled: true
        onEntered: parent.color = color2
        onExited:  parent.color = color1
      }
    }

    Rectangle {
      id: zoomOut
      width: 30
      height: 30
      anchors.left: zoomIn.right;
      color: color1
      opacity: 0.8
      Text {
        anchors.centerIn: parent
        text: "-"
      }
      MouseArea {
        anchors.fill: parent
        onClicked: {
          mapImage.width = mapImage.width * 0.8
          mapImage.height = mapImage.height * 0.8
          theme.width = theme.width * 0.8
          theme.height = theme.height * 0.8
        }
        hoverEnabled: true
        onEntered: parent.color = color2
        onExited:  parent.color = color1
      }
    }

    Rectangle {
      id: backSlider
      x: 100
      y: 10
      width: 120
      height: 20
      color: color3
      radius: 6
      opacity: 0.8
    }

    Rectangle {
      id: buttonSlider
      x: 200
      y: 10
      width: 20
      height: 20
      color: color1
      radius: 6
      opacity: 0.8

      onXChanged: {
        theme.opacity = (x - 100) / 100
      }

      MouseArea {
        anchors.fill: parent
        drag.target: buttonSlider
        drag.axis: Drag.XAxis

        drag.minimumX: 100
        drag.maximumX: 200

      }
    }
  }
}

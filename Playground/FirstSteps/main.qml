import QtQuick 2.3
import QtQuick.Window 2.2

Window {
  visible: true

  Rectangle {
    width: 300
    height: 200
    x: (parent.width / 2) - this.width / 2
    y: (parent.height / 2) - this.height / 2

    color: "red"

    Text {
      anchors.centerIn: parent
      text: "Hello, World!"
    }

    // mouse inputs
    MouseArea {
      anchors.fill: parent
      onClicked: parent.color = "blue"
    }

    // key inputs
    focus: true
    Keys.onPressed: {
      if (event.key == Qt.Key_Return) {
        color = "green";
        event.accepted = true;
      }
    }

    // property bindings
    Rectangle {
      color: "yellow"
      width: parent.width / 2
      height: parent.height / 4
    }

    Rectangle {
      color: "cyan"
      width: parent.width / 2
      height: parent.height / 4
      x: parent.width / 2
    }
  }

  // animations
  Rectangle {
    color: "lightgray"
    width: 200
    height: 200

    property int animatedValue: 0
    SequentialAnimation on animatedValue {
      loops: Animation.Infinite
      PropertyAnimation { to: 150; duration: 1000 }
      PropertyAnimation { to: 0; duration: 1000 }
    }

    Text {
      anchors.centerIn: parent
      text: parent.animatedValue
    }
  }

  // Defining Custom QML Types for Re-use

  MyButton {
    y: parent.height - this.height
    width: 50;
    height: 50;
    radius: 8
  }
}


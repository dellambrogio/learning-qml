import QtQuick 2.3
import QtQuick.Controls 1.2

//window containing the application
ApplicationWindow {

  //title of the application
  visible: true
  width: 640
  height: 480
  title: qsTr("Hello World")

  //menu containing two menu items
  menuBar: MenuBar {
    Menu {
      title: qsTr("File")
      MenuItem {
        text: qsTr("&Open")
        onTriggered: console.log("Open action triggered");
      }
      MenuItem {
        text: qsTr("Exit")
        onTriggered: Qt.quit();
      }
    }
  }

  //Content Area

  Label {
    text: qsTr("Hello World")
  }

  Button {
    text: qsTr("Hello World")
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
  }
}


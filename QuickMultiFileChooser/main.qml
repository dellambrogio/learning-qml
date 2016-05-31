import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.0
import QtQuick.Layouts 1.3

ApplicationWindow {

  visible: true
  width: 640
  height: 480
  title: qsTr("Hello World")

  function logModel()
  {
    console.log("List of files");
    for(var i = 0; i < fileListModelID.count; ++i) {
      console.log(fileListModelID.get(i).fileUrl);
    }
  }

  onClosing: {
    logModel()
  }

  menuBar: MenuBar {
    Menu {
      title: qsTr("File")
      MenuItem {
        text: qsTr("&Add New File")
        onTriggered: {
          fileListModelID.append({fileUrl: ""})
        }
      }
      MenuItem {
        text: qsTr("Exit")
        onTriggered: {
          logModel()
          Qt.quit()
        }
      }
    }
  }

  ListModel {
    id: fileListModelID
    ListElement {
      fileUrl: ""
    }
  }

  Component {
    id: fileListDelegateID

    Item {
      width: 640
      height: 40

      Row {

        FileDialog {
          id: fileDialogID
          visible: false
          modality: Qt.WindowModal
          title: "Please choose a file"
          folder: shortcuts.home
          selectFolder: false
          selectExisting: true
          selectMultiple: false
          onAccepted: {
            filenameID.text = fileDialogID.fileUrl
            fileListModelID.set(index, {fileUrl: filenameID.text})
          }
          onRejected: {
            filenameID.text = ""
            fileListModelID.get(index, {fileUrl: ""})
          }
        }

        Button {
          text: "Choose"
          width: 60
          onClicked: {
            fileDialogID.open()
          }
        }
        Text {
          id: filenameID
          width: 520
          text: fileUrl
        }
        Button {
          width: 30
          text: "+"
          onClicked: {
            fileListModelID.insert(index+1, {fileUrl: ""})
          }
        }
        Button {
          width: 30
          text: "-"
          onClicked: {
            fileListModelID.remove(index)
          }
        }
      }
    }
  }

  ScrollView {
    width: parent.width
    height: parent.height
    ListView {
      model: fileListModelID
      delegate: fileListDelegateID
    }
  }
}


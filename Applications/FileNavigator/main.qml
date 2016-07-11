import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Qt.labs.folderlistmodel 2.1
import QtQuick.Dialogs 1.0

ApplicationWindow {
	visible: true
	width: 800
	height: 600

	FileDialog {
		id: fileDialogID
		visible: false
		modality: Qt.WindowModal
		title: "Please choose a file"
		folder: shortcuts.home
		selectFolder: true
		selectExisting: true
		selectMultiple: false
		onAccepted: {
			//filenameID.text = fileDialogID.fileUrl
			//fileListModelID.set(index, {fileUrl: filenameID.text})
			folderModel.folder = fileDialogID.fileUrl;
			rootText.text = fileDialogID.fileUrl
		}
		onRejected: {
			//filenameID.text = ""
			//fileListModelID.get(index, {fileUrl: ""})
		}
	}

	FolderListModel {
		id: folderModel
		//nameFilters: ["*.*"]
		folder: "file:///home/micc/Pictures"
	}

	Component {
		id: fileDelegate
		Text {
			text: filePath
			MouseArea {
				hoverEnabled: true
				anchors.fill: parent
				onEntered: {
					previewImage.source = fileURL
				}
				onExited: {
					previewImage.source = ""
				}
			}
		}
	}

	RowLayout {
		width: parent.width

		TextEdit {
			id: rootPath
			text: "type here..."
		}

		ListView {
			width: 200
			height: 400
			model: folderModel
			delegate: fileDelegate
		}
	}

	Image {
		id: previewImage
		width: 400
		anchors.centerIn: parent
		fillMode: Image.PreserveAspectFit
	}

	RowLayout {
		id: toolbar
		anchors.bottom: parent.bottom
		width: parent.width
		height: 60

		Button {
			text: "choose directory"
			onPressed: {
				fileDialogID.open()
			}
		}
		Text {
			id: rootText
			text: folderModel.folder
		}
	}

}


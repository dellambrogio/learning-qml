import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Qt.labs.folderlistmodel 2.1
import QtQuick.Controls.Material 2.0
import QtQuick.Controls.Universal 2.0
import QtQuick.Dialogs 1.0

ApplicationWindow {
	id: window
	width: 360
	height: 520
	visible: true
	title: "File Navigator"

	// toolbar

	header: ToolBar {
		Material.foreground: "white"
		RowLayout {
			spacing: 20
			anchors.fill: parent

			ToolButton {
				text: "choose directory"
				onClicked: {
					fileDialogID.open()
				}
			}

			Label {
				id: titleLabel
				text: folderModel.folder
				font.pixelSize: 12
				elide: Label.ElideRight
				horizontalAlignment: Qt.AlignHCenter
				verticalAlignment: Qt.AlignVCenter
				Layout.fillWidth: true
			}
		}
	}

	// file listing components

	FolderListModel {
		id: folderModel
		nameFilters: [liveSearch.text]
		folder: "file:///home/micc/Pictures"
		//Property { name: "sortField"; type: "SortField" }
		//Property { name: "sortReversed"; type: "bool" }
	}

	Component {
		id: fileDelegate
		Text {
			text: filePath
			MouseArea {
				hoverEnabled: true
				anchors.fill: parent
				onEntered: {
					//previewImage.source = fileURL
				}
				onExited: {
					//previewImage.source = ""
				}
			}
		}
	}

	// file listing

	ListView {
		x: 20
		y: 20
		width: parent.width
		height: parent.height
		model: folderModel
		delegate: fileDelegate
	}

	Image {
		id: previewImage
		width: 400
		anchors.centerIn: parent
		fillMode: Image.PreserveAspectFit
	}

	Rectangle {
		id: toolbar
		anchors.bottom: parent.bottom
		width: parent.width
		height: 60
		color: "lightgray"

		RowLayout {
			anchors.fill: parent

			TextEdit {
				id: liveSearch
				text: "*.*"
			}
		}
	}


	// file chooser
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

}


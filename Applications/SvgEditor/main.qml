import QtQuick 2.6
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "componentCreation.js" as MyScript

ApplicationWindow {
	id: appWindow
	width: 800
	height: 600
	visible: true
	title: "SVG Editor"

	// toolbar

	header: ToolBar {
		RowLayout {
			spacing: 20
			anchors.fill: parent

			ToolButton {
				text: "add point"
				onClicked: {
					MyScript.createSpriteObjects();
				}
			}
		}
	}

	Rectangle {
		id: surface
		anchors.centerIn: parent
		width: 512
		height: 512

		Image {
			source: "castle.png"
		}

	}


}


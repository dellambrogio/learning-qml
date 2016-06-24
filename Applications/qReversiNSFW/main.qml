import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
	visible: true

	RowLayout {
		Button {
			text: "start"
			onClicked: gameController.newGame()
		}
		Text {
			text: "current player: " + gameController.currentPlayer
		}
		Text {
			text: gameController.numBlackStones + ":" + gameController.numWhiteStones
		}
	}

	Rectangle {
		anchors.centerIn: parent
		width: 650
		height: 650
		color: "blue"

		Grid {
			x: 10
			y: 10
			rows: 8
			columns: 8
			spacing: 10
			Repeater {
				model: myModel

				Rectangle {
					width: 70
					height: 70
					color: model.modelData.color

					MouseArea {
						anchors.fill: parent
						onClicked: {
							gameController.makeMove(index)
						}
					}
				}
			}
		}
	}

}


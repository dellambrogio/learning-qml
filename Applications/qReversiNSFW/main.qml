import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import ReversiController 1.0

ApplicationWindow {
	visible: true

	Rectangle {
		width: parent.width
		height: 70
		color: "lightgray"

		RowLayout {
			spacing: 2

			Button {
				text: "start"
				onClicked: gameController.newGame()
			}

			Rectangle {
				width: 70
				height: 70
				color: "black"
				Text {
					anchors.centerIn: parent
					color: "white"
					text: gameController.numBlackStones
					font.pointSize: 30
				}
			}

			Rectangle {
				width: 70
				height: 70
				color: "white"
				Text {
					anchors.centerIn: parent
					color: "black"
					text: gameController.numWhiteStones
					font.pointSize: 30
				}
			}

			Text {
				font.pointSize: 30
				text:	{
					if (gameController.currentPlayer == Player.Black)
					{
						"black"
					}
					else if (gameController.currentPlayer == Player.White)
					{
						"white"
					}
					else
					{
						"nope"
					}
				}
			}

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
				model: gameController.cells

				Rectangle {
					width: 70
					height: 70
					color: model.modelData.color
					border.color: "light blue"
					border.width: {
						if (model.modelData.isValidMove)
							2
						else
							0
					}

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


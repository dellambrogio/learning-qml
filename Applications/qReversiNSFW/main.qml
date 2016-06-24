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
				text: gameController.getCurrentDateTime()
			}
	}

}


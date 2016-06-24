import QtQuick 2.5
import QtQuick.Window 2.2

Window {
	visible: true
	color: "lightgray"

	Text {
		text: gameController.getCurrentDateTime()
	}
}


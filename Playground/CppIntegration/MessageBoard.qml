import QtQuick 2.0

Item {
		width: 100
		height: 100

		MouseArea {
				anchors.fill: parent
				onClicked: {
						var result = msgBoard.postMessage("Hello from QML")
						console.log("Result of postMessage():", result)
						msgBoard.refresh();
				}
		}
}

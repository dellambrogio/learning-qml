
import QtQuick 2.6

Rectangle {
	width: 20
	height: 20
	color: "red"

	MouseArea {
		anchors.fill: parent
		onClicked: {
			//console.log("clicked");
		}
		onPositionChanged: {
			//console.log(this.x + " " + this.y);
		}
		drag.target: parent
		drag.axis: Drag.XandYAxis
	}
}

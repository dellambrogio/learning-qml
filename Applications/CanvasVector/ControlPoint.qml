
import QtQuick 2.6

Rectangle {
	width: 20
	height: 20
	color: "transparent"
	border.width: 2
	border.color: "red"

	signal positionChanged

	MouseArea {
		anchors.fill: parent
		onClicked: {
			//console.log("clicked");
		}
		onPositionChanged: {
			//console.log(this.x + " " + this.y);
			parent.positionChanged()
		}
		drag.target: parent
		drag.axis: Drag.XandYAxis
	}
}

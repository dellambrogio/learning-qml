import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "componentCreation.js" as MyScript


ApplicationWindow {
	id: appWindow
	width: 800
	height: 600
	visible: true
	title: "Canvas Vector"
	color: "#494949"

	header: ToolBar {
		RowLayout {
			spacing: 20
			anchors.fill: parent

			ToolButton {
				text: "add POI"
				onClicked: {
					//MyScript.createSpriteObjects();
				}
			}
		}
	}

	ListModel {
		id: pois
		ListElement { points: [
				ListElement{x: 0.2; y: 0.4},
				ListElement{x: 0.5; y: 0.5},
				ListElement{x: 0.3; y: 0.9}
			] }

		ListElement { points: [
				ListElement{x: 0.4; y: 0.8},
				ListElement{x: 0.4; y: 0.9},
				ListElement{x: 0.3; y: 0.7}
			] }
	}

	//	Row {
	//			id: colorTools
	//			anchors {
	//					horizontalCenter: parent.horizontalCenter
	//					top: parent.top
	//					topMargin: 8
	//			}
	//			property variant activeSquare: red
	//			property color paintColor: "#33B5E5"
	//			spacing: 4
	//			Repeater {
	//					model: ["#33B5E5", "#99CC00", "#FFBB33", "#FF4444"]
	//					ColorSquare {
	//							id: red
	//							color: modelData
	//							active: parent.paintColor == color
	//							onClicked: {
	//									parent.paintColor = color
	//							}
	//					}
	//			}
	//	}

	Rectangle {
		id: stage
		width: 800
		height: 600
		anchors.centerIn: parent
		color: "black"


		Canvas {
			id: canvas
			width: parent.width
			height: parent.height

			onPaint: {
				var ctx = getContext('2d')

				ctx.fillStyle = 'white'
				var size = 6
				var hhsize = size * 0.5

				for(var i=0; i<pois.count; i++) {

					var points = pois.get(i).points

					ctx.beginPath()

					for (var j=0; j<points.count; j++) {

						var x = (points.get(j).x * width) - hhsize
						var y = (points.get(j).y * height) - hhsize

						if (j===0)
							ctx.moveTo(x, y)
						else
							ctx.lineTo(x, y)
					}

					ctx.closePath();
					ctx.lineWidth = 5;
					ctx.fillStyle = '#8ED6FF';
					ctx.fill();
					ctx.strokeStyle = 'blue';
					ctx.stroke();

				}

			}
			MouseArea {
				id: area
				anchors.fill: parent
				onPressed: {
					//					var px = mouseX/canvas.width
					//					var py = mouseY/canvas.height
					//					points.append({x: px, y: py})

					//					//canvas.lastX = mouseX
					//					//canvas.lastY = mouseY
					//					canvas.requestPaint()
				}
				onPositionChanged: {
				}
			}
		}

	}

	Column {
		spacing: 2

		Repeater {
			model: pois

			Item {
				Component.onCompleted: {
					var points = pois.get(index).points
					var size = 12
					var hhsize = size * 0.5

					for (var j=0; j<points.count; j++) {

						var x = (points.get(j).x * canvas.width) - hhsize
						var y = (points.get(j).y * canvas.height) - hhsize

						var component = Qt.createComponent("ControlPoint.qml");

						if (component.status === Component.Ready) {
							var obj = {"x": x, "y": y, "width": size, "height": size}
							var cp = component.createObject(stage, obj);
						}
					}
				}
			}

			//					Repeater {
			//						model: modelData.points

			//						ControlPoint {
			//							x: 100
			//							y: 100
			//						}

			//					}

			//					Text {
			//							width: 120
			//							height: 32
			//							text: index
			//							color: "white"
			//					}
		}
	}
}

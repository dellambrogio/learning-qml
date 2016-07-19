import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3


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
				text: "Add Poi"
				onClicked: {
				}
			}
		}
	}


	Row {
			spacing: 20
			anchors.horizontalCenter: parent.horizontalCenter

			RadioButton {
					text: "square"
					checked: true
					onCheckedChanged: {
						if (checked)
							selectedModel = square
					}
			}
			RadioButton {
					text: "triangle"
					onCheckedChanged: {
						if (checked)
							selectedModel = triangle
					}
			}
	}


	property var selectedModel: square;

	ListModel {
		id: triangle
		ListElement{px: 0.2; py: 0.4}
		ListElement{px: 0.5; py: 0.5}
		ListElement{px: 0.3; py: 0.9}
	}

	ListModel {
		id: square
		ListElement{px: 0.8; py: 0.1}
		ListElement{px: 0.9; py: 0.1}
		ListElement{px: 0.9; py: 0.3}
		ListElement{px: 0.8; py: 0.3}
	}


	//	Row
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

			function drawItem(ctx, model)
			{
				ctx.fillStyle = 'white'
				var size = 6
				var hhsize = size * 0.5

				ctx.beginPath()

				for (var j=0; j<model.count; j++) {

					var x = (model.get(j).px * width) - hhsize
					var y = (model.get(j).py * height) - hhsize

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

			onPaint: {
				var ctx = getContext('2d')
				ctx.clearRect(0, 0, width, height);
				drawItem(ctx, triangle)
				drawItem(ctx, square)
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

		Repeater {
			model: selectedModel

			ControlPoint {
				x: (px * canvas.width) - (width*0.5)
				y: (py * canvas.height) - (height*0.5)
				onPositionChanged: {
					var px = (x + (width*0.5)) / canvas.width
					var py = (y + (height*0.5)) / canvas.height
					//console.log(px + " " + py);

					selectedModel.get(index).px = px;
					selectedModel.get(index).py = py;

					canvas.requestPaint()
				}
			}
		}

	}

}


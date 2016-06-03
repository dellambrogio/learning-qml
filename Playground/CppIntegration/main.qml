import QtQuick 2.3
import QtQuick.Window 2.2
import com.mycompany.messaging 1.0

Window {
	visible: true
	width: 600
	height: 400


	Rectangle
	{
		Text {
			id: counter
			width: 100
			height: 100
			x: 100
			color: "blue"
			text: "0"
		}

	}

	Signaler {
		onCounterChanged: {
			console.log("New message received:", value)
			counter.text = value
		}
	}

	Rectangle {
		width: 100
		height: 100
		color: "green"
		Message {

		}
	}

	Rectangle {
		anchors.centerIn: parent
		width: 100
		height: 100
		color: "red"

		MessageBoard {

		}

	}



	ReMessage {
			text: "Amelie"
	}


}


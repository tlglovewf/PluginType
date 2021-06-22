import QtQuick 2.3
import TaoQuick 1.0
Rectangle {
    width: 860
    height: 600
    color: "red"

    Text {
        anchors.centerIn: parent
        text: "Hello, World!"
    }

	CusButton_Blue{
		width: 120
		height: 36
		text: "hello"
		onClicked:{
			labelpop.show()
		}
	}

	CusSwitch{
		x: 0
		y: 40
		width: 120
		height: 36
		text: "check"
	}

	CusListView{
		x:120
		y:0
		width: 120
		height: 30
	}
	CusSlider_Spin{
		x:120
		y:40
		width:120
		height: 30
	}
}

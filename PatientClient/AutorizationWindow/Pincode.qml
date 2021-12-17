import QtQml 2.12
import QtQml.Models 2.2
import QtQuick 2.12

PincodeForm {
    property string txt: ""
    signal pincodeEntered(string pin)
    Text{
        height: parent.height*0.1
        text: txt
        anchors{
            top: parent.top
            topMargin: height
            horizontalCenter: parent.horizontalCenter
        }
        font.pixelSize: height

    }
    property string pin: ""
    bt9{onClicked: if(pin.length<4){pin+="9"}}
    bt8{onClicked: if(pin.length<4){pin+="8"}}
    bt7{onClicked: if(pin.length<4){pin+="7"}}
    bt6{onClicked: if(pin.length<4){pin+="6"}}
    bt5{onClicked: if(pin.length<4){pin+="5"}}
    bt4{onClicked: if(pin.length<4){pin+="4"}}
    bt3{onClicked: if(pin.length<4){pin+="3"}}
    bt2{onClicked: if(pin.length<4){pin+="2"}}
    bt1{onClicked: if(pin.length<4){pin+="1"}}
    bt0{onClicked: if(pin.length<4){pin+="0"}}
    btX{onClicked: pin = pin.substring(0,pin.length-1)}
    btOk{visible: false;onClicked: {pincodeEntered(pin), pin = ""}}
    onPinChanged: {if(pin.length === 4){btOk.visible = true}else{btOk.visible = false}}

}

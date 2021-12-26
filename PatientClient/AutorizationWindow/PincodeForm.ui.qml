import QtQuick 2.15

import QtGraphicalEffects 1.15

Rectangle {
    id: root
    width: 450
    height: 800
    property alias bt9: bt9
    property alias bt8: bt8
    property alias bt7: bt7
    property alias bt6: bt6
    property alias bt5: bt5
    property alias bt4: bt4
    property alias bt3: bt3
    property alias bt2: bt2
    property alias bt1: bt1
    property alias btX: btX
    property alias bt0: bt0
    property alias dots: dots
    property alias btOk: btOk
    property alias buttons: buttons
    color: "skyblue"
    ListView{
        id: dots
        property int dotSize: 10
        anchors{
            horizontalCenter: parent.horizontalCenter
            bottom: buttons.top
            bottomMargin: height*5
        }
        height: dotSize
        width: (dotSize)*4+spacing*3
        delegate: Rectangle{
            id:dotDelegate
            height: dots.dotSize
            width: height
            radius: height/2
            color: "gray"
            visible: pin.length>=(index+1)?true:false

        }
        interactive: false
        spacing: dotSize*2
        orientation: ListView.Horizontal
        model: ListModel{
            ListElement{num:1}
            ListElement{num:2}
            ListElement{num:3}
            ListElement{num:4}
        }
    }

    Grid{
        id:buttons       
        anchors{
            left: parent.left
            right: parent.right
            leftMargin: parent.width*0.1
            rightMargin: parent.width*0.1
           // horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
            bottomMargin: parent.height*0.1
        }
        property int buttonHeight: width*0.29
        height: buttonHeight*4+spacing*3

        columns: 3
        spacing:(width-buttonHeight*3)/2

        layoutDirection:  GridView.RightToLeft
        RoundButton{id:bt9;width: parent.buttonHeight;height: width;text:"9"}
        RoundButton{id:bt8;width: parent.buttonHeight;height: width;text:"8"}
        RoundButton{id:bt7;width: parent.buttonHeight;height: width;text:"7"}
        RoundButton{id:bt6;width: parent.buttonHeight;height: width;text:"6"}
        RoundButton{id:bt5;width: parent.buttonHeight;height: width;text:"5"}
        RoundButton{id:bt4;width: parent.buttonHeight;height: width;text:"4"}
        RoundButton{id:bt3;width: parent.buttonHeight;height: width;text:"3"}
        RoundButton{id:bt2;width: parent.buttonHeight;height: width;text:"2"}
        RoundButton{id:bt1;width: parent.buttonHeight;height: width;text:"1"}
        RoundButton{id:btX;width: parent.buttonHeight;height: width;text:"X"}
        RoundButton{id:bt0;width: parent.buttonHeight;height: width;text:"0"}
        RoundButton{id:btOk;width: parent.buttonHeight;height: width;text:"Ok"}

    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}D{i:1}D{i:2}D{i:3}D{i:4}
}
##^##*/


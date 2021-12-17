import QtQuick 2.0
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.12
Button{
    id: root
    background: Rectangle{
        id:bt
        property string text: ""
        width: root.height
        height: root.width
        radius: width/2
        color: "white"
        Text {
            text: bt.text
            anchors.fill: parent
            horizontalAlignment: Text.horizontalCenter
            font.pixelSize: parent.height/3
        }

    }

    MouseArea{
        enabled: true
        anchors.fill: parent
        onPressed: {
            bt.color = "#FFACACAC"
            shadow.horizontalOffset = 4
            shadow.verticalOffset = 4
        }
        onContainsMouseChanged: {
            if(containsMouse == false){
                bt.color = "white"
                shadow.horizontalOffset = 5
                shadow.verticalOffset = 5
            }
        }
        onReleased: {
            bt.color = "white"
            shadow.horizontalOffset = 5
            shadow.verticalOffset = 5
            if(containsMouse == true){
                root.clicked()
            }
        }
    }
    DropShadow{
        id:shadow
        anchors.fill: bt
        source: bt
        horizontalOffset: 5
        verticalOffset: 5
        samples: 5
        color: "#80000000"
        radius: 5
    }
}
/*##^##
Designer {
    D{i:0;formeditorZoom:1.75}D{i:1}
}
##^##*/

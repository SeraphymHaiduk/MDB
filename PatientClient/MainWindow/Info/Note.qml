import QtQuick 2.0

Rectangle{
    width: 400
    height: 100
    color: "skyblue"
    property string dateStr
    property string doctorStr
    property string complaintsStr
    property string conclusionStr
    property string referralStr

    Text{
        id:dateText
        anchors{
            top: parent.top
            left: parent.left
            margins: 5
        }
        text: dateStr
    }
    Text{
        id:doctorText
        anchors{
            verticalCenter: dateText.verticalCenter
            right: parent.right
        }
        text: "Врач "+ doctorStr
    }
    Column{
        anchors{
            bottom:parent.bottom
            left: parent.left
            right: parent.right
            top: dateText.bottom
        }
        Text{
            id: complaintsText
            anchors{
                horizontalCenter: parent.horizontalCenter
            }
            text:"Жалобы "+complaintsStr
        }
        Text{
            id: conclusionText
            anchors{
                horizontalCenter: parent.horizontalCenter
            }
            text:"Предварительное заключение "+conclusionStr
        }
        Text{
            id: referralText
            anchors{
                horizontalCenter: parent.horizontalCenter
            }
            text:"Направление "+referralStr
        }


    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/

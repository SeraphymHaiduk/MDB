import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.2

Item {
    id: root
    width: 360
    height: 600
    property string name1: ""
    property string name2: ""
    property string name3: ""
    property string uuid: ""
    property string sex: ""
    property string date: ""
    property string image: ""
    property alias profileRectangle: profileRectangle
    property alias list:list
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent
        SwipeView{
            anchors.fill: parent
            Item {
                id: profile
                Rectangle {
                    id: profileRectangle
                    height: text3.y  + text3.height + 25
                    anchors {
                        fill: parent
                        margins: 8
                    }
                    radius: 25
                    color: "#d3d7cf"
                    Image {
                        id: borderImage
                        source: image
                        layer.enabled: false
                        anchors {
                            horizontalCenter: parent.horizontalCenter
                            topMargin: 10
                            top: parent.top
                        }
                        height: root.height / 4
                        width: height
                    }

                    Rectangle {
                        id: separatorRect1
                        anchors {
                            top: borderImage.bottom
                            left: parent.left
                            right: parent.right
                            margins: 10
                        }
                        height: 2
                        color: "#ffffff"
                    }
                    Text {
                        id: text1
                        anchors {
                            top: separatorRect1.bottom
                            left: parent.left
                            right: parent.horizontalCenter
                            topMargin: 10
                            leftMargin: 10
                        }
                        font.pixelSize: root.height * 0.03
                        height: font.pixelSize * 3
                        text: name1 + "\n" + name2 + "\n" + name3
                    }
                    Text {
                        id: text2
                        anchors {
                            left: text1.right
                            right: parent.right
                            rightMargin: 10
                            verticalCenter: text1.verticalCenter
                        }
                        width: text1.width
                        height: text1.height
                        text: "Пол " + sex + "\nДата\n" + date
                        font.pixelSize: root.height * 0.03
                        horizontalAlignment: Text.AlignRight
                    }

                    Rectangle {
                        id: separatorRect2
                        color: "#ffffff"
                        anchors {
                            top: text1.bottom
                            left: parent.left
                            right: parent.right
                            margins: 10
                        }
                        height: 2
                    }
                    Text {
                        id: text3
                        anchors {
                            top: separatorRect2.bottom
                            left: parent.left
                            right: parent.right
                            margins: 10
                        }
                        font.pixelSize: root.height * 0.03
                        text: "uuid: " + uuid
                    }
                }
            }
            Item {
                id: notation
                ListView{
                    id:list
                    width: parent.width
                    anchors{
                        fill:parent
                        leftMargin: 8
                        rightMargin: 8
                        topMargin: 8
                    }
                    spacing: 10

                    delegate: Note{
                        height: rectangle.height*0.1
                        width: list.width

                    }
                    model: ListModel{
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}
                        ListElement{}

                    }
                }
            }





        }





    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:4}D{i:5}D{i:6}D{i:7}D{i:8}D{i:9}D{i:3}D{i:10}D{i:2}
D{i:1}
}
##^##*/


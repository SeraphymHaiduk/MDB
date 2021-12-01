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
    property alias loadBt: loadBt
    property alias rectangle: rectangle
    property alias column: column
    property alias flickable: flickable
    property alias rootRect: rectangle
    Rectangle {
        id: rectangle
        anchors.fill: parent

        color: "#ffffff"
        Flickable {
            id: flickable
            anchors.fill: parent
            anchors.margins: 10
            contentHeight: column.height
            Column {
                id: column
                anchors {
                    left: parent.left
                    right: parent.right
                }
                spacing: 10
                Rectangle {
                    id: rectangle1
                    height: text3.y - rectangle1.y + text3.height + 25
                    anchors {
                        margins: 8
                        left: parent.left
                        right: parent.right
                    }
                    radius: 25
                    color: "#d3d7cf"

                    Image {
                        id: borderImage
                        source: "thisPersonDoesntExist.png"
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
                Button {
                    id: loadBt
                    height: root.height * 0.1
                    anchors {
                        left: parent.left
                        right: parent.right
                        margins: 10
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/


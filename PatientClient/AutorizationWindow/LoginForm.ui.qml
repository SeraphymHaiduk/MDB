import QtQuick 2.4
import QtQuick.Controls 2.12

Item {
    width: 400
    height: 600
    property alias button: button
    property alias mouseArea: mouseArea
    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Rectangle {
            id: rectangle11
            width: 262
            height: 56
            color: "#888a85"
            radius: 8
            anchors {
                top: parent.top
                topMargin: parent.height * 0.1
                horizontalCenter: parent.horizontalCenter
            }
            Rectangle {
                id: rectangle12
                color: "#d3d7cf"
                radius: 8
                anchors {
                    fill: parent
                    margins: 8
                }

                TextInput {
                    id: textInput
                    width: 80
                    height: 20
                    anchors.centerIn: parent
                    text: qsTr("Text Input")
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        Rectangle {
            id: rectangle21
            width: 262
            height: 56
            color: "#888a85"
            radius: 8
            anchors {
                top: rectangle11.bottom
                topMargin: rectangle21.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }
            Rectangle {
                id: rectangle22
                color: "#d3d7cf"
                radius: 8
                anchors {
                    fill: parent
                    margins: 8
                }
                TextInput {
                    id: textInput1
                    width: 80
                    height: 20
                    anchors.centerIn: parent
                    text: qsTr("Text Input")
                    echoMode: TextInput.Password
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }

        Button {
            id: button
            text: qsTr("Login")
            anchors {
                top: rectangle21.bottom
                topMargin: rectangle21.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }

        }

        MouseArea {
            id: mouseArea
            y: 268
            width: 205
            height: 27
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: text1
                width: 74
                height: 21
                text: qsTr("Text")
                font.pixelSize: 12
                anchors {
                    fill: parent
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}D{i:4}D{i:3}D{i:2}D{i:7}D{i:6}D{i:5}D{i:8}D{i:10}D{i:9}
D{i:1}
}
##^##*/


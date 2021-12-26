import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Item {
    width: 400
    height: 600
    property alias button: button
    property alias mouseArea: mouseArea
    property alias uuidText: uuidInput.text
    property alias passwordText: passwordInput.text
    property alias btPatient: btPatient
    property alias btMedWorker: btMedWorker
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
                    id: uuidInput
                    width: 80
                    height: 20
                    anchors.centerIn: parent
                    text: qsTr("20634322535")
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
                    id: passwordInput
                    width: 80
                    height: 20
                    anchors.centerIn: parent
                    text: qsTr("1122334455")
                    echoMode: TextInput.Password
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
        ColumnLayout {
            id: column
            spacing: rectangle21.height * 0.1
            anchors {
                top: rectangle21.bottom
                topMargin: rectangle21.height * 0.4
                horizontalCenter: parent.horizontalCenter
                //    horizontalCenterOffset: -rectangle21.width / 2 + width / 2
            }
            RadioButton {
                id: btPatient
                text: "Я пациент"
            }
            RadioButton {
                id: btMedWorker
                text: "Я мед. работник"
            }
        }

        Button {
            id: button
            text: qsTr("Login")
            anchors {
                top: column.bottom
                topMargin: rectangle21.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }
        }

        MouseArea {
            id: mouseArea
            width: 205
            height: 27
            anchors {
                top: button.bottom
                topMargin: rectangle21.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }
            Text {
                id: text1
                width: 74
                height: 21
                text: qsTr("Sign up")
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
    D{i:0;formeditorZoom:1.25}D{i:4}D{i:3}D{i:2}D{i:7}D{i:6}D{i:5}D{i:9}D{i:10}D{i:8}
D{i:11}D{i:13}D{i:12}D{i:1}
}
##^##*/


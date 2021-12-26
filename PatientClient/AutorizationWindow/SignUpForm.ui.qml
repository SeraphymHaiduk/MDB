import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
Item {
    width: 400
    height: 400
    property alias signUpBt: signUpBt
    property alias nameInput: nameInput
    property alias surnameInput: surnameInput
    property alias patronymicInput: patronimycInput
    property alias passwordInput: passwordInput
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
                topMargin: parent.height * 0.05
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
                    id: nameInput
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
                    id: surnameInput
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
            id: rectangle31
            width: 262
            height: 56
            color: "#888a85"
            radius: 8
            anchors {
                top: rectangle21.bottom
                topMargin: rectangle31.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }
            Rectangle {
                id: rectangle32
                color: "#d3d7cf"
                radius: 8
                anchors {
                    fill: parent
                    margins: 8
                }
                TextInput {
                    id: patronimycInput
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
            id: rectangle41
            width: 262
            height: 56
            color: "#888a85"
            radius: 8
            anchors {
                top: rectangle31.bottom
                topMargin: rectangle31.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }
            Rectangle {
                id: rectangle42
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
                    text: qsTr("Text Input")
                    echoMode: TextInput.Password
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                }
            }
        }
        ColumnLayout {
            id: column
            spacing: rectangle41.height * 0.1
            anchors {
                top: rectangle41.bottom
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
        Button{
            id:signUpBt
            anchors {
                top: column.bottom
                topMargin: rectangle41.height * 0.4
                horizontalCenter: parent.horizontalCenter
            }
        }


}

}

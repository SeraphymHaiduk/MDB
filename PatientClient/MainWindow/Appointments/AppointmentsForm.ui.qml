import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 360
    height: 600

    Rectangle {
        id: rectangle
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        color: "#ffffff"

        ListView {
            id: listView
            spacing: 20
            anchors.fill: parent
            anchors.topMargin: 10
            delegate: Button {
                id: rect1
                height: 100
                width: parent.width
                flat: true
                anchors {
                    left: parent.left
                    right: parent.right
                    leftMargin: 10
                    rightMargin: 10
                }
                Text {
                    anchors.centerIn: rect1
                    text: labelText
                }
            }
            model: ListModel {
                ListElement {
                    labelText: "Консультация у терапевта"
                }
                ListElement {
                    labelText: "Получить справку"
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

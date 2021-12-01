import QtQuick 2.4

Item {
    width: 360
    height: 600

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#ffffff"

        Text {
            id: text1
            x: 168
            y: 199
            text: qsTr("Recipes")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}

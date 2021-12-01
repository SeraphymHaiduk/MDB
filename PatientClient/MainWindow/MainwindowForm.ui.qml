import QtQuick 2.4
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 360
    height: 640
    property string loaderSource: "Info/Info.qml"

    property alias menuButton: menuButton
    property alias shadeArea: shadeArea
    property alias shade: shade
    property alias leftMenu: leftMenu

    property alias infoBt: infoBt
    property alias appointmentsBt: appointmentsBt
    property alias recipesBt: recipesBt

    property bool leftMenuShow: false
    property bool menuStarted: false
    Page {
        id: page
        anchors.fill: parent
        Loader {
            id: loader
            anchors {
                top: toolBar.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            source: loaderSource
        }
        ToolBar {
            id: toolBar
            height: 40
            position: ToolBar.Header
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors {
                left: parent.left
                right: parent.right
            }
            Button {
                id: menuButton
                enabled: leftMenuShow ? false : true
                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                }
                width: height
                flat: true
                clip: true
                Text {
                    text: qsTr('≡')
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: parent.height * 1.2
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "white"
                }
            }
        }
    }
    Rectangle {
        id: shade
        anchors.fill: item1
        color: "#ff000000"
        opacity: leftMenuShow ? 0.5 : 0
        MouseArea {
            id: shadeArea
            anchors.fill: parent
            anchors.leftMargin: leftMenu.width
            enabled: leftMenuShow ? true : false
        }
    }
    Item {
        id: leftMenu
        width: item1.width * 0.7
        height: item1.height
        anchors {
            right:  item1.left
            rightMargin: leftMenuShow ? -width : 0
        }
        Rectangle {
            anchors.fill: parent
            color: "#d3d7cf"

            Column {
                id: row
                height: leftMenu.height - toolBar.height
                anchors {
                    bottom: parent.bottom
                    left: parent.left
                    right: parent.right
                }
                Button {
                    id: infoBt
                    width: parent.width
                    height: toolBar.height
                    flat: true
                    text: "Мед карта"
                }
                Button {
                    id: appointmentsBt
                    width: parent.width
                    height: toolBar.height
                    flat: true
                    text: "Направления"
                }
                Button {
                    id: recipesBt
                    width: parent.width
                    height: toolBar.height
                    flat: true
                    text: "Рецепты"
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


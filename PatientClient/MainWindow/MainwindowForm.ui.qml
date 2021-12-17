import QtQuick 2.4
import QtQuick.Controls 2.15

Item {
    id: item1
    width: 360
    height: 640
    property string loaderSource: "Info/Info.qml"


    property alias infoBt: infoBt
    property alias appointmentsBt: appointmentsBt
    property alias recipesBt: recipesBt

    Page {
        id: page
        anchors.fill: parent
        clip: true
        Loader {
            id: loader
            anchors {
                fill: parent
            }
            source: loaderSource
        }
        header: ToolBar {
            id: toolBar
            height: 40
            position: ToolBar.Header
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors {
                left: parent.left
                right: parent.right
            }

        }

        footer: ToolBar{
            id: footerToolbar
            height: 40
            position: ToolBar.Footer
            Row{
                anchors.fill: parent
                Button {
                    id: infoBt
                    width: parent.width/3
                    height: footerToolbar.height
                    flat: true
                    text: "Мед карта"
                }
                Button {
                    id: appointmentsBt
                    width: parent.width/3
                    height: footerToolbar.height
                    flat: true
                    text: "Направления"
                }
                Button {
                    id: recipesBt
                    width: parent.width/3
                    height: footerToolbar.height
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


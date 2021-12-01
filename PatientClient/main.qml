import QtQuick 2.15
import QtQuick.Window 2.15
import "MainWindow"
Window {

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Mainwindow{
        anchors.fill: parent

    }
}

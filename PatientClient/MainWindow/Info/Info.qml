import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
InfoForm {
    anchors.fill: parent
    function addNotes(){ //добавление записей (изменить)
        if(!notesVisible){
            notesVisible = true
            btText.text = "Скрыть записи"
            var component
            var note
            component = Qt.createComponent("Note.qml")
            if(component.status === Component.Ready){
                note = component.createObject(column)
            }
        }
        else{
            notesVisible = false
            btText.text = "Показать записи"
        }
    }
    property bool notesVisible: false
    name1: "Бекмамбетов"
    name2: "Айнур"
    name3: "Адольфович"
    loadBt {
        onPressed: {
            addNotes()
        }
        background: Rectangle {
            height: parent.height
            radius: 10

            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: loadBt.pressed ? "#ccc" : "#eee"
                }
                GradientStop {
                    position: 1
                    color: loadBt.pressed ? "#aaa" : "#ccc"
                }
            }
            Text {
                id: btText
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
                text: "Показать записи"
                font.pixelSize: rootRect.height*0.03
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/

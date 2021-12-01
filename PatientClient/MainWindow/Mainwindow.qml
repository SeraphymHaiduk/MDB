import QtQuick 2.4
import "Info/"
MainwindowForm {
    Connections{
        target: menuButton
        function onClicked() {
            leftMenuShow = true
            leftMenu.visible = true
        }
    }
    Connections{
        target: shadeArea
        function onClicked(){
            leftMenuShow = false
        }
    }
    shade{
        Behavior on opacity { OpacityAnimator{ duration: 200}}
    }
    leftMenu{
        Behavior on anchors.rightMargin {NumberAnimation{duration: 200}}
    }
    infoBt{
        onClicked: {
            loaderSource = "Info/Info.qml"
            leftMenuShow = false
        }
    }
    recipesBt{
        onClicked: {
            loaderSource = "Recipes/Recipes.qml"
            leftMenuShow = false
        }
    }
    appointmentsBt{
        onClicked: {
            loaderSource = "Appointments/Appointments.qml"
            leftMenuShow = false
        }
    }

}

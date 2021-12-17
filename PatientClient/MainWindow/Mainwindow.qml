import QtQuick 2.4
import "Info/"
MainwindowForm {
    infoBt{
        onClicked: {
            loaderSource = "Info/Info.qml"
        }
    }
    recipesBt{
        onClicked: {
            loaderSource = "Recipes/Recipes.qml"
        }
    }
    appointmentsBt{
        onClicked: {
            loaderSource = "Appointments/Appointments.qml"
        }
    }

}

import QtQuick 2.4

LoginForm {
    signal signUpClicked()
    signal loginClicked()
    mouseArea {
        onClicked: {
            signUpClicked()
        }
    }
    button{
        onClicked: {
            loginClicked()
        }
    }
}

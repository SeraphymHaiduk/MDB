import QtQuick 2.4

LoginForm {
    id: root
    signal signUpClicked()
    signal loginClicked(string uuid, string password, string client_type)
    mouseArea {
        onClicked: {
            signUpClicked()
        }
    }
    button{
        onClicked: {
            if(btMedWorker.checked || btPatient.checked){
                root.loginClicked(uuidText,passwordText,btMedWorker.checked?"DOCTOR":"PATIENT")
            }
        }
    }
}

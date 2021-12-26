import QtQuick 2.4
import QtQuick.Controls 2.12
SignUpForm {
    signal signUpClicked(string name,string surname,string patronymic,string password,string client_type)
    signUpBt {
        onClicked: {
            signUpClicked(nameInput.text,surnameInput.text,patronymicInput.text,passwordInput.text,btMedWorker.checked?"DOCTOR":"PATIENT")
        }
    }
}

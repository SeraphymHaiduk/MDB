import QtQuick 2.4

AuthorizationWindowForm{
    id:root
    signal signUpClicked(string name, string surname, string patronymic, string password,string client_type)
    signal loginClicked(string uuid, string password,string client_type)
    Loader{
        id:authLoader
        sourceComponent: loginComponent
        anchors.fill: parent
    }
    Component{
        id:loginComponent
        Login{
            onLoginClicked: {
                root.loginClicked(uuid,password,client_type)
            }
            onSignUpClicked: {
                authLoader.sourceComponent = signUpComponent
            }
        }
    }
    Component{
        id:signUpComponent
        SignUp{
            id:signUp
            onSignUpClicked: {
                root.signUpClicked(name,surname,patronymic,password,client_type)
            }
        }
    }

}

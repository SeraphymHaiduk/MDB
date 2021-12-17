import QtQuick 2.15
import QtQuick.Window 2.15
import "MainWindow"
import "AutorizationWindow/"
import RequestHandler 1.0
import LocalConfig 1.0
Window {
    id:main
    width: 450
    height: 800
    visible: true
    title: qsTr("Hello World")
    Loader{
        id:mainLoader
        anchors.fill: parent
        sourceComponent: loginComponent
        property string pincodeMessadge: pincodeNew?"Придумайте пинкод":"Введите пинкод"
        property bool pincodeNew: false
        property string pincodeBuf: ""
    }
    Component{
        id:autorizationComponent
        AuthorizationWindow{

        }
    }
    Component{
        id:loginComponent
        Login{
            onLoginClicked: {
                console.log("LoginClicked")
            }
            onSignUpClicked: console.log("SignUpClicked")
        }
    }
    Component{
        id:pincodeComponent
        Pincode{
            id:pincode
            txt: mainLoader.pincodeMessadge
            Component.onCompleted: {
                pincode.pincodeEntered.connect(foo)
            }
        }

    }
    function foo(pin){
        if(mainLoader.pincodeNew){
            if(mainLoader.pincodeBuf.length>0){
                if(pin == mainLoader.pincodeBuf){
                 //localConfig.setConfigProperties()   сделать нормально
                    mainLoader.sourceComponent = mainWindowComponent
                }
                else{
                    console.log("pincode not repeated") //cделать нормальное уведомление о неповторившемся пинкоде
                }
            }
            else{
                mainLoader.pincodeBuf = pin
            }


        }
        else{
            //запрос пинкода из конфига
            //если совпадает, то пропустить, если нет, то сообщить о не неверном пароле
        }

    }
    Component{
        id:mainWindowComponent
        Mainwindow{

        }
    }
    property string params: "ABOBA"
    Handler{
        id:handler
    }
    LocalConfig{
        id:localConfig
    }

    Component.onCompleted: {
        handler.send(params)
        if(localConfig.getActualToken() === "none"){
            mainLoader.source = "AutorizationWindow/Login.qml"
        }
        handler.send("SIGN_UP CLIENT_TYPE PATIENT NAME Valeriy SURNAME Zelensky PATRONYMIC Antonovich PASSWORD 1122334455")

    }
    Connections{
        target: handler
        function onSignUpDataReceived(uuid,access_tk,refresh_tk,date){
            console.log(uuid+" "+access_tk+" "+refresh_tk+" "+date)
            mainLoader.sourceComponent = pincodeComponent
            mainLoader.pincodeNew = true



        }
    }

}

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
        sourceComponent: authComponent
        property string pincodeMessadge: ""
        property bool pincodeNew: false
        property string pincodeBuf: ""

    }
    Component{
        id:authComponent
        AuthorizationWindow{
            onSignUpClicked: {
                handler.send("SIGN_UP CLIENT_TYPE %1 NAME %2 SURNAME %3 PATRONYMIC %4 PASSWORD %5".arg(client_type).arg(name).arg(surname).arg(patronymic).arg(password))
                localConfig.setConfigProperties({"password":password})
            }
            onLoginClicked: {
                handler.send("LOGIN CLIENT_TYPE %1 UUID %2 PASSWORD %3".arg(client_type).arg(uuid).arg(password))
                localConfig.setConfigProperties({"uuid":uuid,"password":password})
            }
        }
    }

    Component{
        id:newPincodeComponent
        Pincode{
            id:newPincode
            txt: mainLoader.pincodeMessadge
            onBackPressed: {
                pin = ""
                mainLoader.pincodeBuf = ""
                mainLoader.pincodeMessadge = "Придумайте пинкод"
            }
            Component.onCompleted: {
                newPincode.pincodeEntered.connect(newPinEntered)
                mainLoader.pincodeMessadge = "Придумайте пинкод"
            }
        }

    }
    function newPinEntered(pin){
        if(mainLoader.pincodeBuf.length>0){
            if(pin === mainLoader.pincodeBuf){
                localConfig.setConfigProperties({"pincode":pin})
                mainLoader.sourceComponent = mainWindowComponent
            }
            else{
                mainLoader.pincodeMessadge = "Код не совпадает"
            }
        }
        else{
            mainLoader.pincodeBuf = pin
            mainLoader.pincodeMessadge = "повторите пароль"
        }
    }
    Component{
        id:pincodeComponent
        Pincode{
            id:pincode
            txt:mainLoader.pincodeMessadge
            onBackPressed: {
                mainLoader.sourceComponent = authComponent
            }
            Component.onCompleted: {
                pincode.pincodeEntered.connect(checkPin)
                mainLoader.pincodeMessadge = "Введите пинкод"
                backBt.text = "войти в другой аккаунт"

            }
        }
    }

    function checkPin(pin){
        arr = localConfig.getConfigProperties()
        if(arr["pincode"]===pin){
            mainLoader.sourceComponent = mainWindowComponent
        }
    }
    Component{
        id:mainWindowComponent
        Mainwindow{
            id: mainWindow
            property variant config

        Component.onCompleted: {
            config = localConfig.getConfigProperties()
            handler.send("%1 GET PROFILE_PROPS UUID %2 CLIENT_TYPE %3"
                         .arg(config["access_token"])
                         .arg(config["uuid"])
                         .arg(config["client_type"]))
            handler.send("%1 GET VISITS_HISTORY UUID %2 CLIENT_TYPE %3"
                         .arg(config["access_token"])
                         .arg(config["uuid"])
                         .arg(config["client_type"]))
           handler.visitsHistoryReceived.connect(setPrms())
        }
        Connections{
            target: handler
            function onProfilePropsReceived(name,surname,patronymic){
                mainWindow.config = localConfig.getConfigProperties()
                mainWindow.name = name
                mainWindow.surname = surname
                mainWindow.patronymic = patronymic
                mainWindow.uuid = mainWindow.config["uuid"]

            }
            function onVisitsHistoryReceived(list,rowsNum,colsNum){
                mainWindow.rowCount = rowsNum
                mainWindow.colCount = colsNum
                mainWindow.visits = list
            }
        }
        }
    }

    Handler{
        id:handler
    }
    LocalConfig{
        id:localConfig
    }
    property variant loginInfo
    property variant arr
    Component.onCompleted: {
        loginInfo = localConfig.getLoginProperties()
        if(loginInfo["uuid"] === "none" || loginInfo["password"] === "none"){
            mainLoader.sourceComponent = authComponent
// /*строка только для тестов*/handler.send("SIGN_UP CLIENT_TYPE PATIENT SURNAME Zelensky PATRONYMIC Antonovich PASSWORD 1122334455 NAME Valeriy")
        }
        else{//переработать - если нет access, то if(arr["refresh"]!== "none") send("'refresh_tk REFRESH'"), иначе - send("LOGIN ...")
            arr = localConfig.getActualToken()
            if(arr["access"]==="none"){
                handler.send("LOGIN CLIENT_TYPE %1 UUID %2 PASSWORD %3".arg(loginInfo["client_type"]).arg(loginInfo["uuid"]).arg(loginInfo["password"]))
            }
            else{
                arr = localConfig.getConfigProperties()
                if(arr["pincode"] === "" || arr["pincode"] === undefined){
                    mainLoader.sourceComponent = newPincodeComponent
                }
                else{
                    mainLoader.sourceComponent = pincodeComponent
                }
            }
        }
        /*
        else if(arr["pincode"] === ""){//Сделать, чтобы сначала отправлялся Login запрос, а потом переключать на пинкод
            mainLoader.sourceComponent = newPincodeComponent
        }
        else{
            mainLoader.sourceComponent = pincodeComponent
        }*/

    }
    Connections{
        target: handler
        function onSignUpDataReceived(uuid,access_tk,refresh_tk,date,client_type){
            arr = {"uuid":uuid,
                "access_token":access_tk,
                "refresh_token":refresh_tk,
                "access_date":date,
                "refresh_date":date,
                "client_type":client_type,
                "pincode":""}
            localConfig.setConfigProperties(arr)
            mainLoader.sourceComponent = newPincodeComponent
        }
        function onLoginDataRecieved(access_tk,refresh_tk,date,client_type){
            arr = localConfig.getConfigProperties()
            if(arr["pincode"] === ""||arr["pincode"] === undefined){
                mainLoader.sourceComponent = newPincodeComponent
            }
            else {
                mainLoader.sourceComponent = pincodeComponent
            }
            arr = {"access_token":access_tk,
                    "refresh_token":refresh_tk,
                    "refresh_date":date,
                    "access_date":date,
                    "client_type":client_type,
                    }
            localConfig.setConfigProperties(arr)

        }
    }
}

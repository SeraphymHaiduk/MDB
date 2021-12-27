import QtQuick 2.4
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
InfoForm {
    function setElement(a){
        listmodel.append(a)
        console.log("aas2")
    }
    anchors.fill: parent
    name1: "Бекмамбетов"
    name2: "Айнур"
    name3: "Адольфович"
    image: "thisPersonDoesntExist.png"
    uuid: "11111testUUID"
    //sex: "m"
    //date: "10.07.1985"
    swipeView{

    }


}



/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.75;height:480;width:640}
}
##^##*/

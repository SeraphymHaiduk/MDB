import QtQuick 2.4
import QtQml 2.12
import QtQuick.Controls 2.12
import "Info"
import "Recipes"
import "Appointments"
MainwindowForm {
    id: root
    property variant visits
    property int rowCount
    property int colCount

    property string name: "имя"
    property string surname: "Фамилия"
    property string patronymic: "Отчество"
    property string uuid: ""
    infoBt{
        onClicked: {
            loader.sourceComponent = infoComponent
        }
    }
    recipesBt{
        onClicked: {
            loader.sourceComponent = recipesComponent
        }
    }
    appointmentsBt{
        onClicked: {
            loader.sourceComponent = appointmentsComponent
        }
    }
    loader {}

    Component{
        id:recipesComponent
        Recipes{

        }
    }
    Component{
        id:appointmentsComponent
        Appointments{

        }
    }
    Component {
        id:infoComponent
        Info{
            id:info
            name1: root.surname
            name2: root.name
            name3: root.patronymic
            uuid: root.uuid
            property variant tmp:[]
            Connections{
                target: root

                function onVisitsChanged(){
                    console.log("aaaaas",root.rowCount,root.colCount)
                    for(var i = 0;i < root.rowCount;i++){
                        for(var j = 0; j < root.colCount; j++){
                            tmp.push(visits[i*root.colCount+j])
                        }
                        console.log(tmp)
                        info.setElement({  "date":tmp[0],
                                             "doctor":tmp[1],
                                             "complaints":tmp[2],
                                             "conclusion":tmp[3],
                                             "referral":tmp[4]
                                         })
                        tmp = []

                    }
                }
            }
        }
    }

}

#include "localconfig.h"
#include <QSqlDatabase>
#include <QStandardPaths>
#include <QDebug>
#include <QSqlError>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
LocalConfig::LocalConfig(QObject* parent) :QObject(parent)
{

}
void LocalConfig::setConfigProperties(QVariantMap values){
    QMap<QString,QVariant>::key_iterator iter = values.keyBegin();

    QFile file("test.json");
    file.open(QIODevice::ReadWrite);
    QJsonDocument jd(QJsonDocument::fromJson((file.readAll())));
    QJsonObject jo = jd.object();
    file.seek(0);
    while(iter!=values.keyEnd()){
        jo[*iter] =  values[*iter].toString();
    }
    file.write(QJsonDocument(jo).toJson());
    file.close();
}

QVariantMap LocalConfig::getConfigProperties(){
    QFile file(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)+"patientClientconfig.json");

    QVariantMap map;
    if(file.open(QIODevice::ReadOnly)){
        QJsonDocument jd(QJsonDocument::fromJson(file.readAll()));
        QJsonObject jo = jd.object();
        QStringList list = jo.keys();
        for(int i = 0; i < list.length();i++){
            map[list[i]] = jo[list[i]].toString();
        }
        file.close();
    }
    else{
        qDebug() << "file Error: "+file.errorString();
    }

    return map;
}

QString LocalConfig::getActualToken(){
    QFile file(QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)+"patientClientconfig.json");
    if(!file.open(QIODevice::ReadOnly)){
        return "none";
    }
    QJsonDocument jd(QJsonDocument::fromJson(file.readAll()));
    QJsonObject jo = jd.object();
    QDate date = QDate::currentDate();
    if(date<QDate::fromString((jo["access_date"].toString(),"dd-MM-yyy"))){
        return jo["access_date"].toString();
    }
    else if (date<QDate::fromString((jo["refresh_date"].toString(),"dd-MM-yyy"))) {
        return jo["refresh_date"].toString();
    }
    else {
        return "none";
    }
}

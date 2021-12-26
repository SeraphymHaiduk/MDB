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
    qDebug() << values;
    qDebug() << "set props";
    QVariantMap::iterator iter = values.begin();

//    qDebug() << "set props 1";
    QFile file("test.json");

    file.open(QIODevice::ReadWrite);
    QJsonDocument jd(QJsonDocument::fromJson((file.readAll())));
    QJsonObject jo = jd.object();
    file.seek(0);
    while(iter!=values.end()){
        jo[iter.key()] =  iter.value().toString();
//        qDebug() << "input" << jo[iter.key()];
        iter++;
    }
    file.write(QJsonDocument(jo).toJson());
    file.close();
}

QVariantMap LocalConfig::getConfigProperties(){
    QFile file("test.json"/*QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)+"patientClientconfig.json"*/);
    QVariantMap map;
    if(file.open(QIODevice::ReadOnly)){
        QJsonDocument jd(QJsonDocument::fromJson(file.readAll()));
        QJsonObject jo = jd.object();
        QStringList list = jo.keys();
        foreach(QString s, list){
            map[s] = jo[s].toString();
        }
        file.close();
    }
    else{
        qDebug() << "file Error: "+file.errorString();
    }
    return map;
}
QVariantMap LocalConfig::getLoginProperties(){
        QFile file("test.json");
        QVariantMap map;
        if(!file.open(QIODevice::ReadOnly)){
            map["uuid"] = "none";
            map["password"] = "none";
            return map;
        }
        QJsonDocument jd(QJsonDocument::fromJson(file.readAll()));
        QJsonObject jo = jd.object();
        map["uuid"] = (jo["uuid"] == QJsonValue::Undefined)?"none":jo["uuid"].toString();
        map["password"] = (jo["password"] == QJsonValue::Undefined)?"none":jo["password"].toString();
        return map;
}
QVariantMap LocalConfig::getActualToken(){//пока что проверяет только то, что дата сегодняшняя
    QFile file("test.json"/*QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)+"patientClientconfig.json"*/);
    QVariantMap map;
    if(!file.open(QIODevice::ReadOnly)){
        map["access_token"] = "none";
        map["refresh_token"] = "none";
        return map;
    }
    QJsonDocument jd(QJsonDocument::fromJson(file.readAll()));
    QJsonObject jo = jd.object();
    QDate date = QDate::currentDate();

    if(date==QDate::fromString(jo["access_date"].toString(),"dd-MM-yyyy")){
        map["access_token"] = jo["access_token"].toString();
    }
    else{
        map["access"] = "none";
    }
    if (date==QDate::fromString(jo["refresh_date"].toString(),"dd-MM-yyyy")) {
        map["refresh_token"] = jo["refresh_token"].toString();
    }
    else {
        map["refresh"] = "none";
    }
    return map;
}

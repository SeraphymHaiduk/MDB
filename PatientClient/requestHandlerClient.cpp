#include "requestHandlerClient.h"
#include <QHostAddress>
#include <QByteArray>
#include <QDataStream>
RequestHandlerClient::RequestHandlerClient(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost,2323);
    QObject::connect(socket,&QTcpSocket::connected,this,[=](){qDebug() << "connected";});
    QObject::connect(socket,&QTcpSocket::readyRead,this,[=](){this->receiveRequest(socket);});
}
void RequestHandlerClient::send(const QByteArray& params, const QByteArray& data){
    qDebug() << "data sended: " << params;
    QByteArray package;
    QDataStream out(&package,QIODevice::WriteOnly);
    out << (unsigned short int)params.size() << (unsigned short int)data.size();
    out.writeRawData(params, params.size());
    out.writeRawData(data, data.size());
    socket->write(package);
}
void RequestHandlerClient::receiveRequest(QTcpSocket *socket){
    QDataStream in(socket);
    if(requestDataSize == 0 || requestParamSize == 0){
            if(socket->bytesAvailable() < (int)sizeof(uint16_t)*2)
                return;
            in >> requestParamSize;
            in >> requestDataSize;
            qDebug() << "params size " <<requestParamSize;
            qDebug() << "data size " << requestDataSize;
    }
    if(!paramsWasRead){
        if(socket->bytesAvailable() < requestParamSize)
            return;
        paramsWasRead = true;
        if(requestParams.size()){
        requestParams.clear();
        }
        requestParams.resize(requestParamSize);
        in.readRawData(requestParams.data(),requestParamSize);
    }
    if(!dataWasRead){
        if(socket->bytesAvailable() < requestDataSize )
            return;
        dataWasRead = true;
        if(requestData.size()){
            requestData.clear();
        }
        requestData.resize(requestDataSize);
        in.readRawData(requestData.data(),requestDataSize);
    }
    requestParamSize = 0;
    requestDataSize = 0;
    paramsWasRead = false;
    dataWasRead = false;
    qDebug() << QString(requestParams).toUtf8(); //вывод входящих параметров
    interpret();
    if(socket->bytesAvailable()){
        emit socket->readyRead();
    }
}
void RequestHandlerClient::interpret(){
    QList<QString> params = QString(requestParams.data()).split(" ");
    QList<QString>::iterator it = params.begin();
    qDebug() << "interpreted";

    switch (Dict[*it++]) {
    case Commands::LOGIN_CONFIRM:{
        QMap<QString, QString*> values = {
            {"access_token",NULL},
            {"refresh_token",NULL},
            {"date",NULL},
            {"client_type",NULL}
        };
        while(it!=params.end()){
            switch (Dict[*it++]) {
            case Commands::ACCESS_TK:{
                qDebug() << "access_token" << *it;
                values["access_token"] = &(*it++);

                break;
            }
            case Commands::REFRESH_TK:{
                qDebug() << "refresh_token" << *it;
                values["refresh_token"] = &(*it++);
                break;
            }
            case Commands::DATE:{
                qDebug() << "date" << *it;
                values["date"] = &(*it++);
                break;
            }
            case Commands::CLIENT_TYPE:{
                qDebug() << "client_type" << *it;
                values["client_type"] = &(*it++);
                break;
            }
            }
        }
        QStringList lst = values.keys();
        int count = 0;
        foreach(QString s, lst){
            if(values[s]==NULL){
                qDebug() << QString("%1 is NULL").arg(s);
                count++;
            }
        }
        if(count>0){
            return;
        }
        emit loginDataRecieved(*values["access_token"],*values["refresh_token"],*values["date"],*values["client_type"]);
        break;
    }
    case Commands::SIGN_UP_CONFIRM:{
            switch (Dict[*it++]) {
            case Commands::ACCEPTED :{
                QMap<QString,QString*> values = {
                    {"uuid",NULL},
                    {"access_token",NULL},
                    {"refresh_token",NULL},
                    {"date",NULL},
                    {"client_type",NULL}
                };
                while(it!=params.end()){
                    switch (Dict[*it++]) {
                    case Commands::UUID:{
                        values["uuid"] = &(*it++);
                        break;
                    }
                    case Commands::ACCESS_TK:{
                        values["access_token"] = &(*it++);
                        break;
                    }
                    case Commands::REFRESH_TK:{
                        values["refresh_token"] = &(*it++);
                        break;
                    }
                    case Commands::DATE:{
                        values["date"] = &(*it++);
                        break;
                    }
                    case Commands::CLIENT_TYPE:{
                        qDebug() << "client_type" << *it;
                        values["client_type"] = &(*it++);
                        break;
                    }
                    }
                }
                QStringList lst = values.keys();
                int count = 0;
                foreach(QString s, lst){
                    if(values[s]==NULL){
                        qDebug() << QString("%1 is NULL").arg(s);
                        count++;
                    }
                }
                if(count>0){
                    return;
                }
                emit signUpDataReceived(*values["uuid"],*values["access_token"],*values["refresh_token"],*values["date"],*values["client_type"]) ;
                break;
            }
            case Commands::REJECTED:{
                qDebug() << QString("SIGN_UP_CONFIRM REJECTED cause: %1").arg(*it);
                return;
//                break;
            }
            }



    }
    }
}

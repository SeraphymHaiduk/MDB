#include "requesthandler.h"
#include <QObject>
#include <QTimer>
#include <QDataStream>
#include <random>
#include "time.h"
#include <QSqlError>
#include <QSqlQuery>
RequestHandler::RequestHandler(QObject *parent) : QObject(parent)
{
    usersDB = QSqlDatabase::addDatabase("QPSQL");

    server = new QTcpServer(this);
    QObject::connect(server,&QTcpServer::newConnection,this,[&]{this->connectUser(server);});
    if(!server->listen(QHostAddress::Any,2323)){
            qDebug() << QString("Problem with server creating: %1").arg(server->errorString());
    }
    usersDB.setHostName("127.0.0.1");
    usersDB.setUserName("seraphym");
    usersDB.setDatabaseName("test1_db");
    usersDB.setPassword("");
    if(!usersDB.open()){
        qDebug() << QString("usersDB error:%1").arg(usersDB.lastError().text());
    }


}
void RequestHandler::connectUser(QTcpServer *server){
    QTcpSocket *socket = server->nextPendingConnection();
    /*Добавить проверку access_token или refresh_token
     *В случае его отсутствия ограничить время работы подключения
    QTimer t;
    t.singleShot(5000,socket,[&]{
        socket->disconnectFromHost();
        socket->deleteLater();
    });
    */
    connect(socket,&QTcpSocket::readyRead,this,[&]{qDebug()<< "user connected";this->recieveRequest(socket);});
}
void RequestHandler::recieveRequest(QTcpSocket *socket){
    QDataStream in(socket);
    if(requestDataSize == 0 || requestParamSize == 0){
            if(socket->bytesAvailable() < (int)sizeof(uint16_t)*2)
                return;
            in >> requestParamSize;
            in >> requestDataSize ;
            qDebug() << "params size " <<requestParamSize;
            qDebug() << "data size " << requestDataSize;
    }
    if(!paramsWasRead){
        if(socket->bytesAvailable() < requestParamSize)
            return;
        paramsWasRead = true;
        requestParams.clear();
        in.readRawData(requestParams.data(),requestParamSize);
    }
    if(!dataWasRead){
        if(socket->bytesAvailable() < requestDataSize )
            return;
        dataWasRead = true;
        requestData.resize(requestDataSize);
        in.readRawData(requestData.data(),requestDataSize);
    }
    qDebug()<< "user connected";
    requestParamSize = 0;
    requestDataSize = 0;
    paramsWasRead = false;
    dataWasRead = false;
    interpret(socket);
}

void RequestHandler::interpret(QTcpSocket* socket){
    QList<QString> params = QString(requestParams.data()).split(" ");
    if((params[0] != "LOGIN")){
        //проверка токена
    }
    switch (Dict[params[0]]) {
        case Commands::GET_M_CARD_TITLE:{
            break;
        }
        case Commands::LOGIN:{ //проверить, совпадает ли имя, фамилия, отчество и пароль
            QString name = params[2];
            QString surname = params[3];
            QString patronymic = params[4];
            QString password = params[5];
            QString client_type;
            if(params[1] == "doctor"){
                client_type = "doctors";
            }
            else if(params[1] == "patient"){
                client_type = "patients";
        }
            QSqlQuery query;
            query.exec(QString("SELECT uuid, password FROM %1 WHERE name = %2 AND SURNAME = %3 AND PATRONYMIC = %4").arg(client_type, name,surname,patronymic));
            while(query.next()){
                if(password == query.value(1)){
                    //соз
                    //отправить их клиенту
                    break;
                }
            }
            break;
        }
        case Commands::FIND_DOCTOR:{
            break;
        }
        case Commands::GET_DOCTOR_INFO:{
            break;
        }
        default:{
            break;
        }
    }
}
void RequestHandler::sendData(QTcpSocket *socket, QString params, const QByteArray &data){
    unsigned short paramslen = params.length();
    unsigned short datalen = data.length();
    socket->write((char*)(&paramslen),sizeof(unsigned short));
    socket->write((char*)(&datalen),sizeof(unsigned short));
    socket->write(params.toUtf8(),paramslen);
    socket->write(data.data(),datalen);
}
QByteArray RequestHandler::generate_token(){
    srand(time(0));
    QByteArray token;
    token.append(rand());
    token.append(rand());
}

RequestHandler::~RequestHandler(){
    delete server;
}

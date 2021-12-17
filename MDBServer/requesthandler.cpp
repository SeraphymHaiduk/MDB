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
    patientDB = QSqlDatabase::addDatabase("QPSQL");

    server = new QTcpServer(this);
    QObject::connect(server,&QTcpServer::newConnection,this,[&]{this->connectUser(server);});
    if(!server->listen(QHostAddress::Any,2323)){
            qDebug() << QString("Problem with server creating: %1").arg(server->errorString());
    }
    patientDB.setHostName("127.0.0.1");
    patientDB.setUserName("medicalserver");
    patientDB.setDatabaseName("test1_db");
    patientDB.setPassword("password");
    if(!patientDB.open()){
        qDebug() << QString("patientDB error:%1").arg(patientDB.lastError().text());
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
    connect(socket,&QTcpSocket::readyRead,this,[=]{this->receiveRequest(socket);});
    qDebug() << "user connected ";
}
void RequestHandler::receiveRequest(QTcpSocket *socket){
    QDataStream in(socket);
    if(requestDataSize == 0 || requestParamSize == 0){
            if(socket->bytesAvailable() < (int)sizeof(uint16_t)*2)
                return;
            in >> requestParamSize;
            in >> requestDataSize ;
            qDebug() << "params size " <<requestParamSize;
            qDebug() << "data size " << requestDataSize;
    }
    qDebug() << "1 point";

    if(!paramsWasRead){
                qDebug() << "2 point";
        if(socket->bytesAvailable() < requestParamSize)
            return;
        paramsWasRead = true;
        qDebug() << "2.1 point";
        if(requestParams.size()){
            requestParams.clear(); //Вылет
        }
        qDebug() << "2.2 point";
        requestParams.resize(requestParamSize);
        in.readRawData(requestParams.data(),requestParamSize);
    }
    if(!dataWasRead){
        qDebug() << "3 point";
        if(socket->bytesAvailable() < requestDataSize )
            return;
        dataWasRead = true;
        if(requestData.size()){
            requestData.clear();
        }
        requestData.resize(requestDataSize);
        in.readRawData(requestData.data(),requestDataSize);
    }
    qDebug() << "4 point";
    requestParamSize = 0;
    requestDataSize = 0;
    paramsWasRead = false;
    dataWasRead = false;
  //  qDebug() << QString::fromStdString(requestParams.toStdString()); //print incoming params
    interpret(socket);
    if(socket->bytesAvailable()){
        emit socket->readyRead();
    }
}

void RequestHandler::interpret(QTcpSocket* socket){
    QStringList params = QString(requestParams.data()).split(" ");
    if(params[0]=="ABOBA"){
        qDebug() << "Получено";
        return;
    }
    if((params[0] != "LOGIN") && (params[0] != "SIGN_UP")){
        //проверка токена
    }

    QList<QString>::Iterator it = params.begin();
    switch (Dict[*it++]) {
    case Commands::GET_M_CARD_TITLE:{
        break;
    }
    case Commands::LOGIN:{ //проверить, совпадает ли имя, фамилия, отчество и пароль
        while(it != params.end()){
            switch (Dict[*it++]) {
            case Commands::CLIENT_TYPE:{

            break;
            }
            }
        }
        QString &client_type = params[1];
        QString &uuid = params[2];
        QString &password = params[3];

        QSqlQuery query;
        query.exec(QString("SELECT password FROM %1 WHERE uuid = '%2'").arg(client_type, uuid));
        while(query.next()){
            if(password == query.value(0)){

                query.exec(QString("UPDATE TABLE %1 SET "));
                //отправить их клиенту
                break;
            }
        }
        break;
    }
    case Commands::SIGN_UP:{
        QMap<QString,QString*> values = {
            {"client_type",NULL},
            {"name",NULL},
            {"surname", NULL},
            {"patronymic", NULL},
            {"password", NULL}
        };
        QSqlQuery q;
        while(it!=params.end()){
            switch (Dict[*it++]) {
            case Commands::CLIENT_TYPE:{
                values["client_type"] = &(*it++);
                break;
            }
            case Commands::NAME:{
                values["name"] = &(*it++);
                break;
            }
            case Commands::SURNAME:{
                values["surname"] = &(*it++);
                break;
            }
            case Commands::PATRONYMIC:{
                values["patronymic"] = &(*it++);
                break;
            }

            case Commands::PASSWORD:{
                values["password"] = &(*it++);
                break;
            }

            }
        }
        QList<QString> lst = values.keys();
        int count = 0;
        foreach(QString s, lst ){
            if(values[s] == NULL){
                send(socket,QString("%1 parameter is NULL").arg(s).toUtf8());
                count++;
            }
        }
        if(count>0){
            return;
        }
            srand(time(NULL));
            QString uuid = generate_token();
            q.prepare(QString("INSERT INTO %6(uuid,name,surname,patronymic,password)"
                              "VALUES('%1','%2','%3','%4','%5')").arg(  uuid,
                                                                        *values["name"],
                                                                        *values["surname"],
                                                                        *values["patronymic"],
                                                                        *values["password"],
                                                                        *values["client_type"]
                                                                        ));
            if(q.exec()){
                qDebug() << "signup started";
                QString access = generate_token();
                QString  refresh = generate_token();
                QDate date = QDate::currentDate();
                QString sDate = date.toString("dd-MM-yyyy");
                if(q.exec(QString("UPDATE PATIENT SET tokens = "
                               "tokens || '{\"access_token\":\"%1\",\"refresh_token\":\"%2\",\"access_date\":\"%3\",\"refresh_date\":\"%3\"}'::jsonb "
                               "WHERE uuid = '%4'").arg(access,refresh,sDate,uuid))){
                    send(socket,QString("SIGN_UP_CONFIRM ACCEPTED UUID %1 ACCESS_TK %2 REFRESH_TK %3 DATE %4").arg(uuid,access,refresh,sDate).toUtf8());
                }
                else{
                    qDebug() << q.lastError().text();
                }
            }
            else{
                send(socket,QString("SIGN_UP_CONFIRM REJECTED %1").arg(q.lastError().text()).toUtf8());
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
void RequestHandler::send(QTcpSocket *socket, const QByteArray &params, const QByteArray &data){
    qDebug() << "data sended " << params;
    QByteArray package;
    QDataStream out(&package,QIODevice::WriteOnly);
    out << (unsigned short int)params.size() << (unsigned short int)data.size();
    out.writeRawData(params, params.size());
    out.writeRawData(data, data.size());
    socket->write(package);
}
QString RequestHandler::generate_token(){
    long long a = rand();
    a = a << 4;
    a += rand();
    return QVariant(a).toString();
}

RequestHandler::~RequestHandler(){
    delete server;
}

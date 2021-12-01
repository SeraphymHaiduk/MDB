#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H
#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMap>
#include <QBuffer>
#include <QSqlDatabase>
#include <QtSql>
enum class Commands{
    GENERATE_TOKEN,
    LOGIN,
    SIGN_UP,
    GET_M_CARD_TITLE,
    FIND_DOCTOR,
    GET_DOCTOR_INFO,
};
class RequestHandler : public QObject
{
    Q_OBJECT
public slots:
    void connectUser(QTcpServer *server);
    void recieveRequest(QTcpSocket *socket);
public:
    RequestHandler(QObject *parent = 0);
    ~RequestHandler();
    void interpret(QTcpSocket *socket);
    void sendData(QTcpSocket *user,QString params, const QByteArray &data);
    QByteArray generate_token();
    void dbRequest(QString s);
private:
    QTcpServer *server;

    QByteArray requestParams;
    QByteArray requestData;

    QSqlDatabase usersDB;
    QSqlDatabase patientsDB;
    QSqlDatabase doctorsDB;



    uint16_t requestDataSize = 0;
    uint16_t requestParamSize = 0;
    bool paramsWasRead = false;
    bool dataWasRead = false;
    QMap<QString,Commands> Dict = {
        {"GENERATE_TOKEN",      Commands::GENERATE_TOKEN},
        {"LOGIN",               Commands::LOGIN},
        {"SIGN_UP",             Commands::SIGN_UP},
        {"GET_M_CARD_TITLE",    Commands::GET_M_CARD_TITLE},
        {"FIND_DOCTOR",         Commands::FIND_DOCTOR},
        {"GET_DOCTOR_INFO",     Commands::GET_DOCTOR_INFO},
    };
};


#endif // REQUESTHANDLER_H

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
    LOGIN,
    SIGN_UP,
    FIND_DOCTOR,
    GET_DOCTOR_INFO,
    CLIENT_TYPE,
    NAME,
    SURNAME,
    PATRONYMIC,
    PASSWORD,
    UUID,
    GET,
    PROFILE_PROPS,
};
class RequestHandler : public QObject
{
    Q_OBJECT
public slots:
    void connectUser(QTcpServer *server);
    void receiveRequest(QTcpSocket *socket);
public:
    RequestHandler(QObject *parent = 0);
    ~RequestHandler();
    void interpret(QTcpSocket *socket);
    void send(QTcpSocket *user,const QByteArray &params, const QByteArray &data = "");
    QString generate_token();
    void dbRequest(QString s);
private:
    QTcpServer *server;

    QByteArray requestParams;
    QByteArray requestData;

    QSqlDatabase patientDB;
    QSqlDatabase patientsDB;
    QSqlDatabase doctorsDB;

    bool fillParamsMap(QMap<QString,QString*> &map,QList<QString>::iterator &it,QList<QString>::iterator &&itEnd,QList<QString> params = {});

    uint16_t requestDataSize = 0;
    uint16_t requestParamSize = 0;
    bool paramsWasRead = false;
    bool dataWasRead = false;
    QMap<QString,Commands> Dict = {
        {"LOGIN",               Commands::LOGIN},
        {"SIGN_UP",             Commands::SIGN_UP},
        {"FIND_DOCTOR",         Commands::FIND_DOCTOR},
        {"GET_DOCTOR_INFO",     Commands::GET_DOCTOR_INFO},
        {"CLIENT_TYPE",         Commands::CLIENT_TYPE},
        {"NAME",                Commands::NAME},
        {"SURNAME",             Commands::SURNAME},
        {"PATRONYMIC",          Commands::PATRONYMIC},
        {"PASSWORD",            Commands::PASSWORD},
        {"UUID",                Commands::UUID},
        {"GET",                 Commands::GET},
        {"PROFILE_PROPS",       Commands::PROFILE_PROPS},
    };
};


#endif // REQUESTHANDLER_H

#ifndef REQUESTHANDLERCLIENT_H
#define REQUESTHANDLERCLIENT_H
#include <QTcpSocket>

enum class Commands{
    SIGN_UP_CONFIRM,
    LOGIN_CONFIRM,
    ACCEPTED,
    REJECTED,
    UUID,
    ACCESS_TK,
    REFRESH_TK,
    DATE,

};

class RequestHandlerClient : public QObject
{
    Q_OBJECT
public:
    RequestHandlerClient(QObject *parent = 0);
    Q_INVOKABLE void send(const QByteArray& params, const QByteArray& data = "");
    void receiveRequest(QTcpSocket *socket);
    void interpret();
    QTcpSocket *socket;

    QByteArray requestParams;
    QByteArray requestData;

    uint16_t requestDataSize = 0;
    uint16_t requestParamSize = 0;
    bool paramsWasRead = false;
    bool dataWasRead = false;

    QMap<QString,Commands> Dict = {
        {
         {"SIGN_UP_CONFIRM",    Commands::SIGN_UP_CONFIRM},
         {"LOGIN_CONFIRM",      Commands::LOGIN_CONFIRM},
         {"ACCEPTED",           Commands::ACCEPTED},
         {"REJECTED",           Commands::REJECTED},
         {"UUID",               Commands::UUID},
         {"ACCESS_TK",          Commands::ACCESS_TK},
         {"REFRESH_TK",         Commands::REFRESH_TK},
         {"DATE",               Commands::DATE},
        }

    };
signals:
    void signUpDataReceived(QString uuid,QString access_token,QString refresh_token,QString date);

};
#endif // REQUESTHANDLERCLIENT_H

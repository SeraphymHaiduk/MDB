#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H
#include <QTcpSocket>

class RequestSender : public QObject
{
    Q_OBJECT
public:
    RequestSender(QObject *parent = 0);
    QTcpSocket *socket;
};

#endif // REQUESTSENDER_H

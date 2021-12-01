#include "requestsender.h"
#include <QHostAddress>
#include <QByteArray>
#include <QDataStream>
RequestSender::RequestSender(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    socket->connectToHost(QHostAddress::LocalHost,2323);
    QObject::connect(socket,&QTcpSocket::connected,this,[](){qDebug() << "connected";});
    QByteArray package;
    QDataStream out(&package,QIODevice::WriteOnly);
    QByteArray params = "sadsad Aboba@gmail.com zhmishenko17";
    QByteArray data = "some data";
    out << (short int)params.size() << (short int)data.size();
    out.writeRawData(params, params.size());
    out.writeRawData(data, data.size());
    out.device()->seek(0);
    socket->write(package);
}

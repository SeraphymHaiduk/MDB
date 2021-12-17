#include <QCoreApplication>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <requesthandler.h>
#include <QList>
#include <QMap>
#include <iostream>
int main(int argc, char *argv[])
{
       QCoreApplication app(argc,argv);
       QTextStream cout(stdout);
       QTextStream cin(stdin);
       QString s = "aaa bbb ccc";
       QList<QString> sl = s.split(' ');
       QList<QString>::iterator it = sl.begin();
       QString *ss = &(*it++);
    //   qDebug() << *ss << *it;
       RequestHandler handler;
       app.exec();
       return 0;
}

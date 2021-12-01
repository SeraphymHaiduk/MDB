#include <QCoreApplication>
#include <QTextStream>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <requesthandler.h>
#include <iostream>
int main(int argc, char *argv[])
{
       QCoreApplication app(argc,argv);
       RequestHandler *handler = new RequestHandler(&app);
       app.exec();
       delete handler;
       return 0;
}

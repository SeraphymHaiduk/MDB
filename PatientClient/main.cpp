#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtSql>
#include <QSqlDatabase>
#include "requestHandlerClient.h"
#include <QQuickView>
#include "localconfig.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);

  qmlRegisterType<RequestHandlerClient>("RequestHandler",1,0,"Handler");
  qmlRegisterType<LocalConfig>("LocalConfig",1,0,"LocalConfig");
  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);

  engine.load(url);

/*
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
  db.setDatabaseName("test1_db");
  db.setUserName("seraphym");
  db.setPassword("");
  if(!db.open()){
       qDebug() << QString("db error! %1").arg(db.lastError().text());
  }
  else{
       qDebug() << "db succes!";
  }
  QSqlQuery q;
  q.exec("SELECT * FROM patient");
  QString c;
  q.next();
  c.append(q.value(4).toString());
  qDebug()<<c;
*/
/*    QDate d = QDate::fromString("2012-12-10","yyyy-MM-dd");
    qDebug() << d.day();*/
  return app.exec();;
}

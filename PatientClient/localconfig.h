#ifndef LOCALCONFIG_H
#define LOCALCONFIG_H
#include <QObject>
#include <QVariantMap>

class LocalConfig : public QObject
{
    Q_OBJECT
public:
    LocalConfig(QObject *parent = 0);
    Q_INVOKABLE void setConfigProperties(QVariantMap values);
    Q_INVOKABLE QVariantMap getConfigProperties();
    Q_INVOKABLE QString getActualToken();
/*    Q_INVOKABLE void setUserProperties(QVariantMap values);
    Q_INVOKABLE QVariantMap getUserProperties();
    Q_INVOKABLE void addNotation(QVariantMap values);
    Q_INVOKABLE void getNotations(QVariantMap properties);
*/

};

#endif // LOCALCONFIG_H
/*
config:
    uuid
    pincode
    access_token
    refresh_token
    access_date
    refresh_date
user properties:
    name
    surname
    patronymic
    date of birth
    profile photo
    сontingent
notations table:
...
resipes table:
...
agreements:
    doctor_uuid permission final_date
*/

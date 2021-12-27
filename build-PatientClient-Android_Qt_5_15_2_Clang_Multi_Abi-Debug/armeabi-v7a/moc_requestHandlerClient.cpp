/****************************************************************************
** Meta object code from reading C++ file 'requestHandlerClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../PatientClient/requestHandlerClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'requestHandlerClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RequestHandlerClient_t {
    QByteArrayData data[20];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RequestHandlerClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RequestHandlerClient_t qt_meta_stringdata_RequestHandlerClient = {
    {
QT_MOC_LITERAL(0, 0, 20), // "RequestHandlerClient"
QT_MOC_LITERAL(1, 21, 18), // "signUpDataReceived"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "uuid"
QT_MOC_LITERAL(4, 46, 12), // "access_token"
QT_MOC_LITERAL(5, 59, 13), // "refresh_token"
QT_MOC_LITERAL(6, 73, 4), // "date"
QT_MOC_LITERAL(7, 78, 11), // "client_type"
QT_MOC_LITERAL(8, 90, 17), // "loginDataRecieved"
QT_MOC_LITERAL(9, 108, 20), // "profilePropsReceived"
QT_MOC_LITERAL(10, 129, 4), // "name"
QT_MOC_LITERAL(11, 134, 7), // "surname"
QT_MOC_LITERAL(12, 142, 10), // "patromynic"
QT_MOC_LITERAL(13, 153, 21), // "visitsHistoryReceived"
QT_MOC_LITERAL(14, 175, 4), // "list"
QT_MOC_LITERAL(15, 180, 4), // "rows"
QT_MOC_LITERAL(16, 185, 4), // "cols"
QT_MOC_LITERAL(17, 190, 4), // "send"
QT_MOC_LITERAL(18, 195, 6), // "params"
QT_MOC_LITERAL(19, 202, 4) // "data"

    },
    "RequestHandlerClient\0signUpDataReceived\0"
    "\0uuid\0access_token\0refresh_token\0date\0"
    "client_type\0loginDataRecieved\0"
    "profilePropsReceived\0name\0surname\0"
    "patromynic\0visitsHistoryReceived\0list\0"
    "rows\0cols\0send\0params\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RequestHandlerClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   44,    2, 0x06 /* Public */,
       8,    4,   55,    2, 0x06 /* Public */,
       9,    3,   64,    2, 0x06 /* Public */,
      13,    3,   71,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    2,   78,    2, 0x02 /* Public */,
      17,    1,   83,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::QVariantList, QMetaType::Int, QMetaType::Int,   14,   15,   16,

 // methods: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QByteArray,   18,   19,
    QMetaType::Void, QMetaType::QByteArray,   18,

       0        // eod
};

void RequestHandlerClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RequestHandlerClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signUpDataReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 1: _t->loginDataRecieved((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->profilePropsReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->visitsHistoryReceived((*reinterpret_cast< QVariantList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->send((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 5: _t->send((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RequestHandlerClient::*)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RequestHandlerClient::signUpDataReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RequestHandlerClient::*)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RequestHandlerClient::loginDataRecieved)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RequestHandlerClient::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RequestHandlerClient::profilePropsReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RequestHandlerClient::*)(QVariantList , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RequestHandlerClient::visitsHistoryReceived)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RequestHandlerClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RequestHandlerClient.data,
    qt_meta_data_RequestHandlerClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RequestHandlerClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RequestHandlerClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RequestHandlerClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RequestHandlerClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RequestHandlerClient::signUpDataReceived(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RequestHandlerClient::loginDataRecieved(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RequestHandlerClient::profilePropsReceived(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RequestHandlerClient::visitsHistoryReceived(QVariantList _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

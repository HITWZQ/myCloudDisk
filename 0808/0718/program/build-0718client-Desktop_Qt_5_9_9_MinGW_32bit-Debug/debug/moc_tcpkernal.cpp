/****************************************************************************
** Meta object code from reading C++ file 'tcpkernal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../0809/program/0718client/tcpkernal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpkernal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPKernal_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPKernal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPKernal_t qt_meta_stringdata_TCPKernal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPKernal"
QT_MOC_LITERAL(1, 10, 13), // "sigalregister"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "const char*"
QT_MOC_LITERAL(4, 37, 5), // "szbuf"
QT_MOC_LITERAL(5, 43, 11), // "signallogin"
QT_MOC_LITERAL(6, 55, 17), // "signalgetfilelist"
QT_MOC_LITERAL(7, 73, 20) // "signaluploadfileinfo"

    },
    "TCPKernal\0sigalregister\0\0const char*\0"
    "szbuf\0signallogin\0signalgetfilelist\0"
    "signaluploadfileinfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPKernal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       7,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void TCPKernal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPKernal *_t = static_cast<TCPKernal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigalregister((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 1: _t->signallogin((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 2: _t->signalgetfilelist((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 3: _t->signaluploadfileinfo((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TCPKernal::*_t)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPKernal::sigalregister)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TCPKernal::*_t)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPKernal::signallogin)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TCPKernal::*_t)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPKernal::signalgetfilelist)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TCPKernal::*_t)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TCPKernal::signaluploadfileinfo)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject TCPKernal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TCPKernal.data,
      qt_meta_data_TCPKernal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TCPKernal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPKernal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPKernal.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IKernal"))
        return static_cast< IKernal*>(this);
    return QObject::qt_metacast(_clname);
}

int TCPKernal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TCPKernal::sigalregister(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TCPKernal::signallogin(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TCPKernal::signalgetfilelist(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TCPKernal::signaluploadfileinfo(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

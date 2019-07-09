/****************************************************************************
** Meta object code from reading C++ file 'imgworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imgworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_imgworker_t {
    QByteArrayData data[6];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_imgworker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_imgworker_t qt_meta_stringdata_imgworker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "imgworker"
QT_MOC_LITERAL(1, 10, 13), // "workRequested"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "finished"
QT_MOC_LITERAL(4, 34, 7), // "sendstr"
QT_MOC_LITERAL(5, 42, 6) // "doWork"

    },
    "imgworker\0workRequested\0\0finished\0"
    "sendstr\0doWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_imgworker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    1,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void imgworker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        imgworker *_t = static_cast<imgworker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workRequested(); break;
        case 1: _t->finished(); break;
        case 2: _t->sendstr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->doWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (imgworker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imgworker::workRequested)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (imgworker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imgworker::finished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (imgworker::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&imgworker::sendstr)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject imgworker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_imgworker.data,
      qt_meta_data_imgworker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *imgworker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *imgworker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_imgworker.stringdata0))
        return static_cast<void*>(const_cast< imgworker*>(this));
    return QObject::qt_metacast(_clname);
}

int imgworker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void imgworker::workRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void imgworker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void imgworker::sendstr(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

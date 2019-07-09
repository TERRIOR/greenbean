/****************************************************************************
** Meta object code from reading C++ file 'camsetdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../camsetdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'camsetdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CamsetDialog_t {
    QByteArrayData data[9];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CamsetDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CamsetDialog_t qt_meta_stringdata_CamsetDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CamsetDialog"
QT_MOC_LITERAL(1, 13, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 16), // "QAbstractButton*"
QT_MOC_LITERAL(4, 52, 6), // "button"
QT_MOC_LITERAL(5, 59, 26), // "on_pushButtonstart_clicked"
QT_MOC_LITERAL(6, 86, 25), // "on_pushButtonstop_clicked"
QT_MOC_LITERAL(7, 112, 10), // "refleshpic"
QT_MOC_LITERAL(8, 123, 9) // "UpdateGUI"

    },
    "CamsetDialog\0on_buttonBox_clicked\0\0"
    "QAbstractButton*\0button\0"
    "on_pushButtonstart_clicked\0"
    "on_pushButtonstop_clicked\0refleshpic\0"
    "UpdateGUI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CamsetDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CamsetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CamsetDialog *_t = static_cast<CamsetDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonstart_clicked(); break;
        case 2: _t->on_pushButtonstop_clicked(); break;
        case 3: _t->refleshpic(); break;
        case 4: _t->UpdateGUI(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

const QMetaObject CamsetDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CamsetDialog.data,
      qt_meta_data_CamsetDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CamsetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CamsetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CamsetDialog.stringdata0))
        return static_cast<void*>(const_cast< CamsetDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CamsetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

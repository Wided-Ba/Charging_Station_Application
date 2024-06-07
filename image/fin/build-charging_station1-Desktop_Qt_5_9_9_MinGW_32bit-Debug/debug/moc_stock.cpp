/****************************************************************************
** Meta object code from reading C++ file 'stock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../charging_station1/stock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_stock_t {
    QByteArrayData data[13];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_stock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_stock_t qt_meta_stringdata_stock = {
    {
QT_MOC_LITERAL(0, 0, 5), // "stock"
QT_MOC_LITERAL(1, 6, 29), // "on_pushButton_ajouter_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 29), // "on_pushButton_del_all_clicked"
QT_MOC_LITERAL(4, 67, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 89, 28), // "on_tableView_stock_activated"
QT_MOC_LITERAL(6, 118, 5), // "index"
QT_MOC_LITERAL(7, 124, 30), // "on_pushButton_modifier_clicked"
QT_MOC_LITERAL(8, 155, 37), // "on_comboBox_modif_currentInde..."
QT_MOC_LITERAL(9, 193, 32), // "on_lineEdit_chercher_textChanged"
QT_MOC_LITERAL(10, 226, 4), // "arg1"
QT_MOC_LITERAL(11, 231, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(12, 255, 23) // "on_pushButton_4_clicked"

    },
    "stock\0on_pushButton_ajouter_clicked\0"
    "\0on_pushButton_del_all_clicked\0"
    "on_pushButton_clicked\0"
    "on_tableView_stock_activated\0index\0"
    "on_pushButton_modifier_clicked\0"
    "on_comboBox_modif_currentIndexChanged\0"
    "on_lineEdit_chercher_textChanged\0arg1\0"
    "on_pushButton_3_clicked\0on_pushButton_4_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void stock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        stock *_t = static_cast<stock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_ajouter_clicked(); break;
        case 1: _t->on_pushButton_del_all_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_tableView_stock_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_modifier_clicked(); break;
        case 5: _t->on_comboBox_modif_currentIndexChanged(); break;
        case 6: _t->on_lineEdit_chercher_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_pushButton_4_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject stock::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_stock.data,
      qt_meta_data_stock,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *stock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_stock.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int stock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

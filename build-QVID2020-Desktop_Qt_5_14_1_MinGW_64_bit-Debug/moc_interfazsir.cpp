/****************************************************************************
** Meta object code from reading C++ file 'interfazsir.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../QVID2020/interfazsir.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfazsir.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InterfazSIR_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InterfazSIR_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InterfazSIR_t qt_meta_stringdata_InterfazSIR = {
    {
QT_MOC_LITERAL(0, 0, 11), // "InterfazSIR"
QT_MOC_LITERAL(1, 12, 7), // "iniciar"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "pais_a_graficar"
QT_MOC_LITERAL(4, 37, 5), // "salir"
QT_MOC_LITERAL(5, 43, 5), // "rbOpc"
QT_MOC_LITERAL(6, 49, 14), // "elegir_grafico"
QT_MOC_LITERAL(7, 64, 8), // "pestania"
QT_MOC_LITERAL(8, 73, 15) // "iniciarGraficos"

    },
    "InterfazSIR\0iniciar\0\0pais_a_graficar\0"
    "salir\0rbOpc\0elegir_grafico\0pestania\0"
    "iniciarGraficos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InterfazSIR[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    1,   44,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void InterfazSIR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InterfazSIR *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iniciar((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->salir(); break;
        case 2: _t->rbOpc(); break;
        case 3: _t->elegir_grafico((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->iniciarGraficos(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InterfazSIR::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_InterfazSIR.data,
    qt_meta_data_InterfazSIR,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InterfazSIR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InterfazSIR::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InterfazSIR.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InterfazSIR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

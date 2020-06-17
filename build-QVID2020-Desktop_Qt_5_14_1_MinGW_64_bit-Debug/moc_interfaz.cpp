/****************************************************************************
** Meta object code from reading C++ file 'interfaz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../QVID2020/interfaz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfaz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Interfaz_t {
    QByteArrayData data[17];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Interfaz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Interfaz_t qt_meta_stringdata_Interfaz = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Interfaz"
QT_MOC_LITERAL(1, 9, 6), // "sRango"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 6), // "sValor"
QT_MOC_LITERAL(4, 24, 6), // "sTexto"
QT_MOC_LITERAL(5, 31, 7), // "sig_SIR"
QT_MOC_LITERAL(6, 39, 15), // "listar_regiones"
QT_MOC_LITERAL(7, 55, 4), // "pais"
QT_MOC_LITERAL(8, 60, 14), // "calcular_datos"
QT_MOC_LITERAL(9, 75, 13), // "actualizar_bd"
QT_MOC_LITERAL(10, 89, 12), // "proximamente"
QT_MOC_LITERAL(11, 102, 15), // "mostrarProgreso"
QT_MOC_LITERAL(12, 118, 8), // "strTabla"
QT_MOC_LITERAL(13, 127, 4), // "maxV"
QT_MOC_LITERAL(14, 132, 4), // "actV"
QT_MOC_LITERAL(15, 137, 9), // "forzarAct"
QT_MOC_LITERAL(16, 147, 11) // "mostrar_SIR"

    },
    "Interfaz\0sRango\0\0sValor\0sTexto\0sig_SIR\0"
    "listar_regiones\0pais\0calcular_datos\0"
    "actualizar_bd\0proximamente\0mostrarProgreso\0"
    "strTabla\0maxV\0actV\0forzarAct\0mostrar_SIR"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interfaz[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   83,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    3,   89,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Interfaz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Interfaz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sRango((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sValor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sTexto((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sig_SIR((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->listar_regiones((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->calcular_datos(); break;
        case 6: _t->actualizar_bd(); break;
        case 7: _t->proximamente(); break;
        case 8: _t->mostrarProgreso((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->forzarAct(); break;
        case 10: _t->mostrar_SIR(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Interfaz::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interfaz::sRango)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Interfaz::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interfaz::sValor)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Interfaz::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interfaz::sTexto)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Interfaz::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interfaz::sig_SIR)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Interfaz::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Interfaz.data,
    qt_meta_data_Interfaz,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Interfaz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interfaz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Interfaz.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Interfaz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Interfaz::sRango(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Interfaz::sValor(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Interfaz::sTexto(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Interfaz::sig_SIR(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

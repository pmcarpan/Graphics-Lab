/****************************************************************************
** Meta object code from reading C++ file 'gridmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/gridmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gridmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GridModel_t {
    QByteArrayData data[14];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GridModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GridModel_t qt_meta_stringdata_GridModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GridModel"
QT_MOC_LITERAL(1, 10, 20), // "sendHoverCoordinates"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 1), // "x"
QT_MOC_LITERAL(4, 34, 1), // "y"
QT_MOC_LITERAL(5, 36, 20), // "sendClickCoordinates"
QT_MOC_LITERAL(6, 57, 17), // "receiveHoverIndex"
QT_MOC_LITERAL(7, 75, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 87, 5), // "index"
QT_MOC_LITERAL(9, 93, 17), // "receiveClickIndex"
QT_MOC_LITERAL(10, 111, 27), // "receiveChangeGridSizeSignal"
QT_MOC_LITERAL(11, 139, 4), // "size"
QT_MOC_LITERAL(12, 144, 22), // "receiveClearGridSignal"
QT_MOC_LITERAL(13, 167, 21) // "receiveSetPixelSignal"

    },
    "GridModel\0sendHoverCoordinates\0\0x\0y\0"
    "sendClickCoordinates\0receiveHoverIndex\0"
    "QModelIndex\0index\0receiveClickIndex\0"
    "receiveChangeGridSizeSignal\0size\0"
    "receiveClearGridSignal\0receiveSetPixelSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GridModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   59,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      10,    1,   65,    2, 0x0a /* Public */,
      12,    0,   68,    2, 0x0a /* Public */,
      13,    2,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

void GridModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GridModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendHoverCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sendClickCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->receiveHoverIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->receiveClickIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->receiveChangeGridSizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->receiveClearGridSignal(); break;
        case 6: _t->receiveSetPixelSignal((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GridModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GridModel::sendHoverCoordinates)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GridModel::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GridModel::sendClickCoordinates)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GridModel::staticMetaObject = { {
    &QAbstractTableModel::staticMetaObject,
    qt_meta_stringdata_GridModel.data,
    qt_meta_data_GridModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GridModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GridModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GridModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int GridModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void GridModel::sendHoverCoordinates(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GridModel::sendClickCoordinates(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'circlemenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/circlemenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'circlemenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CircleMenu_t {
    QByteArrayData data[16];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CircleMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CircleMenu_t qt_meta_stringdata_CircleMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CircleMenu"
QT_MOC_LITERAL(1, 11, 20), // "sendDrawCircleSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "x1"
QT_MOC_LITERAL(4, 36, 2), // "y1"
QT_MOC_LITERAL(5, 39, 1), // "r"
QT_MOC_LITERAL(6, 41, 27), // "CircleAlgorithms::Algorithm"
QT_MOC_LITERAL(7, 69, 4), // "algo"
QT_MOC_LITERAL(8, 74, 23), // "receiveHoverCoordinates"
QT_MOC_LITERAL(9, 98, 1), // "x"
QT_MOC_LITERAL(10, 100, 1), // "y"
QT_MOC_LITERAL(11, 102, 23), // "receiveClickCoordinates"
QT_MOC_LITERAL(12, 126, 29), // "onSetCentrePointButtonClicked"
QT_MOC_LITERAL(13, 156, 19), // "onDrawButtonClicked"
QT_MOC_LITERAL(14, 176, 16), // "receiveTimeTaken"
QT_MOC_LITERAL(15, 193, 4) // "time"

    },
    "CircleMenu\0sendDrawCircleSignal\0\0x1\0"
    "y1\0r\0CircleAlgorithms::Algorithm\0algo\0"
    "receiveHoverCoordinates\0x\0y\0"
    "receiveClickCoordinates\0"
    "onSetCentrePointButtonClicked\0"
    "onDrawButtonClicked\0receiveTimeTaken\0"
    "time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CircleMenu[] = {

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
       1,    4,   49,    2, 0x06 /* Public */,
       1,    3,   58,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   65,    2, 0x0a /* Public */,
      11,    2,   70,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x0a /* Public */,
      14,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 6,    3,    4,    5,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   15,

       0        // eod
};

void CircleMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CircleMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDrawCircleSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< CircleAlgorithms::Algorithm(*)>(_a[4]))); break;
        case 1: _t->sendDrawCircleSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->receiveHoverCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->receiveClickCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onSetCentrePointButtonClicked(); break;
        case 5: _t->onDrawButtonClicked(); break;
        case 6: _t->receiveTimeTaken((*reinterpret_cast< const long long(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CircleMenu::*)(int , int , int , CircleAlgorithms::Algorithm );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CircleMenu::sendDrawCircleSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CircleMenu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CircleMenu.data,
    qt_meta_data_CircleMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CircleMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CircleMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CircleMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CircleMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CircleMenu::sendDrawCircleSignal(int _t1, int _t2, int _t3, CircleAlgorithms::Algorithm _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

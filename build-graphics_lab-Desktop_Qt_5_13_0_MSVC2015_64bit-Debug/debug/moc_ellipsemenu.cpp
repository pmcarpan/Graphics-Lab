/****************************************************************************
** Meta object code from reading C++ file 'ellipsemenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/ellipsemenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ellipsemenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EllipseMenu_t {
    QByteArrayData data[17];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EllipseMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EllipseMenu_t qt_meta_stringdata_EllipseMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "EllipseMenu"
QT_MOC_LITERAL(1, 12, 21), // "sendDrawEllipseSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 2), // "x1"
QT_MOC_LITERAL(4, 38, 2), // "y1"
QT_MOC_LITERAL(5, 41, 1), // "a"
QT_MOC_LITERAL(6, 43, 1), // "b"
QT_MOC_LITERAL(7, 45, 28), // "EllipseAlgorithms::Algorithm"
QT_MOC_LITERAL(8, 74, 4), // "algo"
QT_MOC_LITERAL(9, 79, 23), // "receiveHoverCoordinates"
QT_MOC_LITERAL(10, 103, 1), // "x"
QT_MOC_LITERAL(11, 105, 1), // "y"
QT_MOC_LITERAL(12, 107, 23), // "receiveClickCoordinates"
QT_MOC_LITERAL(13, 131, 29), // "onSetCentrePointButtonClicked"
QT_MOC_LITERAL(14, 161, 19), // "onDrawButtonClicked"
QT_MOC_LITERAL(15, 181, 16), // "receiveTimeTaken"
QT_MOC_LITERAL(16, 198, 4) // "time"

    },
    "EllipseMenu\0sendDrawEllipseSignal\0\0"
    "x1\0y1\0a\0b\0EllipseAlgorithms::Algorithm\0"
    "algo\0receiveHoverCoordinates\0x\0y\0"
    "receiveClickCoordinates\0"
    "onSetCentrePointButtonClicked\0"
    "onDrawButtonClicked\0receiveTimeTaken\0"
    "time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EllipseMenu[] = {

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
       1,    5,   49,    2, 0x06 /* Public */,
       1,    4,   60,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   69,    2, 0x0a /* Public */,
      12,    2,   74,    2, 0x0a /* Public */,
      13,    0,   79,    2, 0x0a /* Public */,
      14,    0,   80,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    3,    4,    5,    6,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   16,

       0        // eod
};

void EllipseMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EllipseMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDrawEllipseSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< EllipseAlgorithms::Algorithm(*)>(_a[5]))); break;
        case 1: _t->sendDrawEllipseSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
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
            using _t = void (EllipseMenu::*)(int , int , int , int , EllipseAlgorithms::Algorithm );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EllipseMenu::sendDrawEllipseSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EllipseMenu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_EllipseMenu.data,
    qt_meta_data_EllipseMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EllipseMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EllipseMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EllipseMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EllipseMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EllipseMenu::sendDrawEllipseSignal(int _t1, int _t2, int _t3, int _t4, EllipseAlgorithms::Algorithm _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

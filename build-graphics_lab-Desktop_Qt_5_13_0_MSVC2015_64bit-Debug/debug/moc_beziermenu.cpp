/****************************************************************************
** Meta object code from reading C++ file 'beziermenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/beziermenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'beziermenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BezierMenu_t {
    QByteArrayData data[14];
    char stringdata0[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BezierMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BezierMenu_t qt_meta_stringdata_BezierMenu = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BezierMenu"
QT_MOC_LITERAL(1, 11, 24), // "sendDrawBezierFullSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 32), // "std::vector<std::pair<int,int> >"
QT_MOC_LITERAL(4, 70, 13), // "controlPoints"
QT_MOC_LITERAL(5, 84, 26), // "sendDrawBezierApproxSignal"
QT_MOC_LITERAL(6, 111, 23), // "receiveHoverCoordinates"
QT_MOC_LITERAL(7, 135, 1), // "x"
QT_MOC_LITERAL(8, 137, 1), // "y"
QT_MOC_LITERAL(9, 139, 23), // "receiveClickCoordinates"
QT_MOC_LITERAL(10, 163, 31), // "onPushControlPointButtonClicked"
QT_MOC_LITERAL(11, 195, 33), // "onClearControlPointsButtonCli..."
QT_MOC_LITERAL(12, 229, 29), // "onDrawBezierFullButtonClicked"
QT_MOC_LITERAL(13, 259, 31) // "onDrawBezierApproxButtonClicked"

    },
    "BezierMenu\0sendDrawBezierFullSignal\0"
    "\0std::vector<std::pair<int,int> >\0"
    "controlPoints\0sendDrawBezierApproxSignal\0"
    "receiveHoverCoordinates\0x\0y\0"
    "receiveClickCoordinates\0"
    "onPushControlPointButtonClicked\0"
    "onClearControlPointsButtonClicked\0"
    "onDrawBezierFullButtonClicked\0"
    "onDrawBezierApproxButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BezierMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   60,    2, 0x0a /* Public */,
       9,    2,   65,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BezierMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BezierMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDrawBezierFullSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 1: _t->sendDrawBezierApproxSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 2: _t->receiveHoverCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->receiveClickCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onPushControlPointButtonClicked(); break;
        case 5: _t->onClearControlPointsButtonClicked(); break;
        case 6: _t->onDrawBezierFullButtonClicked(); break;
        case 7: _t->onDrawBezierApproxButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BezierMenu::*)(std::vector<std::pair<int,int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BezierMenu::sendDrawBezierFullSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BezierMenu::*)(std::vector<std::pair<int,int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BezierMenu::sendDrawBezierApproxSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BezierMenu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_BezierMenu.data,
    qt_meta_data_BezierMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BezierMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BezierMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BezierMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BezierMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BezierMenu::sendDrawBezierFullSignal(std::vector<std::pair<int,int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BezierMenu::sendDrawBezierApproxSignal(std::vector<std::pair<int,int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'gridmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/gridmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gridmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GridMenu_t {
    QByteArrayData data[9];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GridMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GridMenu_t qt_meta_stringdata_GridMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GridMenu"
QT_MOC_LITERAL(1, 9, 25), // "sendChangePixelSizeSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "size"
QT_MOC_LITERAL(4, 41, 24), // "sendChangeGridSizeSignal"
QT_MOC_LITERAL(5, 66, 19), // "sendClearGridSignal"
QT_MOC_LITERAL(6, 86, 24), // "onPixelSizeButtonClicked"
QT_MOC_LITERAL(7, 111, 23), // "onGridSizeButtonClicked"
QT_MOC_LITERAL(8, 135, 24) // "onClearGridButtonClicked"

    },
    "GridMenu\0sendChangePixelSizeSignal\0\0"
    "size\0sendChangeGridSizeSignal\0"
    "sendClearGridSignal\0onPixelSizeButtonClicked\0"
    "onGridSizeButtonClicked\0"
    "onClearGridButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GridMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   51,    2, 0x0a /* Public */,
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GridMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GridMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendChangePixelSizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendChangeGridSizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendClearGridSignal(); break;
        case 3: _t->onPixelSizeButtonClicked(); break;
        case 4: _t->onGridSizeButtonClicked(); break;
        case 5: _t->onClearGridButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GridMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GridMenu::sendChangePixelSizeSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GridMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GridMenu::sendChangeGridSizeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GridMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GridMenu::sendClearGridSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GridMenu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_GridMenu.data,
    qt_meta_data_GridMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GridMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GridMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GridMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GridMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GridMenu::sendChangePixelSizeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GridMenu::sendChangeGridSizeSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GridMenu::sendClearGridSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

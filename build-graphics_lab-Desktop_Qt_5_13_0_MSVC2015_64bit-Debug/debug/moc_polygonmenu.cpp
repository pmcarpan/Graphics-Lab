/****************************************************************************
** Meta object code from reading C++ file 'polygonmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/polygonmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'polygonmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PolygonMenu_t {
    QByteArrayData data[27];
    char stringdata0[514];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolygonMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolygonMenu_t qt_meta_stringdata_PolygonMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PolygonMenu"
QT_MOC_LITERAL(1, 12, 21), // "sendDrawPolygonSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 32), // "std::vector<std::pair<int,int> >"
QT_MOC_LITERAL(4, 68, 8), // "vertices"
QT_MOC_LITERAL(5, 77, 19), // "sendFloodFillSignal"
QT_MOC_LITERAL(6, 97, 1), // "x"
QT_MOC_LITERAL(7, 99, 1), // "y"
QT_MOC_LITERAL(8, 101, 8), // "oldColor"
QT_MOC_LITERAL(9, 110, 8), // "newColor"
QT_MOC_LITERAL(10, 119, 22), // "sendBoundaryFillSignal"
QT_MOC_LITERAL(11, 142, 9), // "edgeColor"
QT_MOC_LITERAL(12, 152, 29), // "sendScanLinePolygonFillSignal"
QT_MOC_LITERAL(13, 182, 21), // "sendClipPolygonSignal"
QT_MOC_LITERAL(14, 204, 27), // "std::tuple<int,int,int,int>"
QT_MOC_LITERAL(15, 232, 4), // "rect"
QT_MOC_LITERAL(16, 237, 23), // "receiveHoverCoordinates"
QT_MOC_LITERAL(17, 261, 23), // "receiveClickCoordinates"
QT_MOC_LITERAL(18, 285, 24), // "onPushPointButtonClicked"
QT_MOC_LITERAL(19, 310, 20), // "onClearButtonClicked"
QT_MOC_LITERAL(20, 331, 19), // "onDrawButtonClicked"
QT_MOC_LITERAL(21, 351, 24), // "onFloodFillButtonClicked"
QT_MOC_LITERAL(22, 376, 27), // "onBoundaryFillButtonClicked"
QT_MOC_LITERAL(23, 404, 27), // "onScanLineFillButtonClicked"
QT_MOC_LITERAL(24, 432, 30), // "onSetClipPointOneButtonClicked"
QT_MOC_LITERAL(25, 463, 30), // "onSetClipPointTwoButtonClicked"
QT_MOC_LITERAL(26, 494, 19) // "onClipButtonClicked"

    },
    "PolygonMenu\0sendDrawPolygonSignal\0\0"
    "std::vector<std::pair<int,int> >\0"
    "vertices\0sendFloodFillSignal\0x\0y\0"
    "oldColor\0newColor\0sendBoundaryFillSignal\0"
    "edgeColor\0sendScanLinePolygonFillSignal\0"
    "sendClipPolygonSignal\0std::tuple<int,int,int,int>\0"
    "rect\0receiveHoverCoordinates\0"
    "receiveClickCoordinates\0"
    "onPushPointButtonClicked\0onClearButtonClicked\0"
    "onDrawButtonClicked\0onFloodFillButtonClicked\0"
    "onBoundaryFillButtonClicked\0"
    "onScanLineFillButtonClicked\0"
    "onSetClipPointOneButtonClicked\0"
    "onSetClipPointTwoButtonClicked\0"
    "onClipButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolygonMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    4,   97,    2, 0x06 /* Public */,
      10,    4,  106,    2, 0x06 /* Public */,
      12,    1,  115,    2, 0x06 /* Public */,
      13,    2,  118,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    2,  123,    2, 0x0a /* Public */,
      17,    2,  128,    2, 0x0a /* Public */,
      18,    0,  133,    2, 0x0a /* Public */,
      19,    0,  134,    2, 0x0a /* Public */,
      20,    0,  135,    2, 0x0a /* Public */,
      21,    0,  136,    2, 0x0a /* Public */,
      22,    0,  137,    2, 0x0a /* Public */,
      23,    0,  138,    2, 0x0a /* Public */,
      24,    0,  139,    2, 0x0a /* Public */,
      25,    0,  140,    2, 0x0a /* Public */,
      26,    0,  141,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor, QMetaType::QColor,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor, QMetaType::QColor,    6,    7,   11,    9,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 14,    4,   15,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PolygonMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PolygonMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDrawPolygonSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 1: _t->sendFloodFillSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< QColor(*)>(_a[4]))); break;
        case 2: _t->sendBoundaryFillSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< QColor(*)>(_a[4]))); break;
        case 3: _t->sendScanLinePolygonFillSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 4: _t->sendClipPolygonSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1])),(*reinterpret_cast< std::tuple<int,int,int,int>(*)>(_a[2]))); break;
        case 5: _t->receiveHoverCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->receiveClickCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->onPushPointButtonClicked(); break;
        case 8: _t->onClearButtonClicked(); break;
        case 9: _t->onDrawButtonClicked(); break;
        case 10: _t->onFloodFillButtonClicked(); break;
        case 11: _t->onBoundaryFillButtonClicked(); break;
        case 12: _t->onScanLineFillButtonClicked(); break;
        case 13: _t->onSetClipPointOneButtonClicked(); break;
        case 14: _t->onSetClipPointTwoButtonClicked(); break;
        case 15: _t->onClipButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PolygonMenu::*)(std::vector<std::pair<int,int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolygonMenu::sendDrawPolygonSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PolygonMenu::*)(int , int , QColor , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolygonMenu::sendFloodFillSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PolygonMenu::*)(int , int , QColor , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolygonMenu::sendBoundaryFillSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PolygonMenu::*)(std::vector<std::pair<int,int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolygonMenu::sendScanLinePolygonFillSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PolygonMenu::*)(std::vector<std::pair<int,int>> , std::tuple<int,int,int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolygonMenu::sendClipPolygonSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PolygonMenu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_PolygonMenu.data,
    qt_meta_data_PolygonMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PolygonMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolygonMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolygonMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PolygonMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void PolygonMenu::sendDrawPolygonSignal(std::vector<std::pair<int,int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PolygonMenu::sendFloodFillSignal(int _t1, int _t2, QColor _t3, QColor _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PolygonMenu::sendBoundaryFillSignal(int _t1, int _t2, QColor _t3, QColor _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PolygonMenu::sendScanLinePolygonFillSignal(std::vector<std::pair<int,int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PolygonMenu::sendClipPolygonSignal(std::vector<std::pair<int,int>> _t1, std::tuple<int,int,int,int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

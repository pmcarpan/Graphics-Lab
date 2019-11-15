/****************************************************************************
** Meta object code from reading C++ file 'linemenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/linemenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linemenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineMenu_t {
    QByteArrayData data[28];
    char stringdata0[447];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineMenu_t qt_meta_stringdata_LineMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LineMenu"
QT_MOC_LITERAL(1, 9, 18), // "sendDrawLineSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "x1"
QT_MOC_LITERAL(4, 32, 2), // "y1"
QT_MOC_LITERAL(5, 35, 2), // "x2"
QT_MOC_LITERAL(6, 38, 2), // "y2"
QT_MOC_LITERAL(7, 41, 25), // "LineAlgorithms::Algorithm"
QT_MOC_LITERAL(8, 67, 4), // "algo"
QT_MOC_LITERAL(9, 72, 19), // "sendClipLinesSignal"
QT_MOC_LITERAL(10, 92, 41), // "std::vector<std::tuple<int,in..."
QT_MOC_LITERAL(11, 134, 5), // "lines"
QT_MOC_LITERAL(12, 140, 27), // "std::tuple<int,int,int,int>"
QT_MOC_LITERAL(13, 168, 4), // "rect"
QT_MOC_LITERAL(14, 173, 23), // "receiveHoverCoordinates"
QT_MOC_LITERAL(15, 197, 1), // "x"
QT_MOC_LITERAL(16, 199, 1), // "y"
QT_MOC_LITERAL(17, 201, 23), // "receiveClickCoordinates"
QT_MOC_LITERAL(18, 225, 26), // "onSetPointOneButtonClicked"
QT_MOC_LITERAL(19, 252, 26), // "onSetPointTwoButtonClicked"
QT_MOC_LITERAL(20, 279, 19), // "onDrawButtonClicked"
QT_MOC_LITERAL(21, 299, 22), // "onDrawAllButtonClicked"
QT_MOC_LITERAL(22, 322, 20), // "onClearButtonClicked"
QT_MOC_LITERAL(23, 343, 30), // "onSetClipPointOneButtonClicked"
QT_MOC_LITERAL(24, 374, 30), // "onSetClipPointTwoButtonClicked"
QT_MOC_LITERAL(25, 405, 19), // "onClipButtonClicked"
QT_MOC_LITERAL(26, 425, 16), // "receiveTimeTaken"
QT_MOC_LITERAL(27, 442, 4) // "time"

    },
    "LineMenu\0sendDrawLineSignal\0\0x1\0y1\0"
    "x2\0y2\0LineAlgorithms::Algorithm\0algo\0"
    "sendClipLinesSignal\0"
    "std::vector<std::tuple<int,int,int,int> >\0"
    "lines\0std::tuple<int,int,int,int>\0"
    "rect\0receiveHoverCoordinates\0x\0y\0"
    "receiveClickCoordinates\0"
    "onSetPointOneButtonClicked\0"
    "onSetPointTwoButtonClicked\0"
    "onDrawButtonClicked\0onDrawAllButtonClicked\0"
    "onClearButtonClicked\0"
    "onSetClipPointOneButtonClicked\0"
    "onSetClipPointTwoButtonClicked\0"
    "onClipButtonClicked\0receiveTimeTaken\0"
    "time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   84,    2, 0x06 /* Public */,
       1,    4,   95,    2, 0x26 /* Public | MethodCloned */,
       9,    2,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,  109,    2, 0x0a /* Public */,
      17,    2,  114,    2, 0x0a /* Public */,
      18,    0,  119,    2, 0x0a /* Public */,
      19,    0,  120,    2, 0x0a /* Public */,
      20,    0,  121,    2, 0x0a /* Public */,
      21,    0,  122,    2, 0x0a /* Public */,
      22,    0,  123,    2, 0x0a /* Public */,
      23,    0,  124,    2, 0x0a /* Public */,
      24,    0,  125,    2, 0x0a /* Public */,
      25,    0,  126,    2, 0x0a /* Public */,
      26,    1,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    3,    4,    5,    6,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   27,

       0        // eod
};

void LineMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LineMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDrawLineSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< LineAlgorithms::Algorithm(*)>(_a[5]))); break;
        case 1: _t->sendDrawLineSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->sendClipLinesSignal((*reinterpret_cast< std::vector<std::tuple<int,int,int,int> >(*)>(_a[1])),(*reinterpret_cast< std::tuple<int,int,int,int>(*)>(_a[2]))); break;
        case 3: _t->receiveHoverCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->receiveClickCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onSetPointOneButtonClicked(); break;
        case 6: _t->onSetPointTwoButtonClicked(); break;
        case 7: _t->onDrawButtonClicked(); break;
        case 8: _t->onDrawAllButtonClicked(); break;
        case 9: _t->onClearButtonClicked(); break;
        case 10: _t->onSetClipPointOneButtonClicked(); break;
        case 11: _t->onSetClipPointTwoButtonClicked(); break;
        case 12: _t->onClipButtonClicked(); break;
        case 13: _t->receiveTimeTaken((*reinterpret_cast< const long long(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LineMenu::*)(int , int , int , int , LineAlgorithms::Algorithm );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineMenu::sendDrawLineSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LineMenu::*)(std::vector<std::tuple<int,int,int,int>> , std::tuple<int,int,int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineMenu::sendClipLinesSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LineMenu::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_LineMenu.data,
    qt_meta_data_LineMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LineMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineMenu.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LineMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void LineMenu::sendDrawLineSignal(int _t1, int _t2, int _t3, int _t4, LineAlgorithms::Algorithm _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void LineMenu::sendClipLinesSignal(std::vector<std::tuple<int,int,int,int>> _t1, std::tuple<int,int,int,int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

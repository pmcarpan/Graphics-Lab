/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../graphics_lab/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[48];
    char stringdata0[714];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 21), // "receiveDrawLineSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 2), // "x1"
QT_MOC_LITERAL(4, 33, 2), // "y1"
QT_MOC_LITERAL(5, 36, 2), // "x2"
QT_MOC_LITERAL(6, 39, 2), // "y2"
QT_MOC_LITERAL(7, 42, 25), // "LineAlgorithms::Algorithm"
QT_MOC_LITERAL(8, 68, 4), // "algo"
QT_MOC_LITERAL(9, 73, 23), // "receiveDrawCircleSignal"
QT_MOC_LITERAL(10, 97, 1), // "r"
QT_MOC_LITERAL(11, 99, 27), // "CircleAlgorithms::Algorithm"
QT_MOC_LITERAL(12, 127, 24), // "receiveDrawEllipseSignal"
QT_MOC_LITERAL(13, 152, 1), // "a"
QT_MOC_LITERAL(14, 154, 1), // "b"
QT_MOC_LITERAL(15, 156, 28), // "EllipseAlgorithms::Algorithm"
QT_MOC_LITERAL(16, 185, 24), // "receiveDrawPolygonSignal"
QT_MOC_LITERAL(17, 210, 32), // "std::vector<std::pair<int,int> >"
QT_MOC_LITERAL(18, 243, 8), // "vertices"
QT_MOC_LITERAL(19, 252, 22), // "receiveFloodFillSignal"
QT_MOC_LITERAL(20, 275, 1), // "x"
QT_MOC_LITERAL(21, 277, 1), // "y"
QT_MOC_LITERAL(22, 279, 8), // "oldColor"
QT_MOC_LITERAL(23, 288, 8), // "newColor"
QT_MOC_LITERAL(24, 297, 25), // "receiveBoundaryFillSignal"
QT_MOC_LITERAL(25, 323, 9), // "edgeColor"
QT_MOC_LITERAL(26, 333, 32), // "receiveScanLinePolygonFillSignal"
QT_MOC_LITERAL(27, 366, 22), // "receiveClipLinesSignal"
QT_MOC_LITERAL(28, 389, 41), // "std::vector<std::tuple<int,in..."
QT_MOC_LITERAL(29, 431, 5), // "lines"
QT_MOC_LITERAL(30, 437, 27), // "std::tuple<int,int,int,int>"
QT_MOC_LITERAL(31, 465, 4), // "rect"
QT_MOC_LITERAL(32, 470, 24), // "receiveClipPolygonSignal"
QT_MOC_LITERAL(33, 495, 18), // "receiveScaleSignal"
QT_MOC_LITERAL(34, 514, 2), // "cx"
QT_MOC_LITERAL(35, 517, 2), // "cy"
QT_MOC_LITERAL(36, 520, 18), // "receiveShearSignal"
QT_MOC_LITERAL(37, 539, 19), // "receiveRotateSignal"
QT_MOC_LITERAL(38, 559, 7), // "degrees"
QT_MOC_LITERAL(39, 567, 18), // "std::pair<int,int>"
QT_MOC_LITERAL(40, 586, 5), // "about"
QT_MOC_LITERAL(41, 592, 22), // "receiveTranslateSignal"
QT_MOC_LITERAL(42, 615, 2), // "dx"
QT_MOC_LITERAL(43, 618, 2), // "dy"
QT_MOC_LITERAL(44, 621, 25), // "receiveReflectPointSignal"
QT_MOC_LITERAL(45, 647, 24), // "receiveReflectLineSignal"
QT_MOC_LITERAL(46, 672, 27), // "receiveDrawBezierFullSignal"
QT_MOC_LITERAL(47, 700, 13) // "controlPoints"

    },
    "Widget\0receiveDrawLineSignal\0\0x1\0y1\0"
    "x2\0y2\0LineAlgorithms::Algorithm\0algo\0"
    "receiveDrawCircleSignal\0r\0"
    "CircleAlgorithms::Algorithm\0"
    "receiveDrawEllipseSignal\0a\0b\0"
    "EllipseAlgorithms::Algorithm\0"
    "receiveDrawPolygonSignal\0"
    "std::vector<std::pair<int,int> >\0"
    "vertices\0receiveFloodFillSignal\0x\0y\0"
    "oldColor\0newColor\0receiveBoundaryFillSignal\0"
    "edgeColor\0receiveScanLinePolygonFillSignal\0"
    "receiveClipLinesSignal\0"
    "std::vector<std::tuple<int,int,int,int> >\0"
    "lines\0std::tuple<int,int,int,int>\0"
    "rect\0receiveClipPolygonSignal\0"
    "receiveScaleSignal\0cx\0cy\0receiveShearSignal\0"
    "receiveRotateSignal\0degrees\0"
    "std::pair<int,int>\0about\0"
    "receiveTranslateSignal\0dx\0dy\0"
    "receiveReflectPointSignal\0"
    "receiveReflectLineSignal\0"
    "receiveDrawBezierFullSignal\0controlPoints"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    5,  109,    2, 0x0a /* Public */,
       1,    4,  120,    2, 0x2a /* Public | MethodCloned */,
       9,    4,  129,    2, 0x0a /* Public */,
       9,    3,  138,    2, 0x2a /* Public | MethodCloned */,
      12,    5,  145,    2, 0x0a /* Public */,
      12,    4,  156,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  165,    2, 0x0a /* Public */,
      19,    4,  168,    2, 0x0a /* Public */,
      24,    4,  177,    2, 0x0a /* Public */,
      26,    1,  186,    2, 0x0a /* Public */,
      27,    2,  189,    2, 0x0a /* Public */,
      32,    2,  194,    2, 0x0a /* Public */,
      33,    3,  199,    2, 0x0a /* Public */,
      36,    3,  206,    2, 0x0a /* Public */,
      37,    3,  213,    2, 0x0a /* Public */,
      41,    3,  220,    2, 0x0a /* Public */,
      44,    3,  227,    2, 0x0a /* Public */,
      45,    5,  234,    2, 0x0a /* Public */,
      46,    1,  245,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 7,    3,    4,    5,    6,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,    3,    4,   10,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 15,    3,    4,   13,   14,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   13,   14,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QColor, QMetaType::QColor,   20,   21,   25,   23,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 28, 0x80000000 | 30,   29,   31,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 30,   18,   31,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   34,   35,   18,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   34,   35,   18,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 39, 0x80000000 | 17,   38,   40,   18,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   42,   43,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 17,    3,    4,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 17,    3,    4,    5,    6,   18,
    QMetaType::Void, 0x80000000 | 17,   47,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveDrawLineSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< LineAlgorithms::Algorithm(*)>(_a[5]))); break;
        case 1: _t->receiveDrawLineSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->receiveDrawCircleSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< CircleAlgorithms::Algorithm(*)>(_a[4]))); break;
        case 3: _t->receiveDrawCircleSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->receiveDrawEllipseSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< EllipseAlgorithms::Algorithm(*)>(_a[5]))); break;
        case 5: _t->receiveDrawEllipseSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->receiveDrawPolygonSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 7: _t->receiveFloodFillSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< QColor(*)>(_a[4]))); break;
        case 8: _t->receiveBoundaryFillSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3])),(*reinterpret_cast< QColor(*)>(_a[4]))); break;
        case 9: _t->receiveScanLinePolygonFillSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        case 10: _t->receiveClipLinesSignal((*reinterpret_cast< std::vector<std::tuple<int,int,int,int> >(*)>(_a[1])),(*reinterpret_cast< std::tuple<int,int,int,int>(*)>(_a[2]))); break;
        case 11: _t->receiveClipPolygonSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1])),(*reinterpret_cast< std::tuple<int,int,int,int>(*)>(_a[2]))); break;
        case 12: _t->receiveScaleSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[3]))); break;
        case 13: _t->receiveShearSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[3]))); break;
        case 14: _t->receiveRotateSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< std::pair<int,int>(*)>(_a[2])),(*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[3]))); break;
        case 15: _t->receiveTranslateSignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[3]))); break;
        case 16: _t->receiveReflectPointSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[3]))); break;
        case 17: _t->receiveReflectLineSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[5]))); break;
        case 18: _t->receiveDrawBezierFullSignal((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'QuickTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QuickTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuickTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QuickTool_t {
    QByteArrayData data[14];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuickTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuickTool_t qt_meta_stringdata_QuickTool = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QuickTool"
QT_MOC_LITERAL(1, 10, 9), // "getObject"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "targetObjName"
QT_MOC_LITERAL(4, 35, 17), // "getObjectProperty"
QT_MOC_LITERAL(5, 53, 9), // "targetObj"
QT_MOC_LITERAL(6, 63, 12), // "propertyName"
QT_MOC_LITERAL(7, 76, 17), // "setObjectProperty"
QT_MOC_LITERAL(8, 94, 5), // "value"
QT_MOC_LITERAL(9, 100, 22), // "getItemGeometryToScene"
QT_MOC_LITERAL(10, 123, 20), // "setAppOverrideCursor"
QT_MOC_LITERAL(11, 144, 6), // "cursor"
QT_MOC_LITERAL(12, 151, 24), // "restoreAppOverrideCursor"
QT_MOC_LITERAL(13, 176, 15) // "cursorGlobalPos"

    },
    "QuickTool\0getObject\0\0targetObjName\0"
    "getObjectProperty\0targetObj\0propertyName\0"
    "setObjectProperty\0value\0getItemGeometryToScene\0"
    "setAppOverrideCursor\0cursor\0"
    "restoreAppOverrideCursor\0cursorGlobalPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuickTool[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    2,   62,    2, 0x0a /* Public */,
       7,    3,   67,    2, 0x0a /* Public */,
       4,    2,   74,    2, 0x0a /* Public */,
       7,    3,   79,    2, 0x0a /* Public */,
       9,    1,   86,    2, 0x0a /* Public */,
      10,    1,   89,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::QObjectStar, QMetaType::QString,    3,
    QMetaType::QVariant, QMetaType::QObjectStar, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString, QMetaType::QVariant,    5,    6,    8,
    QMetaType::QVariant, QMetaType::QString, QMetaType::QString,    3,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QVariant,    3,    6,    8,
    QMetaType::QRect, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QCursor,   11,
    QMetaType::Void,
    QMetaType::QPoint,

       0        // eod
};

void QuickTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QuickTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QObject* _r = _t->getObject((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariant _r = _t->getObjectProperty((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setObjectProperty((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 3: { QVariant _r = _t->getObjectProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->setObjectProperty((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 5: { QRect _r = _t->getItemGeometryToScene((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QRect*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setAppOverrideCursor((*reinterpret_cast< QCursor(*)>(_a[1]))); break;
        case 7: _t->restoreAppOverrideCursor(); break;
        case 8: { QPoint _r = _t->cursorGlobalPos();
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QuickTool::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QuickTool.data,
    qt_meta_data_QuickTool,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QuickTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuickTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QuickTool.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QuickTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

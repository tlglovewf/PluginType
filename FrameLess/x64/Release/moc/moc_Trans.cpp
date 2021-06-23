/****************************************************************************
** Meta object code from reading C++ file 'Trans.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Trans.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Trans.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Trans_t {
    QByteArrayData data[19];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Trans_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Trans_t qt_meta_stringdata_Trans = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Trans"
QT_MOC_LITERAL(1, 6, 18), // "currentLangChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "currentLang"
QT_MOC_LITERAL(4, 38, 16), // "languagesChanged"
QT_MOC_LITERAL(5, 55, 9), // "languages"
QT_MOC_LITERAL(6, 65, 10), // "langLoaded"
QT_MOC_LITERAL(7, 76, 4), // "lang"
QT_MOC_LITERAL(8, 81, 12), // "folderLoaded"
QT_MOC_LITERAL(9, 94, 6), // "folder"
QT_MOC_LITERAL(10, 101, 18), // "transStringChanged"
QT_MOC_LITERAL(11, 120, 5), // "trans"
QT_MOC_LITERAL(12, 126, 6), // "source"
QT_MOC_LITERAL(13, 133, 14), // "setCurrentLang"
QT_MOC_LITERAL(14, 148, 10), // "loadFolder"
QT_MOC_LITERAL(15, 159, 4), // "load"
QT_MOC_LITERAL(16, 164, 8), // "QString&"
QT_MOC_LITERAL(17, 173, 8), // "filePath"
QT_MOC_LITERAL(18, 182, 11) // "transString"

    },
    "Trans\0currentLangChanged\0\0currentLang\0"
    "languagesChanged\0languages\0langLoaded\0"
    "lang\0folderLoaded\0folder\0transStringChanged\0"
    "trans\0source\0setCurrentLang\0loadFolder\0"
    "load\0QString&\0filePath\0transString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Trans[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,
      10,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   72,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      14,    1,   78,    2, 0x02 /* Public */,
      15,    2,   81,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QString, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Bool, 0x80000000 | 16, QMetaType::QString,    7,   17,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QStringList, 0x00495001,
      18, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       4,

       0        // eod
};

void Trans::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Trans *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentLangChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->languagesChanged((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->langLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->folderLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->transStringChanged(); break;
        case 5: { QString _r = _t->trans((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setCurrentLang((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->loadFolder((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { bool _r = _t->load((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Trans::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trans::currentLangChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Trans::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trans::languagesChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Trans::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trans::langLoaded)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Trans::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trans::folderLoaded)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Trans::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Trans::transStringChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Trans *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->currentLang(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->languages(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->transString(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Trans *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentLang(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Trans::staticMetaObject = { {
    &QTranslator::staticMetaObject,
    qt_meta_stringdata_Trans.data,
    qt_meta_data_Trans,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Trans::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Trans::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Trans.stringdata0))
        return static_cast<void*>(this);
    return QTranslator::qt_metacast(_clname);
}

int Trans::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTranslator::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Trans::currentLangChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Trans::languagesChanged(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Trans::langLoaded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Trans::folderLoaded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Trans::transStringChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

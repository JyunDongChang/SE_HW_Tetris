/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_view_t {
    QByteArrayData data[4];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_t qt_meta_stringdata_view = {
    {
QT_MOC_LITERAL(0, 0, 4), // "view"
QT_MOC_LITERAL(1, 5, 12), // "scoreChanged"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5) // "score"

    },
    "view\0scoreChanged\0\0score"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        view *_t = static_cast<view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scoreChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (view::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&view::scoreChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject view::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_view.data,
      qt_meta_data_view,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void view::scoreChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_view_1_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_1_t qt_meta_stringdata_view_1 = {
    {
QT_MOC_LITERAL(0, 0, 6) // "view_1"

    },
    "view_1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view_1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void view_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject view_1::staticMetaObject = {
    { &view::staticMetaObject, qt_meta_stringdata_view_1.data,
      qt_meta_data_view_1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view_1.stringdata0))
        return static_cast<void*>(this);
    return view::qt_metacast(_clname);
}

int view_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = view::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_view_2_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_2_t qt_meta_stringdata_view_2 = {
    {
QT_MOC_LITERAL(0, 0, 6) // "view_2"

    },
    "view_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view_2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void view_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject view_2::staticMetaObject = {
    { &view::staticMetaObject, qt_meta_stringdata_view_2.data,
      qt_meta_data_view_2,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view_2.stringdata0))
        return static_cast<void*>(this);
    return view::qt_metacast(_clname);
}

int view_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = view::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_view_3_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_3_t qt_meta_stringdata_view_3 = {
    {
QT_MOC_LITERAL(0, 0, 6) // "view_3"

    },
    "view_3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view_3[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void view_3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject view_3::staticMetaObject = {
    { &view::staticMetaObject, qt_meta_stringdata_view_3.data,
      qt_meta_data_view_3,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view_3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view_3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view_3.stringdata0))
        return static_cast<void*>(this);
    return view::qt_metacast(_clname);
}

int view_3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = view::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_view_4_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_4_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_4_t qt_meta_stringdata_view_4 = {
    {
QT_MOC_LITERAL(0, 0, 6) // "view_4"

    },
    "view_4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view_4[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void view_4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject view_4::staticMetaObject = {
    { &view::staticMetaObject, qt_meta_stringdata_view_4.data,
      qt_meta_data_view_4,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view_4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view_4::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view_4.stringdata0))
        return static_cast<void*>(this);
    return view::qt_metacast(_clname);
}

int view_4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = view::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_view_5_t {
    QByteArrayData data[1];
    char stringdata0[7];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_5_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_5_t qt_meta_stringdata_view_5 = {
    {
QT_MOC_LITERAL(0, 0, 6) // "view_5"

    },
    "view_5"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view_5[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void view_5::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject view_5::staticMetaObject = {
    { &view::staticMetaObject, qt_meta_stringdata_view_5.data,
      qt_meta_data_view_5,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view_5::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view_5::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view_5.stringdata0))
        return static_cast<void*>(this);
    return view::qt_metacast(_clname);
}

int view_5::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = view::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

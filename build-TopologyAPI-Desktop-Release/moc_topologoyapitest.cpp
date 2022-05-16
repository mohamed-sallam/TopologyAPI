/****************************************************************************
** Meta object code from reading C++ file 'topologoyapitest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test/topologoyapitest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'topologoyapitest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TopologoyAPITest_t {
    QByteArrayData data[10];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TopologoyAPITest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TopologoyAPITest_t qt_meta_stringdata_TopologoyAPITest = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TopologoyAPITest"
QT_MOC_LITERAL(1, 17, 7), // "cleanup"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 31), // "readTopologyShouldEqualGivenOne"
QT_MOC_LITERAL(4, 58, 47), // "shouldSaveJsonFileWithSameTop..."
QT_MOC_LITERAL(5, 106, 33), // "queriedDevicesShouldEqualGive..."
QT_MOC_LITERAL(6, 140, 30), // "deletedTopologyShouldBeUnfound"
QT_MOC_LITERAL(7, 171, 36), // "queriedTopologiesShouldEqualG..."
QT_MOC_LITERAL(8, 208, 53), // "queriedDevicesWithNetlistNode..."
QT_MOC_LITERAL(9, 262, 48) // "queriedDevicesWithNetlistNode..."

    },
    "TopologoyAPITest\0cleanup\0\0"
    "readTopologyShouldEqualGivenOne\0"
    "shouldSaveJsonFileWithSameTopologyOfProvidedOne\0"
    "queriedDevicesShouldEqualGivenOne\0"
    "deletedTopologyShouldBeUnfound\0"
    "queriedTopologiesShouldEqualGivenOne\0"
    "queriedDevicesWithNetlistNodeShouldEqualGivenOne_data\0"
    "queriedDevicesWithNetlistNodeShouldEqualGivenOne"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TopologoyAPITest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
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

void TopologoyAPITest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TopologoyAPITest *_t = static_cast<TopologoyAPITest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cleanup(); break;
        case 1: _t->readTopologyShouldEqualGivenOne(); break;
        case 2: _t->shouldSaveJsonFileWithSameTopologyOfProvidedOne(); break;
        case 3: _t->queriedDevicesShouldEqualGivenOne(); break;
        case 4: _t->deletedTopologyShouldBeUnfound(); break;
        case 5: _t->queriedTopologiesShouldEqualGivenOne(); break;
        case 6: _t->queriedDevicesWithNetlistNodeShouldEqualGivenOne_data(); break;
        case 7: _t->queriedDevicesWithNetlistNodeShouldEqualGivenOne(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject TopologoyAPITest::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TopologoyAPITest.data,
      qt_meta_data_TopologoyAPITest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TopologoyAPITest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TopologoyAPITest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TopologoyAPITest.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TopologoyAPITest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

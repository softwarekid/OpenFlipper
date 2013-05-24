/****************************************************************************
** Meta object code from reading C++ file 'configValue.hh'
**
** Created: Sat May 18 02:59:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/config/configValue.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configValue.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__ConfigValue[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   29,   29,   29, 0x08,
      30,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VSI__ConfigValue[] = {
    "VSI::ConfigValue\0toDefault()\0\0"
    "selectionChange()\0"
};

void VSI::ConfigValue::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfigValue *_t = static_cast<ConfigValue *>(_o);
        switch (_id) {
        case 0: _t->toDefault(); break;
        case 1: _t->selectionChange(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VSI::ConfigValue::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::ConfigValue::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VSI__ConfigValue,
      qt_meta_data_VSI__ConfigValue, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::ConfigValue::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::ConfigValue::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::ConfigValue::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__ConfigValue))
        return static_cast<void*>(const_cast< ConfigValue*>(this));
    return QObject::qt_metacast(_clname);
}

int VSI::ConfigValue::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

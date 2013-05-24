/****************************************************************************
** Meta object code from reading C++ file 'prototypeMatrix4x4.hh'
**
** Created: Sat May 18 02:52:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/Scripting/scriptPrototypes/prototypeMatrix4x4.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prototypeMatrix4x4.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_prototypeMatrix4x4[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   50,   58,   71, 0x0a,
      72,   50,   58,   71, 0x0a,
     102,   71,  113,   71, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_prototypeMatrix4x4[] = {
    "prototypeMatrix4x4\0transform_vector(QScriptValue)\0"
    "_vector\0QScriptValue\0\0"
    "transform_point(QScriptValue)\0toString()\0"
    "QString\0"
};

void prototypeMatrix4x4::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        prototypeMatrix4x4 *_t = static_cast<prototypeMatrix4x4 *>(_o);
        switch (_id) {
        case 0: { QScriptValue _r = _t->transform_vector((*reinterpret_cast< QScriptValue(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 1: { QScriptValue _r = _t->transform_point((*reinterpret_cast< QScriptValue(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->toString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData prototypeMatrix4x4::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject prototypeMatrix4x4::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_prototypeMatrix4x4,
      qt_meta_data_prototypeMatrix4x4, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &prototypeMatrix4x4::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *prototypeMatrix4x4::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *prototypeMatrix4x4::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_prototypeMatrix4x4))
        return static_cast<void*>(const_cast< prototypeMatrix4x4*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< prototypeMatrix4x4*>(this));
    return QObject::qt_metacast(_clname);
}

int prototypeMatrix4x4::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

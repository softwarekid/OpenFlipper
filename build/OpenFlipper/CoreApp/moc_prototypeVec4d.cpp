/****************************************************************************
** Meta object code from reading C++ file 'prototypeVec4d.hh'
**
** Created: Sat May 18 02:52:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/Scripting/scriptPrototypes/prototypeVec4d.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prototypeVec4d.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_prototypeVec4d[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   38,   46,   46, 0x0a,
      47,   65,   46,   46, 0x0a,
      73,   65,   46,   46, 0x0a,
      91,   46,   46,   46, 0x0a,
      98,   65,  118,   46, 0x0a,
     131,   46,  118,   46, 0x0a,
     138,   46,  118,   46, 0x0a,
     148,   46,   46,   46, 0x0a,
     160,   46,  171,   46, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_prototypeVec4d[] = {
    "prototypeVec4d\0multiply(QScriptValue)\0"
    "_scalar\0\0add(QScriptValue)\0_vector\0"
    "sub(QScriptValue)\0zero()\0sprod(QScriptValue)\0"
    "QScriptValue\0norm()\0sqrnorm()\0normalize()\0"
    "toString()\0QString\0"
};

void prototypeVec4d::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        prototypeVec4d *_t = static_cast<prototypeVec4d *>(_o);
        switch (_id) {
        case 0: _t->multiply((*reinterpret_cast< QScriptValue(*)>(_a[1]))); break;
        case 1: _t->add((*reinterpret_cast< QScriptValue(*)>(_a[1]))); break;
        case 2: _t->sub((*reinterpret_cast< QScriptValue(*)>(_a[1]))); break;
        case 3: _t->zero(); break;
        case 4: { QScriptValue _r = _t->sprod((*reinterpret_cast< QScriptValue(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 5: { QScriptValue _r = _t->norm();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 6: { QScriptValue _r = _t->sqrnorm();
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 7: _t->normalize(); break;
        case 8: { QString _r = _t->toString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData prototypeVec4d::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject prototypeVec4d::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_prototypeVec4d,
      qt_meta_data_prototypeVec4d, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &prototypeVec4d::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *prototypeVec4d::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *prototypeVec4d::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_prototypeVec4d))
        return static_cast<void*>(const_cast< prototypeVec4d*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< prototypeVec4d*>(this));
    return QObject::qt_metacast(_clname);
}

int prototypeVec4d::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

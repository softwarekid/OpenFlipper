/****************************************************************************
** Meta object code from reading C++ file 'Scripting.hh'
**
** Created: Sat May 18 02:52:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/Scripting/Scripting.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scripting.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScriptingWrapper[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   45,   71,   71, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,   96,   71,   71, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ScriptingWrapper[] = {
    "ScriptingWrapper\0scriptInfo(QString,QString)\0"
    "_pluginName,_functionName\0\0"
    "slotScriptInfo(QString)\0_functionName\0"
};

void ScriptingWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScriptingWrapper *_t = static_cast<ScriptingWrapper *>(_o);
        switch (_id) {
        case 0: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slotScriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ScriptingWrapper::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScriptingWrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScriptingWrapper,
      qt_meta_data_ScriptingWrapper, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScriptingWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScriptingWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScriptingWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptingWrapper))
        return static_cast<void*>(const_cast< ScriptingWrapper*>(this));
    return QObject::qt_metacast(_clname);
}

int ScriptingWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ScriptingWrapper::scriptInfo(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

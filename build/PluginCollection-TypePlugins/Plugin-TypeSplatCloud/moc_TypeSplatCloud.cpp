/****************************************************************************
** Meta object code from reading C++ file 'TypeSplatCloud.hh'
**
** Created: Sat May 18 03:04:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-TypePlugins/Plugin-TypeSplatCloud/TypeSplatCloud.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TypeSplatCloud.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeSplatCloudPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   43,   53,   53, 0x05,
      54,   84,   53,   53, 0x05,
     100,   43,   53,   53, 0x05,
     118,  131,   53,   53, 0x05,
     140,  161,   53,   53, 0x05,

 // slots: signature, parameters, type, tag, flags
     176,   53,  186,   53, 0x0a,
     194,   53,  205,   53, 0x0a,
     209,   53,  225,   53, 0x0a,
     234,  273,   53,   53, 0x0a,
     295,   53,   53,   53, 0x08,
     312,   53,   53,   53, 0x08,
     330,   43,   53,   53, 0x08,
     363,  397,   53,   53, 0x08,
     419,   43,   53,   53, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TypeSplatCloudPlugin[] = {
    "TypeSplatCloudPlugin\0emptyObjectAdded(int)\0"
    "_objectId\0\0addEmptyObject(DataType,int&)\0"
    "_type,_objectId\0deleteObject(int)\0"
    "log(QString)\0_message\0log(Logtype,QString)\0"
    "_type,_message\0version()\0QString\0"
    "addEmpty()\0int\0supportedType()\0DataType\0"
    "generateBackup(int,QString,UpdateType)\0"
    "_objectId,_name,_type\0noguiSupported()\0"
    "slotViewChanged()\0slotObjectPropertiesChanged(int)\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "_objectId,_updateType\0objectDeleted(int)\0"
};

void TypeSplatCloudPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypeSplatCloudPlugin *_t = static_cast<TypeSplatCloudPlugin *>(_o);
        switch (_id) {
        case 0: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->addEmpty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { DataType _r = _t->supportedType();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 8: _t->generateBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 9: _t->noguiSupported(); break;
        case 10: _t->slotViewChanged(); break;
        case 11: _t->slotObjectPropertiesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 13: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypeSplatCloudPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypeSplatCloudPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TypeSplatCloudPlugin,
      qt_meta_data_TypeSplatCloudPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeSplatCloudPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeSplatCloudPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeSplatCloudPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeSplatCloudPlugin))
        return static_cast<void*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "TypeInterface"))
        return static_cast< TypeInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TypeInterface/1.1"))
        return static_cast< TypeInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< TypeSplatCloudPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TypeSplatCloudPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void TypeSplatCloudPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeSplatCloudPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TypeSplatCloudPlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TypeSplatCloudPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TypeSplatCloudPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

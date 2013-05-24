/****************************************************************************
** Meta object code from reading C++ file 'TypeTriangleMesh.hh'
**
** Created: Sat May 18 03:04:38 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-TypePlugins/Plugin-TypeTriangleMesh/TypeTriangleMesh.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TypeTriangleMesh.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeTriangleMeshPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   44,   59,   59, 0x05,
      60,   73,   59,   59, 0x05,
      82,  104,   59,   59, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   59,   59,   59, 0x08,
     125,   59,  135,   59, 0x0a,
     143,   59,  154,   59, 0x0a,
     158,   59,  174,   59, 0x0a,
     183,  222,   59,   59, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TypeTriangleMeshPlugin[] = {
    "TypeTriangleMeshPlugin\0log(Logtype,QString)\0"
    "_type,_message\0\0log(QString)\0_message\0"
    "emptyObjectAdded(int)\0_id\0noguiSupported()\0"
    "version()\0QString\0addEmpty()\0int\0"
    "supportedType()\0DataType\0"
    "generateBackup(int,QString,UpdateType)\0"
    "_id,_name,_type\0"
};

void TypeTriangleMeshPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypeTriangleMeshPlugin *_t = static_cast<TypeTriangleMeshPlugin *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->noguiSupported(); break;
        case 4: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->addEmpty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { DataType _r = _t->supportedType();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 7: _t->generateBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypeTriangleMeshPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypeTriangleMeshPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TypeTriangleMeshPlugin,
      qt_meta_data_TypeTriangleMeshPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeTriangleMeshPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeTriangleMeshPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeTriangleMeshPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeTriangleMeshPlugin))
        return static_cast<void*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "TypeInterface"))
        return static_cast< TypeInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TypeInterface/1.1"))
        return static_cast< TypeInterface*>(const_cast< TypeTriangleMeshPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TypeTriangleMeshPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TypeTriangleMeshPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeTriangleMeshPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TypeTriangleMeshPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

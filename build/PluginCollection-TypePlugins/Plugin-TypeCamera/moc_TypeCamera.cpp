/****************************************************************************
** Meta object code from reading C++ file 'TypeCamera.hh'
**
** Created: Sat May 18 03:03:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-TypePlugins/Plugin-TypeCamera/TypeCamera.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TypeCamera.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeCameraPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   38,   53,   53, 0x05,
      54,   67,   53,   53, 0x05,
      76,   98,   53,   53, 0x05,
     102,  147,   53,   53, 0x05,
     161,  215,   53,   53, 0x05,

 // slots: signature, parameters, type, tag, flags
     241,   53,   53,   53, 0x08,
     258,   53,   53,   53, 0x08,
     279,  312,   53,   53, 0x08,
     322,   53,  332,   53, 0x0a,
     340,   53,  351,   53, 0x0a,
     355,   53,  371,   53, 0x0a,
     380,  409,   53,   53, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TypeCameraPlugin[] = {
    "TypeCameraPlugin\0log(Logtype,QString)\0"
    "_type,_message\0\0log(QString)\0_message\0"
    "emptyObjectAdded(int)\0_id\0"
    "addContextMenuItem(QAction*,ContextMenuType)\0"
    "_action,_type\0"
    "addContextMenuItem(QAction*,DataType,ContextMenuType)\0"
    "_action,_objectType,_type\0noguiSupported()\0"
    "pluginsInitialized()\0"
    "slotUpdateContextMenuObject(int)\0"
    "_objectId\0version()\0QString\0addEmpty()\0"
    "int\0supportedType()\0DataType\0"
    "contextMenuClicked(QAction*)\0"
    "_contextAction\0"
};

void TypeCameraPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypeCameraPlugin *_t = static_cast<TypeCameraPlugin *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< ContextMenuType(*)>(_a[2]))); break;
        case 4: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< ContextMenuType(*)>(_a[3]))); break;
        case 5: _t->noguiSupported(); break;
        case 6: _t->pluginsInitialized(); break;
        case 7: _t->slotUpdateContextMenuObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->addEmpty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { DataType _r = _t->supportedType();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 11: _t->contextMenuClicked((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypeCameraPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypeCameraPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TypeCameraPlugin,
      qt_meta_data_TypeCameraPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeCameraPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeCameraPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeCameraPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeCameraPlugin))
        return static_cast<void*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "TypeInterface"))
        return static_cast< TypeInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TypeInterface/1.1"))
        return static_cast< TypeInterface*>(const_cast< TypeCameraPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< TypeCameraPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TypeCameraPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TypeCameraPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeCameraPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TypeCameraPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TypeCameraPlugin::addContextMenuItem(QAction * _t1, ContextMenuType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TypeCameraPlugin::addContextMenuItem(QAction * _t1, DataType _t2, ContextMenuType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'TypeHexahedralMesh.hh'
**
** Created: Sat May 18 03:03:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-TypePlugins/Plugin-TypeHexahedralMesh/TypeHexahedralMesh.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TypeHexahedralMesh.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeHexahedralMeshPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   46,   61,   61, 0x05,
      62,   75,   61,   61, 0x05,
      84,  106,   61,   61, 0x05,
     110,  164,   61,   61, 0x05,
     167,  197,   61,   61, 0x05,

 // slots: signature, parameters, type, tag, flags
     210,  233,   61,   61, 0x08,
     245,  233,   61,   61, 0x08,
     264,   61,   61,   61, 0x08,
     281,   61,   61,   61, 0x08,
     302,  327,   61,   61, 0x08,
     334,  361,   61,   61, 0x08,
     371,   61,   61,   61, 0x08,
     395,  438,   61,   61, 0x08,
     453,   61,   61,   61, 0x28,
     493,   61,   61,   61, 0x08,
     511,   61,   61,   61, 0x08,
     535,   61,  545,   61, 0x0a,
     553,   61,  564,   61, 0x0a,
     568,   61,  584,   61, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TypeHexahedralMeshPlugin[] = {
    "TypeHexahedralMeshPlugin\0log(Logtype,QString)\0"
    "_type,_message\0\0log(QString)\0_message\0"
    "emptyObjectAdded(int)\0_id\0"
    "addContextMenuItem(QAction*,DataType,ContextMenuType)\0"
    ",,\0updatedObject(int,UpdateType)\0"
    "_objId,_type\0slotObjectUpdated(int)\0"
    "_identifier\0objectDeleted(int)\0"
    "noguiSupported()\0pluginsInitialized()\0"
    "slotKeyEvent(QKeyEvent*)\0_event\0"
    "slotUpdateContextMenu(int)\0_objectId\0"
    "slot_change_shrinkage()\0"
    "slot_update_planes_in_scenegraph_node(int)\0"
    "_deletedObject\0slot_update_planes_in_scenegraph_node()\0"
    "switchRendering()\0setTranslucencyFactor()\0"
    "version()\0QString\0addEmpty()\0int\0"
    "supportedType()\0DataType\0"
};

void TypeHexahedralMeshPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypeHexahedralMeshPlugin *_t = static_cast<TypeHexahedralMeshPlugin *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< ContextMenuType(*)>(_a[3]))); break;
        case 4: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 5: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->noguiSupported(); break;
        case 8: _t->pluginsInitialized(); break;
        case 9: _t->slotKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 10: _t->slotUpdateContextMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slot_change_shrinkage(); break;
        case 12: _t->slot_update_planes_in_scenegraph_node((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->slot_update_planes_in_scenegraph_node(); break;
        case 14: _t->switchRendering(); break;
        case 15: _t->setTranslucencyFactor(); break;
        case 16: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 17: { int _r = _t->addEmpty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: { DataType _r = _t->supportedType();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypeHexahedralMeshPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypeHexahedralMeshPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TypeHexahedralMeshPlugin,
      qt_meta_data_TypeHexahedralMeshPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeHexahedralMeshPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeHexahedralMeshPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeHexahedralMeshPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeHexahedralMeshPlugin))
        return static_cast<void*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "TypeInterface"))
        return static_cast< TypeInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TypeInterface/1.1"))
        return static_cast< TypeInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< TypeHexahedralMeshPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TypeHexahedralMeshPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void TypeHexahedralMeshPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeHexahedralMeshPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TypeHexahedralMeshPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TypeHexahedralMeshPlugin::addContextMenuItem(QAction * _t1, DataType _t2, ContextMenuType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TypeHexahedralMeshPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

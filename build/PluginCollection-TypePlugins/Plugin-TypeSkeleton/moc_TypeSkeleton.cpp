/****************************************************************************
** Meta object code from reading C++ file 'TypeSkeleton.hh'
**
** Created: Sat May 18 03:04:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-TypePlugins/Plugin-TypeSkeleton/TypeSkeleton.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TypeSkeleton.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeSkeletonPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   40,   55,   55, 0x05,
      56,   69,   55,   55, 0x05,
      78,  100,   55,   55, 0x05,
     104,  149,   55,   55, 0x05,
     163,  217,   55,   55, 0x05,

 // slots: signature, parameters, type, tag, flags
     243,   55,   55,   55, 0x08,
     264,   55,   55,   55, 0x08,
     281,  308,   55,   55, 0x08,
     318,   55,   55,   55, 0x08,
     336,   55,   55,   55, 0x08,
     358,   55,   55,   55, 0x08,
     379,   55,  389,   55, 0x0a,
     397,   55,  408,   55, 0x0a,
     412,   55,  428,   55, 0x0a,
     437,  476,   55,   55, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TypeSkeletonPlugin[] = {
    "TypeSkeletonPlugin\0log(Logtype,QString)\0"
    "_type,_message\0\0log(QString)\0_message\0"
    "emptyObjectAdded(int)\0_id\0"
    "addContextMenuItem(QAction*,ContextMenuType)\0"
    "_action,_type\0"
    "addContextMenuItem(QAction*,DataType,ContextMenuType)\0"
    "_action,_objectType,_type\0"
    "pluginsInitialized()\0noguiSupported()\0"
    "slotUpdateContextMenu(int)\0_objectId\0"
    "slotShowIndices()\0slotShowCoordFrames()\0"
    "slotShowMotionPath()\0version()\0QString\0"
    "addEmpty()\0int\0supportedType()\0DataType\0"
    "generateBackup(int,QString,UpdateType)\0"
    "_id,_name,_type\0"
};

void TypeSkeletonPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypeSkeletonPlugin *_t = static_cast<TypeSkeletonPlugin *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< ContextMenuType(*)>(_a[2]))); break;
        case 4: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< ContextMenuType(*)>(_a[3]))); break;
        case 5: _t->pluginsInitialized(); break;
        case 6: _t->noguiSupported(); break;
        case 7: _t->slotUpdateContextMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotShowIndices(); break;
        case 9: _t->slotShowCoordFrames(); break;
        case 10: _t->slotShowMotionPath(); break;
        case 11: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->addEmpty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { DataType _r = _t->supportedType();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 14: _t->generateBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypeSkeletonPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypeSkeletonPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TypeSkeletonPlugin,
      qt_meta_data_TypeSkeletonPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeSkeletonPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeSkeletonPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeSkeletonPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeSkeletonPlugin))
        return static_cast<void*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "TypeInterface"))
        return static_cast< TypeInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TypeInterface/1.1"))
        return static_cast< TypeInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< TypeSkeletonPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TypeSkeletonPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TypeSkeletonPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeSkeletonPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TypeSkeletonPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TypeSkeletonPlugin::addContextMenuItem(QAction * _t1, ContextMenuType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TypeSkeletonPlugin::addContextMenuItem(QAction * _t1, DataType _t2, ContextMenuType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

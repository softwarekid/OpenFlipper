/****************************************************************************
** Meta object code from reading C++ file 'VolumeMeshObjectInfoPlugin.hh'
**
** Created: Sat May 18 02:55:58 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-InfoVolumeMeshObject/VolumeMeshObjectInfoPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VolumeMeshObjectInfoPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InfoVolumeMeshObjectPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   87,  140,  140, 0x05,
     141,  162,  140,  140, 0x05,
     177,  190,  140,  140, 0x05,

 // slots: signature, parameters, type, tag, flags
     199,  140,  140,  140, 0x08,
     218,  140,  140,  140, 0x08,
     239,  273,  140,  140, 0x08,
     291,  323,  140,  140, 0x08,
     335,  140,  140,  140, 0x08,
     352,  140,  140,  140, 0x08,
     369,  386,  390,  140, 0x0a,
     394,  386,  390,  140, 0x0a,
     409,  386,  390,  140, 0x0a,
     424,  386,  390,  140, 0x0a,
     439,  140,  449,  140, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InfoVolumeMeshObjectPlugin[] = {
    "InfoVolumeMeshObjectPlugin\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "\0log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0initializePlugin()\0"
    "pluginsInitialized()\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "_identifier,_type\0slotObjectSelectionChanged(int)\0"
    "_identifier\0slotAllCleared()\0"
    "noguiSupported()\0vertexCount(int)\0_id\0"
    "int\0edgeCount(int)\0faceCount(int)\0"
    "cellCount(int)\0version()\0QString\0"
};

void InfoVolumeMeshObjectPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InfoVolumeMeshObjectPlugin *_t = static_cast<InfoVolumeMeshObjectPlugin *>(_o);
        switch (_id) {
        case 0: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 1: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->initializePlugin(); break;
        case 4: _t->pluginsInitialized(); break;
        case 5: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 6: _t->slotObjectSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->slotAllCleared(); break;
        case 8: _t->noguiSupported(); break;
        case 9: { int _r = _t->vertexCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->edgeCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->faceCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->cellCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InfoVolumeMeshObjectPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InfoVolumeMeshObjectPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InfoVolumeMeshObjectPlugin,
      qt_meta_data_InfoVolumeMeshObjectPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InfoVolumeMeshObjectPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InfoVolumeMeshObjectPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InfoVolumeMeshObjectPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoVolumeMeshObjectPlugin))
        return static_cast<void*>(const_cast< InfoVolumeMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< InfoVolumeMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< InfoVolumeMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< InfoVolumeMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< InfoVolumeMeshObjectPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int InfoVolumeMeshObjectPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void InfoVolumeMeshObjectPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InfoVolumeMeshObjectPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InfoVolumeMeshObjectPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

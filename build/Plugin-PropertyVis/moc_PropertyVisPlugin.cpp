/****************************************************************************
** Meta object code from reading C++ file 'PropertyVisPlugin.hh'
**
** Created: Sat May 18 02:57:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/PropertyVisPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PropertyVisPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PropertyVisPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   31,   31,   31, 0x05,
      32,   62,   31,   31, 0x05,
      64,   62,   31,   31, 0x05,
      85,   31,   31,   31, 0x05,
      98,  134,   31,   31, 0x05,
     154,  185,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     191,  225,   31,   31, 0x08,
     243,   31,   31,   31, 0x08,
     260,  279,   31,   31, 0x08,
     283,   31,   31,   31, 0x08,
     302,   31,   31,   31, 0x08,
     323,  344,   31,   31, 0x08,
     351,   31,   31,   31, 0x28,
     369,   31,   31,   31, 0x08,
     385,  414,   31,   31, 0x08,
     421,  185,   31,   31, 0x08,
     454,   31,   31,   31, 0x08,
     466,   31,   31,   31, 0x08,
     493,   31,   31,   31, 0x08,
     517,   31,   31,   31, 0x08,
     538,  563,   31,   31, 0x08,
     578,  595,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PropertyVisPlugin[] = {
    "PropertyVisPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0,\0"
    "log(Logtype,QString)\0log(QString)\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0addHiddenPickMode(std::string)\0"
    "_mode\0slotObjectUpdated(int,UpdateType)\0"
    "_identifier,_type\0slotAllCleared()\0"
    "objectDeleted(int)\0_id\0initializePlugin()\0"
    "pluginsInitialized()\0slotMeshChanged(int)\0"
    "_index\0slotMeshChanged()\0slotVisualize()\0"
    "slotMouseEvent(QMouseEvent*)\0_event\0"
    "slotPickModeChanged(std::string)\0"
    "updateGUI()\0propertySelectionChanged()\0"
    "slotDuplicateProperty()\0slotRemoveProperty()\0"
    "slotLog(Logtype,QString)\0_type,_message\0"
    "slotLog(QString)\0_message\0"
};

void PropertyVisPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropertyVisPlugin *_t = static_cast<PropertyVisPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 5: _t->addHiddenPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 6: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 7: _t->slotAllCleared(); break;
        case 8: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->initializePlugin(); break;
        case 10: _t->pluginsInitialized(); break;
        case 11: _t->slotMeshChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotMeshChanged(); break;
        case 13: _t->slotVisualize(); break;
        case 14: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 15: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 16: _t->updateGUI(); break;
        case 17: _t->propertySelectionChanged(); break;
        case 18: _t->slotDuplicateProperty(); break;
        case 19: _t->slotRemoveProperty(); break;
        case 20: _t->slotLog((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: _t->slotLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PropertyVisPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PropertyVisPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PropertyVisPlugin,
      qt_meta_data_PropertyVisPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PropertyVisPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PropertyVisPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PropertyVisPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PropertyVisPlugin))
        return static_cast<void*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< PropertyVisPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< PropertyVisPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PropertyVisPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void PropertyVisPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PropertyVisPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PropertyVisPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PropertyVisPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PropertyVisPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PropertyVisPlugin::addHiddenPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

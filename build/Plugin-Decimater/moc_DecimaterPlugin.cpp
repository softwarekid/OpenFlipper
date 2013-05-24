/****************************************************************************
** Meta object code from reading C++ file 'DecimaterPlugin.hh'
**
** Created: Sat May 18 02:55:25 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Decimater/DecimaterPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DecimaterPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DecimaterPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   29,   29,   29, 0x05,
      30,   60,   29,   29, 0x05,
      70,  130,   29,   29, 0x05,
     183,  204,   29,   29, 0x05,
     219,  232,   29,   29, 0x05,
     241,  269,   29,   29, 0x05,
     289,  327,   29,   29, 0x05,
     361,  397,   29,   29, 0x05,
     417,  437,   29,   29, 0x05,
     451,  488,   29,   29, 0x05,
     504,  530,   29,   29, 0x25,

 // slots: signature, parameters, type, tag, flags
     540,   29,   29,   29, 0x08,
     559,   29,   29,   29, 0x08,
     580,  614,   29,   29, 0x08,
     632,  664,   29,   29, 0x08,
     676,  695,   29,   29, 0x08,
     699,  695,   29,   29, 0x08,
     723,   29,   29,   29, 0x08,
     740,   29,   29,   29, 0x08,
     756,   29,   29,   29, 0x08,
     774,  799,   29,   29, 0x08,
     806,  799,   29,   29, 0x08,
     834,  799,   29,   29, 0x08,
     861,  799,   29,   29, 0x08,
     891,   29,   29,   29, 0x08,
     912,   29,   29,   29, 0x08,
     934,   29,   29,   29, 0x08,
     955,   29,   29,   29, 0x08,
     977,   29,   29,   29, 0x08,
    1000,   29,   29,   29, 0x08,
    1024,   29,   29,   29, 0x08,
    1049,   29,   29,   29, 0x08,
    1086,   29,   29,   29, 0x08,
    1119,   29,   29,   29, 0x08,
    1143, 1169,   29,   29, 0x0a,
    1189,   29, 1199,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DecimaterPlugin[] = {
    "DecimaterPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0"
    "functionExists(QString,QString,bool&)\0"
    "_pluginName,_functionName,_exists\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0scriptInfo(QString)\0"
    "_functionName\0createBackup(int,QString,UpdateType)\0"
    "_id,_name,_type\0createBackup(int,QString)\0"
    "_id,_name\0initializePlugin()\0"
    "pluginsInitialized()\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "_identifier,_type\0slotObjectSelectionChanged(int)\0"
    "_identifier\0objectDeleted(int)\0_id\0"
    "slotAboutToRestore(int)\0noguiSupported()\0"
    "slot_decimate()\0slot_initialize()\0"
    "slotUpdateRoundness(int)\0_value\0"
    "slotUpdateRoundness(double)\0"
    "slotUpdateAspectRatio(int)\0"
    "slotUpdateAspectRatio(double)\0"
    "slotUpdateDistance()\0slotUpdateNormalDev()\0"
    "slotUpdateVertices()\0slotUpdateTriangles()\0"
    "slotUpdateEdgeLength()\0slotUpdateNumVertices()\0"
    "slotUpdateNumTriangles()\0"
    "slotMixedCounterValueChanged(double)\0"
    "slotMixedSliderValueChanged(int)\0"
    "slotDisableDecimation()\0"
    "decimate(int,QVariantMap)\0_objID,_constraints\0"
    "version()\0QString\0"
};

void DecimaterPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DecimaterPlugin *_t = static_cast<DecimaterPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 3: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->pluginExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->functionExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 8: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 10: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->initializePlugin(); break;
        case 12: _t->pluginsInitialized(); break;
        case 13: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 14: _t->slotObjectSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slotAboutToRestore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->noguiSupported(); break;
        case 18: _t->slot_decimate(); break;
        case 19: _t->slot_initialize(); break;
        case 20: _t->slotUpdateRoundness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->slotUpdateRoundness((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->slotUpdateAspectRatio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->slotUpdateAspectRatio((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->slotUpdateDistance(); break;
        case 25: _t->slotUpdateNormalDev(); break;
        case 26: _t->slotUpdateVertices(); break;
        case 27: _t->slotUpdateTriangles(); break;
        case 28: _t->slotUpdateEdgeLength(); break;
        case 29: _t->slotUpdateNumVertices(); break;
        case 30: _t->slotUpdateNumTriangles(); break;
        case 31: _t->slotMixedCounterValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->slotMixedSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->slotDisableDecimation(); break;
        case 34: _t->decimate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 35: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DecimaterPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DecimaterPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DecimaterPlugin,
      qt_meta_data_DecimaterPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DecimaterPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DecimaterPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DecimaterPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DecimaterPlugin))
        return static_cast<void*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< DecimaterPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< DecimaterPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int DecimaterPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void DecimaterPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void DecimaterPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DecimaterPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DecimaterPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DecimaterPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DecimaterPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DecimaterPlugin::functionExists(QString _t1, QString _t2, bool & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DecimaterPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DecimaterPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DecimaterPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE

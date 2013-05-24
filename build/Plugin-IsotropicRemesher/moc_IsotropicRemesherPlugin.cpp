/****************************************************************************
** Meta object code from reading C++ file 'IsotropicRemesherPlugin.hh'
**
** Created: Sat May 18 02:56:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-IsotropicRemesher/IsotropicRemesherPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IsotropicRemesherPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IsotropicRemesherPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   37,   37,   37, 0x05,
      38,   68,   37,   37, 0x05,
      78,  138,   37,   37, 0x05,
     191,  212,   37,   37, 0x05,
     227,  240,   37,   37, 0x05,
     249,  277,   37,   37, 0x05,
     297,  335,   37,   37, 0x05,
     369,  405,   37,   37, 0x05,
     425,  464,   37,   37, 0x05,
     504,  538,   37,   37, 0x25,
     568,  593,   37,   37, 0x05,
     607,  635,   37,   37, 0x05,
     648,  667,   37,   37, 0x05,
     674,  709,   37,   37, 0x05,
     729,  766,   37,   37, 0x05,
     777,  803,   37,   37, 0x25,
     813,  833,   37,   37, 0x05,

 // slots: signature, parameters, type, tag, flags
     847,   37,   37,   37, 0x08,
     866,   37,   37,   37, 0x08,
     887,   37,   37,   37, 0x08,
     900,   37,   37,   37, 0x08,
     926,   37,   37,   37, 0x08,
     945,   37,   37,   37, 0x08,
     964,   37,   37,   37, 0x08,
     984,  667,   37,   37, 0x08,
    1008, 1036,   37,   37, 0x0a,
    1064,   37, 1074,   37, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IsotropicRemesherPlugin[] = {
    "IsotropicRemesherPlugin\0updateView()\0"
    "\0updatedObject(int,UpdateType)\0_id,_type\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0"
    "functionExists(QString,QString,bool&)\0"
    "_pluginName,_functionName,_exists\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0"
    "startJob(QString,QString,int,int,bool)\0"
    "_jobId,_description,_min,_max,_blocking\0"
    "startJob(QString,QString,int,int)\0"
    "_jobId,_description,_min,_max\0"
    "setJobState(QString,int)\0_jobId,_value\0"
    "setJobName(QString,QString)\0_jobId,_name\0"
    "finishJob(QString)\0_jobId\0"
    "setJobDescription(QString,QString)\0"
    "_jobId,_description\0"
    "createBackup(int,QString,UpdateType)\0"
    "_id,_name,\0createBackup(int,QString)\0"
    "_id,_name\0scriptInfo(QString)\0"
    "_functionName\0initializePlugin()\0"
    "pluginsInitialized()\0slotRemesh()\0"
    "slotRemeshButtonClicked()\0slotSetMinLength()\0"
    "slotSetMaxLength()\0slotSetMeanLength()\0"
    "threadFinished(QString)\0"
    "isotropicRemesh(int,double)\0"
    "_objectID,_targetEdgeLength\0version()\0"
    "QString\0"
};

void IsotropicRemesherPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IsotropicRemesherPlugin *_t = static_cast<IsotropicRemesherPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 3: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->pluginExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->functionExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 8: _t->startJob((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 9: _t->startJob((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 10: _t->setJobState((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->setJobName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->finishJob((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setJobDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 15: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 16: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->initializePlugin(); break;
        case 18: _t->pluginsInitialized(); break;
        case 19: _t->slotRemesh(); break;
        case 20: _t->slotRemeshButtonClicked(); break;
        case 21: _t->slotSetMinLength(); break;
        case 22: _t->slotSetMaxLength(); break;
        case 23: _t->slotSetMeanLength(); break;
        case 24: _t->threadFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->isotropicRemesh((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 26: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IsotropicRemesherPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IsotropicRemesherPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IsotropicRemesherPlugin,
      qt_meta_data_IsotropicRemesherPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IsotropicRemesherPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IsotropicRemesherPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IsotropicRemesherPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IsotropicRemesherPlugin))
        return static_cast<void*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "ProcessInterface"))
        return static_cast< ProcessInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ProcessInterface/1.0"))
        return static_cast< ProcessInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< IsotropicRemesherPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int IsotropicRemesherPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void IsotropicRemesherPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void IsotropicRemesherPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IsotropicRemesherPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IsotropicRemesherPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IsotropicRemesherPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void IsotropicRemesherPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void IsotropicRemesherPlugin::functionExists(QString _t1, QString _t2, bool & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void IsotropicRemesherPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void IsotropicRemesherPlugin::startJob(QString _t1, QString _t2, int _t3, int _t4, bool _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 10
void IsotropicRemesherPlugin::setJobState(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void IsotropicRemesherPlugin::setJobName(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void IsotropicRemesherPlugin::finishJob(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void IsotropicRemesherPlugin::setJobDescription(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void IsotropicRemesherPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 16
void IsotropicRemesherPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE

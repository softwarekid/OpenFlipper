/****************************************************************************
** Meta object code from reading C++ file 'RemesherPlugin.hh'
**
** Created: Sat May 18 02:58:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Remesher/RemesherPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RemesherPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RemesherPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   28,   28,   28, 0x05,
      29,   59,   28,   28, 0x05,
      69,  129,   28,   28, 0x05,
     182,  203,   28,   28, 0x05,
     218,  231,   28,   28, 0x05,
     240,  268,   28,   28, 0x05,
     288,  326,   28,   28, 0x05,
     360,  396,   28,   28, 0x05,
     416,  455,   28,   28, 0x05,
     495,  529,   28,   28, 0x25,
     559,  584,   28,   28, 0x05,
     598,  626,   28,   28, 0x05,
     639,  658,   28,   28, 0x05,
     665,  700,   28,   28, 0x05,
     720,  757,   28,   28, 0x05,
     773,  799,   28,   28, 0x25,
     809,  829,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
     843,   28,   28,   28, 0x08,
     862,   28,   28,   28, 0x08,
     883,   28,   28,   28, 0x08,
     916,   28,   28,   28, 0x08,
     936,   28,   28,   28, 0x08,
     968,   28,   28,   28, 0x08,
     987,  658,   28,   28, 0x08,
    1011,   28,   28,   28, 0x08,
    1031, 1089,   28,   28, 0x08,
    1163, 1216,   28,   28, 0x28,
    1274, 1322,   28,   28, 0x08,
    1380, 1423,   28,   28, 0x28,
    1465, 1089,   28,   28, 0x0a,
    1519, 1216,   28,   28, 0x2a,
    1568, 1322,   28,   28, 0x0a,
    1612, 1423,   28,   28, 0x2a,
    1651,   28, 1661,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RemesherPlugin[] = {
    "RemesherPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
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
    "_id,_name,_type\0createBackup(int,QString)\0"
    "_id,_name\0scriptInfo(QString)\0"
    "_functionName\0initializePlugin()\0"
    "pluginsInitialized()\0"
    "adaptiveRemeshingButtonClicked()\0"
    "adaptiveRemeshing()\0uniformRemeshingButtonClicked()\0"
    "uniformRemeshing()\0threadFinished(QString)\0"
    "computeInitValues()\0"
    "slotAdaptiveRemeshing(int,double,double,double,uint,bool)\0"
    "_objectId,_error,_min_edge_length,_max_edge_length,_iters,_use_project"
    "ion\0"
    "slotAdaptiveRemeshing(int,double,double,double,uint)\0"
    "_objectId,_error,_min_edge_length,_max_edge_length,_iters\0"
    "slotUniformRemeshing(int,double,uint,uint,bool)\0"
    "_objectId,_edge_length,_iters,_area_iters,_use_projection\0"
    "slotUniformRemeshing(int,double,uint,uint)\0"
    "_objectId,_edge_length,_iters,_area_iters\0"
    "adaptiveRemeshing(int,double,double,double,uint,bool)\0"
    "adaptiveRemeshing(int,double,double,double,uint)\0"
    "uniformRemeshing(int,double,uint,uint,bool)\0"
    "uniformRemeshing(int,double,uint,uint)\0"
    "version()\0QString\0"
};

void RemesherPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RemesherPlugin *_t = static_cast<RemesherPlugin *>(_o);
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
        case 19: _t->adaptiveRemeshingButtonClicked(); break;
        case 20: _t->adaptiveRemeshing(); break;
        case 21: _t->uniformRemeshingButtonClicked(); break;
        case 22: _t->uniformRemeshing(); break;
        case 23: _t->threadFinished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->computeInitValues(); break;
        case 25: _t->slotAdaptiveRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 26: _t->slotAdaptiveRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5]))); break;
        case 27: _t->slotUniformRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 28: _t->slotUniformRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 29: _t->adaptiveRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 30: _t->adaptiveRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< uint(*)>(_a[5]))); break;
        case 31: _t->uniformRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 32: _t->uniformRemeshing((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 33: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RemesherPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RemesherPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RemesherPlugin,
      qt_meta_data_RemesherPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RemesherPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RemesherPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RemesherPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RemesherPlugin))
        return static_cast<void*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "ProcessInterface"))
        return static_cast< ProcessInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ProcessInterface/1.0"))
        return static_cast< ProcessInterface*>(const_cast< RemesherPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< RemesherPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int RemesherPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void RemesherPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void RemesherPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RemesherPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RemesherPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RemesherPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RemesherPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RemesherPlugin::functionExists(QString _t1, QString _t2, bool & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void RemesherPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void RemesherPlugin::startJob(QString _t1, QString _t2, int _t3, int _t4, bool _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 10
void RemesherPlugin::setJobState(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void RemesherPlugin::setJobName(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void RemesherPlugin::finishJob(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void RemesherPlugin::setJobDescription(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void RemesherPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 16
void RemesherPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE

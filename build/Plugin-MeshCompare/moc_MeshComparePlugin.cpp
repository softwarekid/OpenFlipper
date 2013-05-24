/****************************************************************************
** Meta object code from reading C++ file 'MeshComparePlugin.hh'
**
** Created: Sat May 18 02:56:34 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-MeshCompare/MeshComparePlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshComparePlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MeshComparePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   31,   31,   31, 0x05,
      32,   62,   31,   31, 0x05,
      72,  132,   31,   31, 0x05,
     185,  206,   31,   31, 0x05,
     221,  234,   31,   31, 0x05,
     243,  279,   31,   31, 0x05,
     299,  336,   31,   31, 0x05,
     352,  378,   31,   31, 0x25,
     388,  416,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     436,   31,   31,   31, 0x08,
     455,   31,   31,   31, 0x08,
     476,   31,   31,   31, 0x08,
     492,   31,   31,   31, 0x08,
     504,  538,   31,   31, 0x08,
     556,   31,   31,   31, 0x08,
     573,   31,  583,   31, 0x0a,
     591,  628,   31,   31, 0x0a,
     703,  735,   31,   31, 0x2a,
     797,  824,   31,   31, 0x2a,
     872,  894,   31,   31, 0x2a,
     927,  944,   31,   31, 0x2a,
     964,   31,  986,   31, 0x0a,
     993,   31,  986,   31, 0x0a,
    1022,   31,  986,   31, 0x0a,
    1058,   31,  986,   31, 0x0a,
    1095, 1114,   31,   31, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MeshComparePlugin[] = {
    "MeshComparePlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0"
    "createBackup(int,QString,UpdateType)\0"
    "_id,_name,_type\0createBackup(int,QString)\0"
    "_id,_name\0pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0initializePlugin()\0"
    "pluginsInitialized()\0compareButton()\0"
    "slotClear()\0slotObjectUpdated(int,UpdateType)\0"
    "_identifier,_type\0noguiSupported()\0"
    "version()\0QString\0"
    "compare(int,int,bool,bool,bool,bool)\0"
    "_sourceId,_targetId,_computeDist,_computeNormal,_computeGauss,_compute"
    "Mean\0"
    "compare(int,int,bool,bool,bool)\0"
    "_sourceId,_targetId,_computeDist,_computeNormal,_computeGauss\0"
    "compare(int,int,bool,bool)\0"
    "_sourceId,_targetId,_computeDist,_computeNormal\0"
    "compare(int,int,bool)\0"
    "_sourceId,_targetId,_computeDist\0"
    "compare(int,int)\0_sourceId,_targetId\0"
    "lastMaximalDistance()\0double\0"
    "lastMaximalNormalDeviation()\0"
    "lastMaximalMeanCurvatureDeviation()\0"
    "lastMaximalGaussCurvatureDeviation()\0"
    "slotClampBox(bool)\0_checked\0"
};

void MeshComparePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MeshComparePlugin *_t = static_cast<MeshComparePlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 3: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 6: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 7: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->pluginExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->initializePlugin(); break;
        case 10: _t->pluginsInitialized(); break;
        case 11: _t->compareButton(); break;
        case 12: _t->slotClear(); break;
        case 13: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 14: _t->noguiSupported(); break;
        case 15: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: _t->compare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 17: _t->compare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 18: _t->compare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 19: _t->compare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 20: _t->compare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: { double _r = _t->lastMaximalDistance();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 22: { double _r = _t->lastMaximalNormalDeviation();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 23: { double _r = _t->lastMaximalMeanCurvatureDeviation();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 24: { double _r = _t->lastMaximalGaussCurvatureDeviation();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 25: _t->slotClampBox((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MeshComparePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MeshComparePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeshComparePlugin,
      qt_meta_data_MeshComparePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MeshComparePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MeshComparePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MeshComparePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MeshComparePlugin))
        return static_cast<void*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "TextureInterface"))
        return static_cast< TextureInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TextureInterface/1.0"))
        return static_cast< TextureInterface*>(const_cast< MeshComparePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< MeshComparePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int MeshComparePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MeshComparePlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MeshComparePlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeshComparePlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MeshComparePlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MeshComparePlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MeshComparePlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MeshComparePlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void MeshComparePlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'MeshRepairPlugin.hh'
**
** Created: Sat May 18 02:56:40 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-MeshRepair/MeshRepairPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshRepairPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MeshRepairPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   30,   30,   30, 0x05,
      31,   61,   30,   30, 0x05,
      79,  139,   30,   30, 0x05,
     192,  213,   30,   30, 0x05,
     228,  241,   30,   30, 0x05,
     250,  286,   30,   30, 0x05,
     306,  343,   30,   30, 0x05,
     365,  391,   30,   30, 0x25,
     407,  435,   30,   30, 0x05,
     455,  493,   30,   30, 0x05,
     527,  547,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
     561,   30,   30,   30, 0x08,
     580,   30,   30,   30, 0x08,
     601,   30,   30,   30, 0x08,
     634,   30,   30,   30, 0x08,
     660,   30,   30,   30, 0x08,
     694,   30,   30,   30, 0x08,
     728,   30,   30,   30, 0x08,
     749,   30,   30,   30, 0x08,
     776,   30,   30,   30, 0x08,
     798,   30,   30,   30, 0x08,
     812,   30,   30,   30, 0x08,
     838,   30,   30,   30, 0x08,
     862,   30,   30,   30, 0x08,
     890,   30,   30,   30, 0x08,
     910,   30,   30,   30, 0x08,
     934,   30,   30,   30, 0x08,
     959,   30,   30,   30, 0x08,
     992,   30,   30,   30, 0x08,
    1011,   30,   30,   30, 0x08,
    1040, 1079,   30,   30, 0x0a,
    1096, 1128,   30,   30, 0x0a,
    1138, 1173,   30,   30, 0x0a,
    1191, 1173,   30,   30, 0x0a,
    1225, 1128,   30,   30, 0x0a,
    1250, 1295,   30,   30, 0x0a,
    1320, 1079,   30,   30, 0x0a,
    1346, 1378,   30,   30, 0x0a,
    1396, 1128,   30,   30, 0x0a,
    1417, 1128,   30,   30, 0x0a,
    1440, 1128,   30,   30, 0x0a,
    1467, 1128,   30,   30, 0x0a,
    1492, 1128,   30,   30, 0x0a,
    1511, 1536,   30,   30, 0x0a,
    1551, 1128,   30,   30, 0x0a,
    1579, 1599,   30,   30, 0x0a,
    1618,   30, 1628,   30, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MeshRepairPlugin[] = {
    "MeshRepairPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0"
    "_identifier,_type\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0"
    "createBackup(int,QString,UpdateType)\0"
    "_objectid,_name,_type\0createBackup(int,QString)\0"
    "_objectid,_name\0pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0"
    "functionExists(QString,QString,bool&)\0"
    "_pluginName,_functionName,_exists\0"
    "scriptInfo(QString)\0_functionName\0"
    "initializePlugin()\0pluginsInitialized()\0"
    "slotRemoveSelectedVal3Vertices()\0"
    "slotRemoveSelectedEdges()\0"
    "slotDetectSkinnyTriangleByAngle()\0"
    "slotRemoveSkinnyTriangleByAngle()\0"
    "slotDetectFoldover()\0slotDetectTriangleAspect()\0"
    "slotFlipOrientation()\0slotFixMesh()\0"
    "slotUpdateVertexNormals()\0"
    "slotUpdateFaceNormals()\0"
    "slotUpdateHalfedgeNormals()\0"
    "slotUpdateNormals()\0slotDetectEdgesLonger()\0"
    "slotDetectEdgesShorter()\0"
    "slotDetectFlatValence3Vertices()\0"
    "slotSnapBoundary()\0slotFixNonManifoldVertices()\0"
    "detectFlatValence3Vertices(int,double)\0"
    "_objectId,_angle\0removeSelectedVal3Vertices(int)\0"
    "_objectId\0selectEdgesShorterThan(int,double)\0"
    "_objectId,_length\0selectEdgesLongerThan(int,double)\0"
    "removeSelectedEdges(int)\0"
    "detectSkinnyTriangleByAngle(int,double,bool)\0"
    "_objectId,_angle,_remove\0"
    "detectFoldover(int,float)\0"
    "detectTriangleAspect(int,float)\0"
    "_objectId,_aspect\0flipOrientation(int)\0"
    "updateFaceNormals(int)\0"
    "updateHalfedgeNormals(int)\0"
    "updateVertexNormals(int)\0updateNormals(int)\0"
    "snapBoundary(int,double)\0_objectId,_eps\0"
    "fixNonManifoldVertices(int)\0"
    "fixMesh(int,double)\0_objectId,_epsilon\0"
    "version()\0QString\0"
};

void MeshRepairPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MeshRepairPlugin *_t = static_cast<MeshRepairPlugin *>(_o);
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
        case 9: _t->functionExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->initializePlugin(); break;
        case 12: _t->pluginsInitialized(); break;
        case 13: _t->slotRemoveSelectedVal3Vertices(); break;
        case 14: _t->slotRemoveSelectedEdges(); break;
        case 15: _t->slotDetectSkinnyTriangleByAngle(); break;
        case 16: _t->slotRemoveSkinnyTriangleByAngle(); break;
        case 17: _t->slotDetectFoldover(); break;
        case 18: _t->slotDetectTriangleAspect(); break;
        case 19: _t->slotFlipOrientation(); break;
        case 20: _t->slotFixMesh(); break;
        case 21: _t->slotUpdateVertexNormals(); break;
        case 22: _t->slotUpdateFaceNormals(); break;
        case 23: _t->slotUpdateHalfedgeNormals(); break;
        case 24: _t->slotUpdateNormals(); break;
        case 25: _t->slotDetectEdgesLonger(); break;
        case 26: _t->slotDetectEdgesShorter(); break;
        case 27: _t->slotDetectFlatValence3Vertices(); break;
        case 28: _t->slotSnapBoundary(); break;
        case 29: _t->slotFixNonManifoldVertices(); break;
        case 30: _t->detectFlatValence3Vertices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 31: _t->removeSelectedVal3Vertices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->selectEdgesShorterThan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 33: _t->selectEdgesLongerThan((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 34: _t->removeSelectedEdges((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->detectSkinnyTriangleByAngle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 36: _t->detectFoldover((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 37: _t->detectTriangleAspect((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 38: _t->flipOrientation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->updateFaceNormals((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->updateHalfedgeNormals((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->updateVertexNormals((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->updateNormals((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->snapBoundary((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 44: _t->fixNonManifoldVertices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: _t->fixMesh((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 46: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MeshRepairPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MeshRepairPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeshRepairPlugin,
      qt_meta_data_MeshRepairPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MeshRepairPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MeshRepairPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MeshRepairPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MeshRepairPlugin))
        return static_cast<void*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< MeshRepairPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< MeshRepairPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int MeshRepairPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    return _id;
}

// SIGNAL 0
void MeshRepairPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MeshRepairPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeshRepairPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MeshRepairPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MeshRepairPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MeshRepairPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MeshRepairPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void MeshRepairPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MeshRepairPlugin::functionExists(QString _t1, QString _t2, bool & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MeshRepairPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE

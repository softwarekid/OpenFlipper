/****************************************************************************
** Meta object code from reading C++ file 'MeshObjectInfoPlugin.hh'
**
** Created: Sat May 18 02:55:38 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-InfoMeshObject/MeshObjectInfoPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshObjectInfoPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InfoMeshObjectPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   81,  134,  134, 0x05,
     135,  156,  134,  134, 0x05,
     171,  184,  134,  134, 0x05,
     193,  224,  134,  134, 0x05,

 // slots: signature, parameters, type, tag, flags
     232,  134,  134,  134, 0x08,
     251,  134,  134,  134, 0x08,
     272,  306,  134,  134, 0x08,
     324,  356,  134,  134, 0x08,
     368,  134,  134,  134, 0x08,
     385,  134,  134,  134, 0x08,
     402,  444,  134,  134, 0x08,
     464,  134,  485,  134, 0x08,
     494,  511,  515,  134, 0x0a,
     519,  511,  515,  134, 0x0a,
     534,  511,  515,  134, 0x0a,
     549,  511,  515,  134, 0x0a,
     568,  511,  515,  134, 0x0a,
     588,  511,  515,  134, 0x0a,
     599,  511,  608,  134, 0x0a,
     615,  511,  608,  134, 0x0a,
     635,  511,  608,  134, 0x0a,
     655,  511,  608,  134, 0x0a,
     676,  696,  712,  134, 0x0a,
     719,  737,  712,  134, 0x0a,
     753,  737,  712,  134, 0x0a,
     774,  797,  515,  134, 0x0a,
     815,  511,  712,  134, 0x0a,
     834,  511,  712,  134, 0x0a,
     853,  511,  712,  134, 0x0a,
     873,  134,  883,  134, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InfoMeshObjectPlugin[] = {
    "InfoMeshObjectPlugin\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "\0log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "addWidgetToStatusbar(QWidget*)\0_widget\0"
    "initializePlugin()\0pluginsInitialized()\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "_identifier,_type\0slotObjectSelectionChanged(int)\0"
    "_identifier\0slotAllCleared()\0"
    "noguiSupported()\0"
    "slotInformationRequested(QPoint,DataType)\0"
    "_clickedPoint,_type\0supportedDataTypes()\0"
    "DataType\0vertexCount(int)\0_id\0int\0"
    "edgeCount(int)\0faceCount(int)\0"
    "boundaryCount(int)\0componentCount(int)\0"
    "genus(int)\0cog(int)\0Vector\0"
    "boundingBoxMin(int)\0boundingBoxMax(int)\0"
    "boundingBoxSize(int)\0edgeLength(int,int)\0"
    "_id,_edgeHandle\0double\0faceArea(int,int)\0"
    "_id,_faceHandle\0aspectRatio(int,int)\0"
    "vertexValence(int,int)\0_id,_vertexHandle\0"
    "minEdgeLength(int)\0maxEdgeLength(int)\0"
    "meanEdgeLength(int)\0version()\0QString\0"
};

void InfoMeshObjectPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InfoMeshObjectPlugin *_t = static_cast<InfoMeshObjectPlugin *>(_o);
        switch (_id) {
        case 0: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 1: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addWidgetToStatusbar((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->initializePlugin(); break;
        case 5: _t->pluginsInitialized(); break;
        case 6: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 7: _t->slotObjectSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotAllCleared(); break;
        case 9: _t->noguiSupported(); break;
        case 10: _t->slotInformationRequested((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2]))); break;
        case 11: { DataType _r = _t->supportedDataTypes();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->vertexCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->edgeCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->faceCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->boundaryCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->componentCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: { int _r = _t->genus((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: { Vector _r = _t->cog((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 19: { Vector _r = _t->boundingBoxMin((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 20: { Vector _r = _t->boundingBoxMax((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 21: { Vector _r = _t->boundingBoxSize((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 22: { double _r = _t->edgeLength((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 23: { double _r = _t->faceArea((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 24: { double _r = _t->aspectRatio((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 25: { int _r = _t->vertexValence((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 26: { double _r = _t->minEdgeLength((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 27: { double _r = _t->maxEdgeLength((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 28: { double _r = _t->meanEdgeLength((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 29: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InfoMeshObjectPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InfoMeshObjectPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InfoMeshObjectPlugin,
      qt_meta_data_InfoMeshObjectPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InfoMeshObjectPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InfoMeshObjectPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InfoMeshObjectPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoMeshObjectPlugin))
        return static_cast<void*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "InformationInterface"))
        return static_cast< InformationInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "StatusbarInterface"))
        return static_cast< StatusbarInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.InformationInterface/1.0"))
        return static_cast< InformationInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.StatusbarInterface/1.0"))
        return static_cast< StatusbarInterface*>(const_cast< InfoMeshObjectPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int InfoMeshObjectPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void InfoMeshObjectPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InfoMeshObjectPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InfoMeshObjectPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InfoMeshObjectPlugin::addWidgetToStatusbar(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

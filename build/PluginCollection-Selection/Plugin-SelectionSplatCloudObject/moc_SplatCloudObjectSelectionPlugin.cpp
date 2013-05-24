/****************************************************************************
** Meta object code from reading C++ file 'SplatCloudObjectSelectionPlugin.hh'
**
** Created: Sat May 18 03:03:29 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Selection/Plugin-SelectionSplatCloudObject/SplatCloudObjectSelectionPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SplatCloudObjectSelectionPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplatCloudObjectSelectionPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   45,   45,   45, 0x05,
      46,   76,   45,   45, 0x05,
      92,  119,   45,   45, 0x05,
     129,  189,   45,   45, 0x05,
     242,  279,   45,   45, 0x05,
     301,  327,   45,   45, 0x25,
     343,  356,   45,   45, 0x05,
     365,  386,   45,   45, 0x05,
     401,  459,   45,   45, 0x05,
     500,  531,   45,   45, 0x05,
     549,  626,   45,   45, 0x05,
     662,  748,   45,   45, 0x05,
     792,  844,   45,   45, 0x25,
     882,  954,   45,   45, 0x05,
     989,  954,   45,   45, 0x05,
    1061,  954,   45,   45, 0x05,
    1132,  954,   45,   45, 0x05,
    1209, 1259,   45,   45, 0x05,
    1266, 1325,   45,   45, 0x05,
    1331, 1356,   45,   45, 0x05,
    1369, 1416,   45,   45, 0x05,
    1432, 1457,   45,   45, 0x25,
    1462,  119,   45,   45, 0x05,
    1480, 1500,   45,   45, 0x05,

 // slots: signature, parameters, type, tag, flags
    1514, 1541,   45,   45, 0x0a,
    1561, 1587,   45,   45, 0x08,
    1602, 1587,   45,   45, 0x08,
    1628,   45,   45,   45, 0x08,
    1647,   45,   45,   45, 0x08,
    1668,   45,   45,   45, 0x08,
    1685, 1717,   45,   45, 0x08,
    1728, 1801,   45,   45, 0x08,
    1831, 1911,   45,   45, 0x08,
    1949, 1801,   45,   45, 0x08,
    2021, 1801,   45,   45, 0x08,
    2099, 2126,   45,   45, 0x08,
    2132, 2126,   45,   45, 0x08,
    2160, 1416,   45,   45, 0x08,
    2208,   45, 2218,   45, 0x0a,
    2226,   45, 2245,   45, 0x0a,
    2250, 2277,   45,   45, 0x0a,
    2299, 2277,   45,   45, 0x0a,
    2328,  119,   45,   45, 0x0a,
    2351,  119,   45,   45, 0x0a,
    2377,  119,   45,   45, 0x0a,
    2404,  119, 2428,   45, 0x0a,
    2435,  119,   45,   45, 0x0a,
    2462, 2507,   45,   45, 0x0a,
    2529, 2570,   45,   45, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SplatCloudObjectSelectionPlugin[] = {
    "SplatCloudObjectSelectionPlugin\0"
    "updateView()\0\0updatedObject(int,UpdateType)\0"
    "_objectId,_type\0nodeVisibilityChanged(int)\0"
    "_objectId\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "createBackup(int,QString,UpdateType)\0"
    "_objectId,_name,_type\0createBackup(int,QString)\0"
    "_objectId,_name\0log(QString)\0_message\0"
    "log(Logtype,QString)\0_type,_message\0"
    "addSelectionEnvironment(QString,QString,QString,QString&)\0"
    "_modeName,_description,_icon,_handleName\0"
    "registerType(QString,DataType)\0"
    "_handleName,_type\0"
    "addPrimitiveType(QString,QString,QString,SelectionInterface::Primitive"
    "Type&)\0"
    "_handleName,_name,_icon,_typeHandle\0"
    "addSelectionOperations(QString,QStringList,QString,SelectionInterface:"
    ":PrimitiveType)\0"
    "_handleName,_operationsList,_category,_type\0"
    "addSelectionOperations(QString,QStringList,QString)\0"
    "_handleName,_operationsList,_category\0"
    "showToggleSelectionMode(QString,bool,SelectionInterface::PrimitiveType"
    ")\0"
    "_handleName,_show,_associatedTypes\0"
    "showSphereSelectionMode(QString,bool,SelectionInterface::PrimitiveType"
    ")\0"
    "showLassoSelectionMode(QString,bool,SelectionInterface::PrimitiveType)\0"
    "showVolumeLassoSelectionMode(QString,bool,SelectionInterface::Primitiv"
    "eType)\0"
    "getActiveDataTypes(SelectionInterface::TypeList&)\0"
    "_types\0"
    "getActivePrimitiveType(SelectionInterface::PrimitiveType&)\0"
    "_type\0targetObjectsOnly(bool&)\0"
    "_targetsOnly\0"
    "registerKeyShortcut(int,Qt::KeyboardModifiers)\0"
    "_key,_modifiers\0registerKeyShortcut(int)\0"
    "_key\0deleteObject(int)\0scriptInfo(QString)\0"
    "_functionName\0loadSelection(int,QString)\0"
    "_objectId,_filename\0loadIniFile(INIFile&,int)\0"
    "_ini,_objectId\0saveIniFile(INIFile&,int)\0"
    "initializePlugin()\0pluginsInitialized()\0"
    "noguiSupported()\0slotSelectionOperation(QString)\0"
    "_operation\0"
    "slotToggleSelection(QMouseEvent*,SelectionInterface::PrimitiveType,boo"
    "l)\0"
    "_event,_currentType,_deselect\0"
    "slotSphereSelection(QMouseEvent*,double,SelectionInterface::PrimitiveT"
    "ype,bool)\0"
    "_event,_radius,_currentType,_deselect\0"
    "slotLassoSelection(QMouseEvent*,SelectionInterface::PrimitiveType,bool"
    ")\0"
    "slotVolumeLassoSelection(QMouseEvent*,SelectionInterface::PrimitiveTyp"
    "e,bool)\0"
    "slotLoadSelection(INIFile)\0_file\0"
    "slotSaveSelection(INIFile&)\0"
    "slotKeyShortcutEvent(int,Qt::KeyboardModifiers)\0"
    "version()\0QString\0vertexTypeActive()\0"
    "bool\0selectVertices(int,IdList)\0"
    "_objectId,_vertexList\0"
    "unselectVertices(int,IdList)\0"
    "selectAllVertices(int)\0clearVertexSelection(int)\0"
    "invertVertexSelection(int)\0"
    "getVertexSelection(int)\0IdList\0"
    "deleteVertexSelection(int)\0"
    "colorizeVertexSelection(int,int,int,int,int)\0"
    "_objectId,_r,_g,_b,_a\0"
    "lassoSelect(QRegion&,PrimitiveType,bool)\0"
    "_region,_primitiveType,_deselection\0"
};

void SplatCloudObjectSelectionPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SplatCloudObjectSelectionPlugin *_t = static_cast<SplatCloudObjectSelectionPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->nodeVisibilityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 4: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 5: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->addSelectionEnvironment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->registerType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2]))); break;
        case 10: _t->addPrimitiveType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[4]))); break;
        case 11: _t->addSelectionOperations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[4]))); break;
        case 12: _t->addSelectionOperations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 13: _t->showToggleSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 14: _t->showSphereSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 15: _t->showLassoSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 16: _t->showVolumeLassoSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 17: _t->getActiveDataTypes((*reinterpret_cast< SelectionInterface::TypeList(*)>(_a[1]))); break;
        case 18: _t->getActivePrimitiveType((*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[1]))); break;
        case 19: _t->targetObjectsOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->registerKeyShortcut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 21: _t->registerKeyShortcut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->loadSelection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 25: _t->loadIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->saveIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 27: _t->initializePlugin(); break;
        case 28: _t->pluginsInitialized(); break;
        case 29: _t->noguiSupported(); break;
        case 30: _t->slotSelectionOperation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->slotToggleSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 32: _t->slotSphereSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 33: _t->slotLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 34: _t->slotVolumeLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 35: _t->slotLoadSelection((*reinterpret_cast< const INIFile(*)>(_a[1]))); break;
        case 36: _t->slotSaveSelection((*reinterpret_cast< INIFile(*)>(_a[1]))); break;
        case 37: _t->slotKeyShortcutEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 38: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 39: { bool _r = _t->vertexTypeActive();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 40: _t->selectVertices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< IdList(*)>(_a[2]))); break;
        case 41: _t->unselectVertices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< IdList(*)>(_a[2]))); break;
        case 42: _t->selectAllVertices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->clearVertexSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->invertVertexSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 45: { IdList _r = _t->getVertexSelection((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< IdList*>(_a[0]) = _r; }  break;
        case 46: _t->deleteVertexSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->colorizeVertexSelection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 48: _t->lassoSelect((*reinterpret_cast< QRegion(*)>(_a[1])),(*reinterpret_cast< PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SplatCloudObjectSelectionPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SplatCloudObjectSelectionPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SplatCloudObjectSelectionPlugin,
      qt_meta_data_SplatCloudObjectSelectionPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplatCloudObjectSelectionPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplatCloudObjectSelectionPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplatCloudObjectSelectionPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplatCloudObjectSelectionPlugin))
        return static_cast<void*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "SelectionInterface"))
        return static_cast< SelectionInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "INIInterface"))
        return static_cast< INIInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.SelectionInterface/1.1"))
        return static_cast< SelectionInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.INIInterface/1.2"))
        return static_cast< INIInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< SplatCloudObjectSelectionPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int SplatCloudObjectSelectionPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void SplatCloudObjectSelectionPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SplatCloudObjectSelectionPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SplatCloudObjectSelectionPlugin::nodeVisibilityChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SplatCloudObjectSelectionPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SplatCloudObjectSelectionPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void SplatCloudObjectSelectionPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SplatCloudObjectSelectionPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SplatCloudObjectSelectionPlugin::addSelectionEnvironment(QString _t1, QString _t2, QString _t3, QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SplatCloudObjectSelectionPlugin::registerType(QString _t1, DataType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SplatCloudObjectSelectionPlugin::addPrimitiveType(QString _t1, QString _t2, QString _t3, SelectionInterface::PrimitiveType & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SplatCloudObjectSelectionPlugin::addSelectionOperations(QString _t1, QStringList _t2, QString _t3, SelectionInterface::PrimitiveType _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 13
void SplatCloudObjectSelectionPlugin::showToggleSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void SplatCloudObjectSelectionPlugin::showSphereSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void SplatCloudObjectSelectionPlugin::showLassoSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void SplatCloudObjectSelectionPlugin::showVolumeLassoSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void SplatCloudObjectSelectionPlugin::getActiveDataTypes(SelectionInterface::TypeList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void SplatCloudObjectSelectionPlugin::getActivePrimitiveType(SelectionInterface::PrimitiveType & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void SplatCloudObjectSelectionPlugin::targetObjectsOnly(bool & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void SplatCloudObjectSelectionPlugin::registerKeyShortcut(int _t1, Qt::KeyboardModifiers _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 22
void SplatCloudObjectSelectionPlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void SplatCloudObjectSelectionPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}
QT_END_MOC_NAMESPACE

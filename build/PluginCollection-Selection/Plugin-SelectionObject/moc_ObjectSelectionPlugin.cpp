/****************************************************************************
** Meta object code from reading C++ file 'ObjectSelectionPlugin.hh'
**
** Created: Sat May 18 03:03:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Selection/Plugin-SelectionObject/ObjectSelectionPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjectSelectionPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ObjectSelectionPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   35,   35,   35, 0x05,
      36,   66,   35,   35, 0x05,
      68,   95,   35,   35, 0x05,
     107,  167,   35,   35, 0x05,
     220,  241,   35,   35, 0x05,
     256,  269,   35,   35, 0x05,
     278,  298,   35,   35, 0x05,
     312,  370,   35,   35, 0x05,
     411,  442,   35,   35, 0x05,
     460,  537,   35,   35, 0x05,
     573,  659,   35,   35, 0x05,
     703,  755,   35,   35, 0x25,
     793,  865,   35,   35, 0x05,
     900,  865,   35,   35, 0x05,
     977, 1027,   35,   35, 0x05,
    1034, 1093,   35,   35, 0x05,
    1099, 1124,   35,   35, 0x05,
    1137, 1184,   35,   35, 0x05,
    1200, 1225,   35,   35, 0x25,
    1230, 1248,   35,   35, 0x05,

 // slots: signature, parameters, type, tag, flags
    1252, 1278,   35,   35, 0x08,
    1287, 1278,   35,   35, 0x08,
    1313,   35,   35,   35, 0x08,
    1332,   35,   35,   35, 0x08,
    1353,   35,   35,   35, 0x08,
    1370, 1402,   35,   35, 0x08,
    1413, 1486,   35,   35, 0x08,
    1516, 1486,   35,   35, 0x08,
    1594, 1621,   35,   35, 0x08,
    1627, 1621,   35,   35, 0x08,
    1655, 1184,   35,   35, 0x08,
    1703, 1730,   35,   35, 0x0a,
    1747,   35, 1757,   35, 0x0a,
    1765,   35,   35,   35, 0x0a,
    1784, 1806,   35,   35, 0x0a,
    1812,   35,   35,   35, 0x0a,
    1833,   35,   35,   35, 0x0a,
    1857,   35,   35,   35, 0x0a,
    1881,   35, 1902,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ObjectSelectionPlugin[] = {
    "ObjectSelectionPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0,\0"
    "nodeVisibilityChanged(int)\0_identifier\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0scriptInfo(QString)\0"
    "_functionName\0"
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
    "showVolumeLassoSelectionMode(QString,bool,SelectionInterface::Primitiv"
    "eType)\0"
    "getActiveDataTypes(SelectionInterface::TypeList&)\0"
    "_types\0"
    "getActivePrimitiveType(SelectionInterface::PrimitiveType&)\0"
    "_type\0targetObjectsOnly(bool&)\0"
    "_targetsOnly\0"
    "registerKeyShortcut(int,Qt::KeyboardModifiers)\0"
    "_key,_modifiers\0registerKeyShortcut(int)\0"
    "_key\0deleteObject(int)\0_id\0"
    "loadIniFile(INIFile&,int)\0_ini,_id\0"
    "saveIniFile(INIFile&,int)\0initializePlugin()\0"
    "pluginsInitialized()\0noguiSupported()\0"
    "slotSelectionOperation(QString)\0"
    "_operation\0"
    "slotToggleSelection(QMouseEvent*,SelectionInterface::PrimitiveType,boo"
    "l)\0"
    "_event,_currentType,_deselect\0"
    "slotVolumeLassoSelection(QMouseEvent*,SelectionInterface::PrimitiveTyp"
    "e,bool)\0"
    "slotLoadSelection(INIFile)\0_file\0"
    "slotSaveSelection(INIFile&)\0"
    "slotKeyShortcutEvent(int,Qt::KeyboardModifiers)\0"
    "loadSelection(int,QString)\0_objId,_filename\0"
    "version()\0QString\0selectAllObjects()\0"
    "selectObjects(IdList)\0_list\0"
    "deselectAllObjects()\0invertObjectSelection()\0"
    "deleteSelectedObjects()\0getObjectSelection()\0"
    "IdList\0"
};

void ObjectSelectionPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectSelectionPlugin *_t = static_cast<ObjectSelectionPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->nodeVisibilityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 4: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->addSelectionEnvironment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 8: _t->registerType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2]))); break;
        case 9: _t->addPrimitiveType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[4]))); break;
        case 10: _t->addSelectionOperations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[4]))); break;
        case 11: _t->addSelectionOperations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 12: _t->showToggleSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 13: _t->showVolumeLassoSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 14: _t->getActiveDataTypes((*reinterpret_cast< SelectionInterface::TypeList(*)>(_a[1]))); break;
        case 15: _t->getActivePrimitiveType((*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[1]))); break;
        case 16: _t->targetObjectsOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->registerKeyShortcut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 18: _t->registerKeyShortcut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->loadIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->saveIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 22: _t->initializePlugin(); break;
        case 23: _t->pluginsInitialized(); break;
        case 24: _t->noguiSupported(); break;
        case 25: _t->slotSelectionOperation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->slotToggleSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 27: _t->slotVolumeLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 28: _t->slotLoadSelection((*reinterpret_cast< const INIFile(*)>(_a[1]))); break;
        case 29: _t->slotSaveSelection((*reinterpret_cast< INIFile(*)>(_a[1]))); break;
        case 30: _t->slotKeyShortcutEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 31: _t->loadSelection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 32: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 33: _t->selectAllObjects(); break;
        case 34: _t->selectObjects((*reinterpret_cast< IdList(*)>(_a[1]))); break;
        case 35: _t->deselectAllObjects(); break;
        case 36: _t->invertObjectSelection(); break;
        case 37: _t->deleteSelectedObjects(); break;
        case 38: { IdList _r = _t->getObjectSelection();
            if (_a[0]) *reinterpret_cast< IdList*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ObjectSelectionPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ObjectSelectionPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ObjectSelectionPlugin,
      qt_meta_data_ObjectSelectionPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ObjectSelectionPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ObjectSelectionPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ObjectSelectionPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObjectSelectionPlugin))
        return static_cast<void*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "INIInterface"))
        return static_cast< INIInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "SelectionInterface"))
        return static_cast< SelectionInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.INIInterface/1.2"))
        return static_cast< INIInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.SelectionInterface/1.1"))
        return static_cast< SelectionInterface*>(const_cast< ObjectSelectionPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int ObjectSelectionPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void ObjectSelectionPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ObjectSelectionPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ObjectSelectionPlugin::nodeVisibilityChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ObjectSelectionPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ObjectSelectionPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ObjectSelectionPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ObjectSelectionPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ObjectSelectionPlugin::addSelectionEnvironment(QString _t1, QString _t2, QString _t3, QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ObjectSelectionPlugin::registerType(QString _t1, DataType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ObjectSelectionPlugin::addPrimitiveType(QString _t1, QString _t2, QString _t3, SelectionInterface::PrimitiveType & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ObjectSelectionPlugin::addSelectionOperations(QString _t1, QStringList _t2, QString _t3, SelectionInterface::PrimitiveType _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 12
void ObjectSelectionPlugin::showToggleSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ObjectSelectionPlugin::showVolumeLassoSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ObjectSelectionPlugin::getActiveDataTypes(SelectionInterface::TypeList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void ObjectSelectionPlugin::getActivePrimitiveType(SelectionInterface::PrimitiveType & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void ObjectSelectionPlugin::targetObjectsOnly(bool & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void ObjectSelectionPlugin::registerKeyShortcut(int _t1, Qt::KeyboardModifiers _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 19
void ObjectSelectionPlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}
QT_END_MOC_NAMESPACE

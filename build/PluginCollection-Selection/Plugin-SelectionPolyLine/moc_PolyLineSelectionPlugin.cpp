/****************************************************************************
** Meta object code from reading C++ file 'PolyLineSelectionPlugin.hh'
**
** Created: Sat May 18 03:03:24 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Selection/Plugin-SelectionPolyLine/PolyLineSelectionPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PolyLineSelectionPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PolyLineSelectionPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   37,   37,   37, 0x05,
      38,   68,   37,   37, 0x05,
      70,   97,   37,   37, 0x05,
     109,  169,   37,   37, 0x05,
     222,  243,   37,   37, 0x05,
     258,  271,   37,   37, 0x05,
     280,  300,   37,   37, 0x05,
     314,  372,   37,   37, 0x05,
     413,  444,   37,   37, 0x05,
     462,  539,   37,   37, 0x05,
     575,  661,   37,   37, 0x05,
     705,  757,   37,   37, 0x25,
     795,  867,   37,   37, 0x05,
     902,  867,   37,   37, 0x05,
     979, 1029,   37,   37, 0x05,
    1036, 1095,   37,   37, 0x05,
    1101, 1126,   37,   37, 0x05,
    1139, 1186,   37,   37, 0x05,
    1202, 1227,   37,   37, 0x25,

 // slots: signature, parameters, type, tag, flags
    1232, 1258,   37,   37, 0x08,
    1267, 1258,   37,   37, 0x08,
    1293,   37,   37,   37, 0x08,
    1312,   37,   37,   37, 0x08,
    1333,   37,   37,   37, 0x08,
    1350, 1382,   37,   37, 0x08,
    1393, 1466,   37,   37, 0x08,
    1496, 1466,   37,   37, 0x08,
    1574, 1601,   37,   37, 0x08,
    1607, 1601,   37,   37, 0x08,
    1635, 1186,   37,   37, 0x08,
    1683, 1710,   37,   37, 0x0a,
    1727,   37, 1737,   37, 0x0a,
    1745, 1768,   37,   37, 0x0a,
    1778, 1768,   37,   37, 0x0a,
    1803, 1768,   37,   37, 0x0a,
    1830, 1768,   37,   37, 0x0a,
    1858, 1890,   37,   37, 0x0a,
    1915, 1942,   37,   37, 0x2a,
    1957, 1768, 1981,   37, 0x0a,
    1988, 1768,   37,   37, 0x0a,
    2008, 1768,   37,   37, 0x0a,
    2030, 1768,   37,   37, 0x0a,
    2055, 1768,   37,   37, 0x0a,
    2080, 1890,   37,   37, 0x0a,
    2109, 1942,   37,   37, 0x2a,
    2133, 1768, 1981,   37, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PolyLineSelectionPlugin[] = {
    "PolyLineSelectionPlugin\0updateView()\0"
    "\0updatedObject(int,UpdateType)\0,\0"
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
    "_key\0loadIniFile(INIFile&,int)\0_ini,_id\0"
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
    "version()\0QString\0selectAllVertices(int)\0"
    "_objectId\0deselectAllVertices(int)\0"
    "invertVertexSelection(int)\0"
    "deleteSelectedVertices(int)\0"
    "selectVertices(int,IdList,bool)\0"
    "_objectId,_ids,_deselect\0"
    "selectVertices(int,IdList)\0_objectId,_ids\0"
    "getVertexSelection(int)\0IdList\0"
    "selectAllEdges(int)\0deselectAllEdges(int)\0"
    "invertEdgeSelection(int)\0"
    "deleteSelectedEdges(int)\0"
    "selectEdges(int,IdList,bool)\0"
    "selectEdges(int,IdList)\0getEdgeSelection(int)\0"
};

void PolyLineSelectionPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PolyLineSelectionPlugin *_t = static_cast<PolyLineSelectionPlugin *>(_o);
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
        case 19: _t->loadIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->saveIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->initializePlugin(); break;
        case 22: _t->pluginsInitialized(); break;
        case 23: _t->noguiSupported(); break;
        case 24: _t->slotSelectionOperation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->slotToggleSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 26: _t->slotVolumeLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 27: _t->slotLoadSelection((*reinterpret_cast< const INIFile(*)>(_a[1]))); break;
        case 28: _t->slotSaveSelection((*reinterpret_cast< INIFile(*)>(_a[1]))); break;
        case 29: _t->slotKeyShortcutEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 30: _t->loadSelection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 31: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 32: _t->selectAllVertices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->deselectAllVertices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->invertVertexSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->deleteSelectedVertices((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->selectVertices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const IdList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 37: _t->selectVertices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const IdList(*)>(_a[2]))); break;
        case 38: { IdList _r = _t->getVertexSelection((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< IdList*>(_a[0]) = _r; }  break;
        case 39: _t->selectAllEdges((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->deselectAllEdges((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->invertEdgeSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 42: _t->deleteSelectedEdges((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 43: _t->selectEdges((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const IdList(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 44: _t->selectEdges((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const IdList(*)>(_a[2]))); break;
        case 45: { IdList _r = _t->getEdgeSelection((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< IdList*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PolyLineSelectionPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PolyLineSelectionPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PolyLineSelectionPlugin,
      qt_meta_data_PolyLineSelectionPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PolyLineSelectionPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PolyLineSelectionPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PolyLineSelectionPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PolyLineSelectionPlugin))
        return static_cast<void*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "INIInterface"))
        return static_cast< INIInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "SelectionInterface"))
        return static_cast< SelectionInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.INIInterface/1.2"))
        return static_cast< INIInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.SelectionInterface/1.1"))
        return static_cast< SelectionInterface*>(const_cast< PolyLineSelectionPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PolyLineSelectionPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void PolyLineSelectionPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PolyLineSelectionPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PolyLineSelectionPlugin::nodeVisibilityChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PolyLineSelectionPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PolyLineSelectionPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PolyLineSelectionPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PolyLineSelectionPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PolyLineSelectionPlugin::addSelectionEnvironment(QString _t1, QString _t2, QString _t3, QString & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PolyLineSelectionPlugin::registerType(QString _t1, DataType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PolyLineSelectionPlugin::addPrimitiveType(QString _t1, QString _t2, QString _t3, SelectionInterface::PrimitiveType & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PolyLineSelectionPlugin::addSelectionOperations(QString _t1, QStringList _t2, QString _t3, SelectionInterface::PrimitiveType _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 12
void PolyLineSelectionPlugin::showToggleSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void PolyLineSelectionPlugin::showVolumeLassoSelectionMode(QString _t1, bool _t2, SelectionInterface::PrimitiveType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void PolyLineSelectionPlugin::getActiveDataTypes(SelectionInterface::TypeList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void PolyLineSelectionPlugin::getActivePrimitiveType(SelectionInterface::PrimitiveType & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void PolyLineSelectionPlugin::targetObjectsOnly(bool & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void PolyLineSelectionPlugin::registerKeyShortcut(int _t1, Qt::KeyboardModifiers _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_END_MOC_NAMESPACE

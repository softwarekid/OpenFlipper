/****************************************************************************
** Meta object code from reading C++ file 'SelectionBasePlugin.hh'
**
** Created: Sat May 18 03:02:37 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Selection/Plugin-SelectionBase/SelectionBasePlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectionBasePlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectionBasePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      70,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      25,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   33,   33,   33, 0x05,
      34,   55,   33,   33, 0x05,
      70,   83,   33,   33, 0x05,
      92,  114,   33,   33, 0x05,
     123,  192,   33,   33, 0x05,
     222,  192,   33,   33, 0x05,
     290,  192,   33,   33, 0x05,
     364,  192,   33,   33, 0x05,
     439,  515,   33,   33, 0x05,
     553,  192,   33,   33, 0x05,
     631,  710,   33,   33, 0x05,
     750,  192,   33,   33, 0x05,
     823,  900,   33,   33, 0x05,
     948,  976,   33,   33, 0x05,
     987, 1010,   33,   33, 0x05,
    1016, 1010,   33,   33, 0x05,
    1040, 1084,   33,   33, 0x05,
    1100, 1122,   33,   33, 0x25,
    1127, 1152,   33,   33, 0x05,
    1158, 1201,   33,   33, 0x05,
    1222, 1261,   33,   33, 0x05,
    1275, 1317,   33,   33, 0x05,
    1332, 1384,   33,   33, 0x05,
    1423, 1470,   33,   33, 0x25,
    1499, 1535,   33,   33, 0x05,

 // slots: signature, parameters, type, tag, flags
    1555,   33,   33,   33, 0x08,
    1574,   33,   33,   33, 0x08,
    1595, 1641,   33,   33, 0x08,
    1654, 1683,   33,   33, 0x08,
    1690, 1752,   33,   33, 0x08,
    1793, 1828,   33,   33, 0x08,
    1846, 1927,   33,   33, 0x08,
    1963, 2066,   33,   33, 0x08,
    2142, 2254,   33,   33, 0x08,
    2353, 2443,   33,   33, 0x08,
    2487, 2543,   33,   33, 0x28,
    2581, 2657,   33,   33, 0x08,
    2692, 2657,   33,   33, 0x08,
    2767, 2657,   33,   33, 0x08,
    2848, 2657,   33,   33, 0x08,
    2930, 2657,   33,   33, 0x08,
    3006, 2657,   33,   33, 0x08,
    3091, 2657,   33,   33, 0x08,
    3170, 2657,   33,   33, 0x08,
    3250, 3304,   33,   33, 0x08,
    3311, 3374,   33,   33, 0x08,
    3380, 3409,   33,   33, 0x08,
    3422, 1084,   33,   33, 0x08,
    3473, 3495,   33,   33, 0x08,
    3499, 3495,   33,   33, 0x08,
    3518, 3551,   33,   33, 0x08,
    3561, 1683,   33,   33, 0x08,
    3586, 1683,   33,   33, 0x08,
    3618, 1683,   33,   33, 0x08,
    3657, 1683,   33,   33, 0x08,
    3695, 1683,   33,   33, 0x08,
    3739, 1683,   33,   33, 0x08,
    3784, 1683,   33,   33, 0x08,
    3823, 1683,   33,   33, 0x08,
    3864, 1683,   33,   33, 0x08,
    3906, 1683,   33,   33, 0x08,
    3949, 1683,   33,   33, 0x08,
    3988,   33,   33,   33, 0x08,
    4014,   33,   33,   33, 0x08,
    4040,   33,   33,   33, 0x08,
    4065,   33,   33,   33, 0x08,
    4093, 4133,   33,   33, 0x08,
    4142, 4133,   33,   33, 0x08,
    4171, 4133,   33,   33, 0x08,
    4204,   33, 4214,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SelectionBasePlugin[] = {
    "SelectionBasePlugin\0updateView()\0\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0addToolbar(QToolBar*)\0"
    "_toolbar\0"
    "toggleSelection(QMouseEvent*,SelectionInterface::PrimitiveType,bool)\0"
    "_event,_currentType,_deselect\0"
    "lassoSelection(QMouseEvent*,SelectionInterface::PrimitiveType,bool)\0"
    "volumeLassoSelection(QMouseEvent*,SelectionInterface::PrimitiveType,bo"
    "ol)\0"
    "surfaceLassoSelection(QMouseEvent*,SelectionInterface::PrimitiveType,b"
    "ool)\0"
    "sphereSelection(QMouseEvent*,double,SelectionInterface::PrimitiveType,"
    "bool)\0"
    "_event,_radius,_currentType,_deselect\0"
    "closestBoundarySelection(QMouseEvent*,SelectionInterface::PrimitiveTyp"
    "e,bool)\0"
    "floodFillSelection(QMouseEvent*,double,SelectionInterface::PrimitiveTy"
    "pe,bool)\0"
    "_event,_maxAngle,_currentType,_deselect\0"
    "componentsSelection(QMouseEvent*,SelectionInterface::PrimitiveType,boo"
    "l)\0"
    "customSelection(QMouseEvent*,SelectionInterface::PrimitiveType,QString"
    ",bool)\0"
    "_event,_currentType,_customIdentifier,_deselect\0"
    "selectionOperation(QString)\0_operation\0"
    "loadSelection(INIFile)\0_file\0"
    "saveSelection(INIFile&)\0"
    "keyShortcutEvent(int,Qt::KeyboardModifiers)\0"
    "_key,_modifiers\0keyShortcutEvent(int)\0"
    "_key\0addPickMode(std::string)\0_mode\0"
    "setPickModeMouseTracking(std::string,bool)\0"
    "_mode,_mouseTracking\0"
    "setPickModeCursor(std::string,QCursor)\0"
    "_mode,_cursor\0setPickModeToolbar(std::string,QToolBar*)\0"
    "_mode,_toolbar\0"
    "registerKey(int,Qt::KeyboardModifiers,QString,bool)\0"
    "_key,_modifiers,_description,_multiUse\0"
    "registerKey(int,Qt::KeyboardModifiers,QString)\0"
    "_key,_modifiers,_description\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0initializePlugin()\0"
    "pluginsInitialized()\0"
    "slotMouseWheelEvent(QWheelEvent*,std::string)\0"
    "_event,_mode\0slotMouseEvent(QMouseEvent*)\0"
    "_event\0"
    "slotAddSelectionEnvironment(QString,QString,QString,QString&)\0"
    "_modeName,_description,_icon,_handleName\0"
    "slotRegisterType(QString,DataType)\0"
    "_handleName,_type\0"
    "slotAddPrimitiveType(QString,QString,QString,SelectionInterface::Primi"
    "tiveType&)\0"
    "_handleName,_name,_icon,_typeHandle\0"
    "slotAddCustomSelectionMode(QString,QString,QString,QString,SelectionIn"
    "terface::PrimitiveType,QString&)\0"
    "_handleName,_modeName,_description,_icon,_associatedTypes,_customIdent"
    "ifier\0"
    "slotAddCustomSelectionMode(QString,QString,QString,QString,SelectionIn"
    "terface::PrimitiveType,QString&,DataType)\0"
    "_handleName,_modeName,_description,_icon,_associatedTypes,_customIdent"
    "ifier,_objectTypeRestriction\0"
    "slotAddSelectionOperations(QString,QStringList,QString,SelectionInterf"
    "ace::PrimitiveType)\0"
    "_handleName,_operationsList,_category,_type\0"
    "slotAddSelectionOperations(QString,QStringList,QString)\0"
    "_handleName,_operationsList,_category\0"
    "slotShowToggleSelectionMode(QString,bool,SelectionInterface::Primitive"
    "Type)\0"
    "_handleName,_show,_associatedTypes\0"
    "slotShowLassoSelectionMode(QString,bool,SelectionInterface::PrimitiveT"
    "ype)\0"
    "slotShowVolumeLassoSelectionMode(QString,bool,SelectionInterface::Prim"
    "itiveType)\0"
    "slotShowSurfaceLassoSelectionMode(QString,bool,SelectionInterface::Pri"
    "mitiveType)\0"
    "slotShowSphereSelectionMode(QString,bool,SelectionInterface::Primitive"
    "Type)\0"
    "slotShowClosestBoundarySelectionMode(QString,bool,SelectionInterface::"
    "PrimitiveType)\0"
    "slotShowFloodFillSelectionMode(QString,bool,SelectionInterface::Primit"
    "iveType)\0"
    "slotShowComponentsSelectionMode(QString,bool,SelectionInterface::Primi"
    "tiveType)\0"
    "slotGetActiveDataTypes(SelectionInterface::TypeList&)\0"
    "_types\0"
    "slotGetActivePrimitiveType(SelectionInterface::PrimitiveType&)\0"
    "_type\0slotTargetObjectsOnly(bool&)\0"
    "_targetsOnly\0"
    "slotRegisterKeyShortcut(int,Qt::KeyboardModifiers)\0"
    "addedEmptyObject(int)\0_id\0objectDeleted(int)\0"
    "slotPickModeChanged(std::string)\0"
    "_pickmode\0slotKeyEvent(QKeyEvent*)\0"
    "slotKeyReleaseEvent(QKeyEvent*)\0"
    "slotMouseToggleSelection(QMouseEvent*)\0"
    "slotMouseLassoSelection(QMouseEvent*)\0"
    "slotMouseVolumeLassoSelection(QMouseEvent*)\0"
    "slotMouseSurfaceLassoSelection(QMouseEvent*)\0"
    "slotMouseSphereSelection(QMouseEvent*)\0"
    "slotMouseBoundarySelection(QMouseEvent*)\0"
    "slotMouseFloodFillSelection(QMouseEvent*)\0"
    "slotMouseComponentsSelection(QMouseEvent*)\0"
    "slotMouseCustomSelection(QMouseEvent*)\0"
    "slotLoadSelectionButton()\0"
    "slotSaveSelectionButton()\0"
    "slotOperationRequested()\0"
    "slotShowAndHideOperations()\0"
    "slotSelectionEnvironmentRequested(bool)\0"
    "_checked\0slotEnterSelectionMode(bool)\0"
    "updateActivePrimitiveTypes(bool)\0"
    "version()\0QString\0"
};

void SelectionBasePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SelectionBasePlugin *_t = static_cast<SelectionBasePlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 4: _t->toggleSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->lassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->volumeLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->surfaceLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->sphereSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 9: _t->closestBoundarySelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->floodFillSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 11: _t->componentsSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->customSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 13: _t->selectionOperation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->loadSelection((*reinterpret_cast< const INIFile(*)>(_a[1]))); break;
        case 15: _t->saveSelection((*reinterpret_cast< INIFile(*)>(_a[1]))); break;
        case 16: _t->keyShortcutEvent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 17: _t->keyShortcutEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->addPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 19: _t->setPickModeMouseTracking((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->setPickModeCursor((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< QCursor(*)>(_a[2]))); break;
        case 21: _t->setPickModeToolbar((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 22: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 23: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 24: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 25: _t->initializePlugin(); break;
        case 26: _t->pluginsInitialized(); break;
        case 27: _t->slotMouseWheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 28: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 29: _t->slotAddSelectionEnvironment((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 30: _t->slotRegisterType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2]))); break;
        case 31: _t->slotAddPrimitiveType((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[4]))); break;
        case 32: _t->slotAddCustomSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 33: _t->slotAddCustomSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< DataType(*)>(_a[7]))); break;
        case 34: _t->slotAddSelectionOperations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[4]))); break;
        case 35: _t->slotAddSelectionOperations((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 36: _t->slotShowToggleSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 37: _t->slotShowLassoSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 38: _t->slotShowVolumeLassoSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 39: _t->slotShowSurfaceLassoSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 40: _t->slotShowSphereSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 41: _t->slotShowClosestBoundarySelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 42: _t->slotShowFloodFillSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 43: _t->slotShowComponentsSelectionMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[3]))); break;
        case 44: _t->slotGetActiveDataTypes((*reinterpret_cast< SelectionInterface::TypeList(*)>(_a[1]))); break;
        case 45: _t->slotGetActivePrimitiveType((*reinterpret_cast< SelectionInterface::PrimitiveType(*)>(_a[1]))); break;
        case 46: _t->slotTargetObjectsOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->slotRegisterKeyShortcut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2]))); break;
        case 48: _t->addedEmptyObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 51: _t->slotKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 52: _t->slotKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 53: _t->slotMouseToggleSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 54: _t->slotMouseLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 55: _t->slotMouseVolumeLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 56: _t->slotMouseSurfaceLassoSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 57: _t->slotMouseSphereSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 58: _t->slotMouseBoundarySelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 59: _t->slotMouseFloodFillSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 60: _t->slotMouseComponentsSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 61: _t->slotMouseCustomSelection((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 62: _t->slotLoadSelectionButton(); break;
        case 63: _t->slotSaveSelectionButton(); break;
        case 64: _t->slotOperationRequested(); break;
        case 65: _t->slotShowAndHideOperations(); break;
        case 66: _t->slotSelectionEnvironmentRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->slotEnterSelectionMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 68: _t->updateActivePrimitiveTypes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 69: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SelectionBasePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SelectionBasePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SelectionBasePlugin,
      qt_meta_data_SelectionBasePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SelectionBasePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SelectionBasePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SelectionBasePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectionBasePlugin))
        return static_cast<void*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "INIInterface"))
        return static_cast< INIInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "SelectionInterface"))
        return static_cast< SelectionInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.INIInterface/1.2"))
        return static_cast< INIInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< SelectionBasePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.SelectionInterface/1.1"))
        return static_cast< SelectionInterface*>(const_cast< SelectionBasePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int SelectionBasePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 70)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 70;
    }
    return _id;
}

// SIGNAL 0
void SelectionBasePlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SelectionBasePlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SelectionBasePlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SelectionBasePlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SelectionBasePlugin::toggleSelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SelectionBasePlugin::lassoSelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SelectionBasePlugin::volumeLassoSelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SelectionBasePlugin::surfaceLassoSelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SelectionBasePlugin::sphereSelection(QMouseEvent * _t1, double _t2, SelectionInterface::PrimitiveType _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SelectionBasePlugin::closestBoundarySelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SelectionBasePlugin::floodFillSelection(QMouseEvent * _t1, double _t2, SelectionInterface::PrimitiveType _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SelectionBasePlugin::componentsSelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SelectionBasePlugin::customSelection(QMouseEvent * _t1, SelectionInterface::PrimitiveType _t2, QString _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void SelectionBasePlugin::selectionOperation(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void SelectionBasePlugin::loadSelection(const INIFile & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void SelectionBasePlugin::saveSelection(INIFile & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void SelectionBasePlugin::keyShortcutEvent(int _t1, Qt::KeyboardModifiers _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 18
void SelectionBasePlugin::addPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void SelectionBasePlugin::setPickModeMouseTracking(const std::string & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void SelectionBasePlugin::setPickModeCursor(const std::string & _t1, QCursor _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void SelectionBasePlugin::setPickModeToolbar(const std::string & _t1, QToolBar * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void SelectionBasePlugin::registerKey(int _t1, Qt::KeyboardModifiers _t2, QString _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 24
void SelectionBasePlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}
QT_END_MOC_NAMESPACE

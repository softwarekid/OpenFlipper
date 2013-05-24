/****************************************************************************
** Meta object code from reading C++ file 'SkeletonEditingPlugin.hh'
**
** Created: Sat May 18 02:58:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-SkeletonEditing/SkeletonEditingPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SkeletonEditingPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SkeletonEditingPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   35,   35,   35, 0x05,
      36,   66,   35,   35, 0x05,
      73,   35,   35,   35, 0x05,
     100,  126,   35,   35, 0x05,
     148,  126,   35,   35, 0x05,
     182,  207,   35,   35, 0x05,
     213,  207,   35,   35, 0x05,
     244,  287,   35,   35, 0x05,
     308,  350,   35,   35, 0x05,
     365,  410,   35,   35, 0x05,
     424,  445,   35,   35, 0x05,
     460,  473,   35,   35, 0x05,
     482,  502,   35,   35, 0x05,
     516,  576,   35,   35, 0x05,
     629,  651,   35,   35, 0x05,
     660,  691,   35,   35, 0x05,
     706,  758,   35,   35, 0x05,
     797,  844,   35,   35, 0x25,
     873,  902,   35,   35, 0x05,
     916,  946,   35,   35, 0x05,
     956,  974,   35,   35, 0x05,
     978, 1015,   35,   35, 0x05,
    1037, 1063,   35,   35, 0x25,

 // slots: signature, parameters, type, tag, flags
    1079,   35,   35,   35, 0x08,
    1098,   35,   35,   35, 0x08,
    1119, 1153,   35,   35, 0x08,
    1163, 1209,   35,   35, 0x08,
    1222, 1251,   35,   35, 0x08,
    1258, 1251,   35,   35, 0x08,
    1283, 1251,   35,   35, 0x08,
    1315,  207,   35,   35, 0x08,
    1348, 1367,   35,   35, 0x0a,
    1388, 1413,   35,   35, 0x0a,
    1441, 1462,   35,   35, 0x0a,
    1481, 1515,   35,   35, 0x0a,
    1542, 1462, 1564,   35, 0x0a,
    1574, 1462, 1564,   35, 0x0a,
    1595, 1462, 1622,   35, 0x0a,
    1629, 1462, 1622,   35, 0x0a,
    1655, 1675, 1685,   35, 0x0a,
    1689, 1709, 1685,   35, 0x0a,
    1735, 1675, 1685,   35, 0x0a,
    1756, 1675, 1685,   35, 0x0a,
    1773, 1800,   35,   35, 0x0a,
    1833, 1863,   35,   35, 0x0a,
    1887, 1251,   35,   35, 0x0a,
    1912,   35, 1922,   35, 0x0a,
    1930, 1959,   35,   35, 0x08,
    1967, 1959,   35,   35, 0x08,
    1999,   35,   35,   35, 0x08,
    2017, 2078,   35,   35, 0x08,
    2091, 2149,   35,   35, 0x08,
    2155, 2183,   35,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SkeletonEditingPlugin[] = {
    "SkeletonEditingPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0,_type\0"
    "nodeVisibilityChanged(int)\0"
    "setRenderer(uint,QString)\0"
    "_viewer,_rendererName\0"
    "getCurrentRenderer(uint,QString&)\0"
    "addPickMode(std::string)\0_mode\0"
    "addHiddenPickMode(std::string)\0"
    "setPickModeMouseTracking(std::string,bool)\0"
    "_mode,_mouseTracking\0"
    "setPickModeToolbar(std::string,QToolBar*)\0"
    "_mode,_toolbar\0"
    "addContextMenuItem(QAction*,ContextMenuType)\0"
    "_action,_type\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "scriptInfo(QString)\0_functionName\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "addToolbar(QToolBar*)\0_toolbar\0"
    "getToolBar(QString,QToolBar*&)\0"
    "_name,_toolbar\0"
    "registerKey(int,Qt::KeyboardModifiers,QString,bool)\0"
    "_key,_modifiers,_description,_multiUse\0"
    "registerKey(int,Qt::KeyboardModifiers,QString)\0"
    "_key,_modifiers,_description\0"
    "addToolbox(QString,QWidget*)\0_name,_widget\0"
    "addEmptyObject(DataType,int&)\0_type,_id\0"
    "deleteObject(int)\0_id\0"
    "createBackup(int,QString,UpdateType)\0"
    "_objectid,_name,_type\0createBackup(int,QString)\0"
    "_objectid,_name\0initializePlugin()\0"
    "pluginsInitialized()\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "_id,_type\0slotMouseWheelEvent(QWheelEvent*,std::string)\0"
    "_event,_mode\0slotMouseEvent(QMouseEvent*)\0"
    "_event\0slotKeyEvent(QKeyEvent*)\0"
    "slotKeyReleaseEvent(QKeyEvent*)\0"
    "slotPickModeChanged(std::string)\0"
    "splitBone(int,int)\0_objectId,_tailJoint\0"
    "addJoint(int,int,Vector)\0"
    "_objectId,_parent,_position\0"
    "deleteJoint(int,int)\0_objectId,_jointId\0"
    "transformJoint(int,int,Matrix4x4)\0"
    "_objectId,_jointId,_matrix\0"
    "globalMatrix(int,int)\0Matrix4x4\0"
    "localMatrix(int,int)\0globalTranslation(int,int)\0"
    "Vector\0localTranslation(int,int)\0"
    "animationCount(int)\0_objectId\0int\0"
    "frameCount(int,int)\0_objectId,_animationIndex\0"
    "activeAnimation(int)\0activeFrame(int)\0"
    "setActivePose(int,int,int)\0"
    "_objectId,_animationIndex,_frame\0"
    "addAnimation(int,QString,int)\0"
    "_objectId,_name,_frames\0"
    "splitJoint(QMouseEvent*)\0version()\0"
    "QString\0slotSetEditingMode(QAction*)\0"
    "_action\0slotPickToolbarAction(QAction*)\0"
    "setDescriptions()\0"
    "manipulatorMoved(QtTranslationManipulatorNode*,QMouseEvent*)\0"
    "_node,_event\0"
    "ManipulatorPositionChanged(QtTranslationManipulatorNode*)\0"
    "_node\0slotRotateManipulator(bool)\0"
    "_toggled\0"
};

void SkeletonEditingPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SkeletonEditingPlugin *_t = static_cast<SkeletonEditingPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->nodeVisibilityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setRenderer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->getCurrentRenderer((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->addPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 6: _t->addHiddenPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 7: _t->setPickModeMouseTracking((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->setPickModeToolbar((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 9: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< ContextMenuType(*)>(_a[2]))); break;
        case 10: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 14: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 15: _t->getToolBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 16: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 17: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 18: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 19: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 22: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 23: _t->initializePlugin(); break;
        case 24: _t->pluginsInitialized(); break;
        case 25: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 26: _t->slotMouseWheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2]))); break;
        case 27: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 28: _t->slotKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 29: _t->slotKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 30: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 31: _t->splitBone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 32: _t->addJoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Vector(*)>(_a[3]))); break;
        case 33: _t->deleteJoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->transformJoint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Matrix4x4(*)>(_a[3]))); break;
        case 35: { Matrix4x4 _r = _t->globalMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Matrix4x4*>(_a[0]) = _r; }  break;
        case 36: { Matrix4x4 _r = _t->localMatrix((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Matrix4x4*>(_a[0]) = _r; }  break;
        case 37: { Vector _r = _t->globalTranslation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 38: { Vector _r = _t->localTranslation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 39: { int _r = _t->animationCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 40: { int _r = _t->frameCount((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 41: { int _r = _t->activeAnimation((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 42: { int _r = _t->activeFrame((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 43: _t->setActivePose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 44: _t->addAnimation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 45: _t->splitJoint((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 46: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 47: _t->slotSetEditingMode((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 48: _t->slotPickToolbarAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 49: _t->setDescriptions(); break;
        case 50: _t->manipulatorMoved((*reinterpret_cast< QtTranslationManipulatorNode*(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 51: _t->ManipulatorPositionChanged((*reinterpret_cast< QtTranslationManipulatorNode*(*)>(_a[1]))); break;
        case 52: _t->slotRotateManipulator((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SkeletonEditingPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SkeletonEditingPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SkeletonEditingPlugin,
      qt_meta_data_SkeletonEditingPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SkeletonEditingPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SkeletonEditingPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SkeletonEditingPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SkeletonEditingPlugin))
        return static_cast<void*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< SkeletonEditingPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int SkeletonEditingPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    }
    return _id;
}

// SIGNAL 0
void SkeletonEditingPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SkeletonEditingPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SkeletonEditingPlugin::nodeVisibilityChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SkeletonEditingPlugin::setRenderer(unsigned int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SkeletonEditingPlugin::getCurrentRenderer(unsigned int _t1, QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SkeletonEditingPlugin::addPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SkeletonEditingPlugin::addHiddenPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SkeletonEditingPlugin::setPickModeMouseTracking(const std::string & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SkeletonEditingPlugin::setPickModeToolbar(const std::string & _t1, QToolBar * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SkeletonEditingPlugin::addContextMenuItem(QAction * _t1, ContextMenuType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SkeletonEditingPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SkeletonEditingPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SkeletonEditingPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void SkeletonEditingPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void SkeletonEditingPlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void SkeletonEditingPlugin::getToolBar(QString _t1, QToolBar * & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void SkeletonEditingPlugin::registerKey(int _t1, Qt::KeyboardModifiers _t2, QString _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 18
void SkeletonEditingPlugin::addToolbox(QString _t1, QWidget * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void SkeletonEditingPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void SkeletonEditingPlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void SkeletonEditingPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}
QT_END_MOC_NAMESPACE

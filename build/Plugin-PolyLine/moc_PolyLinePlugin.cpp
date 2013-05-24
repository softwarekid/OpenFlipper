/****************************************************************************
** Meta object code from reading C++ file 'PolyLinePlugin.hh'
**
** Created: Sat May 18 02:57:14 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PolyLine/PolyLinePlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PolyLinePlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PolyLinePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      37,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   28,   28,   28, 0x05,
      29,   59,   28,   28, 0x05,
      77,  102,   28,   28, 0x05,
     108,  102,   28,   28, 0x05,
     139,  181,   28,   28, 0x05,
     196,  217,   28,   28, 0x05,
     232,  245,   28,   28, 0x05,
     254,  276,   28,   28, 0x05,
     285,  316,   28,   28, 0x05,
     331,  351,   28,   28, 0x05,
     365,  401,   28,   28, 0x05,
     421,  439,   28,   28, 0x05,
     443,  473,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
     483,   28,   28,   28, 0x08,
     502,   28,   28,   28, 0x08,
     524,  553,   28,   28, 0x08,
     560,  102,   28,   28, 0x08,
     593,   28,   28,   28, 0x08,
     614,  642,   28,   28, 0x0a,
     648,   28,   28,   28, 0x08,
     665,  694,   28,   28, 0x08,
     703,   28,   28,   28, 0x08,
     719,  694,   28,   28, 0x08,
     747,   28,   28,   28, 0x08,
     761,  791,   28,   28, 0x08,
     796,   28,   28,   28, 0x08,
     811,  791,   28,   28, 0x08,
     842,   28,   28,   28, 0x08,
     864,  791,   28,   28, 0x08,
     902,   28,   28,   28, 0x08,
     926,  956,   28,   28, 0x08,
     964,  956,   28,   28, 0x08,
     996,   28, 1006,   28, 0x0a,
    1014, 1061, 1108,   28, 0x0a,
    1112, 1155, 1108,   28, 0x2a,
    1190,   28,   28,   28, 0x08,
    1210,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PolyLinePlugin[] = {
    "PolyLinePlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0"
    "_identifier,_type\0addPickMode(std::string)\0"
    "_mode\0addHiddenPickMode(std::string)\0"
    "setPickModeToolbar(std::string,QToolBar*)\0"
    "_mode,_toolbar\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "addToolbar(QToolBar*)\0_toolbar\0"
    "getToolBar(QString,QToolBar*&)\0"
    "_name,_toolbar\0scriptInfo(QString)\0"
    "_functionName\0addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0deleteObject(int)\0"
    "_id\0addEmptyObject(DataType,int&)\0"
    "_type,_id\0initializePlugin()\0"
    "slotEditModeChanged()\0"
    "slotMouseEvent(QMouseEvent*)\0_event\0"
    "slotPickModeChanged(std::string)\0"
    "pluginsInitialized()\0slotEnablePickMode(QString)\0"
    "_name\0slot_subdivide()\0"
    "slot_subdivide_percent(bool)\0_checked\0"
    "slot_decimate()\0slot_decimate_percent(bool)\0"
    "slot_smooth()\0slot_smooth(PolyLineObject*&)\0"
    "_pol\0slot_project()\0slot_project(PolyLineObject*&)\0"
    "slot_smooth_project()\0"
    "slot_smooth_project(PolyLineObject*&)\0"
    "slot_smart_move_timer()\0"
    "slotSetPolyLineMode(QAction*)\0_action\0"
    "slotPickToolbarAction(QAction*)\0"
    "version()\0QString\0"
    "generatePolyLineFromCut(int,Vector,Vector,int)\0"
    "_objectId,_planePoint,_planeNormal,_polyLineId\0"
    "int\0generatePolyLineFromCut(int,Vector,Vector)\0"
    "_objectId,_planePoint,_planeNormal\0"
    "slotScissorButton()\0slotTriggerCutPlaneSelect()\0"
};

void PolyLinePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PolyLinePlugin *_t = static_cast<PolyLinePlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->addPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 3: _t->addHiddenPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 4: _t->setPickModeToolbar((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 5: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 8: _t->getToolBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 9: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 11: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->initializePlugin(); break;
        case 14: _t->slotEditModeChanged(); break;
        case 15: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 16: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 17: _t->pluginsInitialized(); break;
        case 18: _t->slotEnablePickMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->slot_subdivide(); break;
        case 20: _t->slot_subdivide_percent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->slot_decimate(); break;
        case 22: _t->slot_decimate_percent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->slot_smooth(); break;
        case 24: _t->slot_smooth((*reinterpret_cast< PolyLineObject*(*)>(_a[1]))); break;
        case 25: _t->slot_project(); break;
        case 26: _t->slot_project((*reinterpret_cast< PolyLineObject*(*)>(_a[1]))); break;
        case 27: _t->slot_smooth_project(); break;
        case 28: _t->slot_smooth_project((*reinterpret_cast< PolyLineObject*(*)>(_a[1]))); break;
        case 29: _t->slot_smart_move_timer(); break;
        case 30: _t->slotSetPolyLineMode((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 31: _t->slotPickToolbarAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 32: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 33: { int _r = _t->generatePolyLineFromCut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Vector(*)>(_a[2])),(*reinterpret_cast< Vector(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 34: { int _r = _t->generatePolyLineFromCut((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Vector(*)>(_a[2])),(*reinterpret_cast< Vector(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 35: _t->slotScissorButton(); break;
        case 36: _t->slotTriggerCutPlaneSelect(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PolyLinePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PolyLinePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PolyLinePlugin,
      qt_meta_data_PolyLinePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PolyLinePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PolyLinePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PolyLinePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PolyLinePlugin))
        return static_cast<void*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< PolyLinePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< PolyLinePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PolyLinePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    return _id;
}

// SIGNAL 0
void PolyLinePlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PolyLinePlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PolyLinePlugin::addPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PolyLinePlugin::addHiddenPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PolyLinePlugin::setPickModeToolbar(const std::string & _t1, QToolBar * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PolyLinePlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PolyLinePlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void PolyLinePlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void PolyLinePlugin::getToolBar(QString _t1, QToolBar * & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void PolyLinePlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void PolyLinePlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void PolyLinePlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void PolyLinePlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE

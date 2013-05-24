/****************************************************************************
** Meta object code from reading C++ file 'TopologyPlugin.hh'
**
** Created: Sat May 18 02:59:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Topology/TopologyPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TopologyPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TopologyPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   28,   28,   28, 0x05,
      29,   59,   28,   28, 0x05,
      69,  100,   28,   28, 0x05,
     106,  143,   28,   28, 0x05,
     165,  191,   28,   28, 0x25,
     207,  228,   28,   28, 0x05,
     243,  256,   28,   28, 0x05,
     265,  287,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
     296,   28,   28,   28, 0x08,
     317,  100,   28,   28, 0x08,
     350,  379,   28,   28, 0x08,
     386,  413,   28,   28, 0x08,
     421,   28,  431,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TopologyPlugin[] = {
    "TopologyPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "addHiddenPickMode(std::string)\0_mode\0"
    "createBackup(int,QString,UpdateType)\0"
    "_objectid,_name,_type\0createBackup(int,QString)\0"
    "_objectid,_name\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "addToolbar(QToolBar*)\0_toolbar\0"
    "pluginsInitialized()\0"
    "slotPickModeChanged(std::string)\0"
    "slotMouseEvent(QMouseEvent*)\0_event\0"
    "toolBarTriggered(QAction*)\0_action\0"
    "version()\0QString\0"
};

void TopologyPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TopologyPlugin *_t = static_cast<TopologyPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->addHiddenPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 3: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 4: _t->createBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 8: _t->pluginsInitialized(); break;
        case 9: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 10: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 11: _t->toolBarTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 12: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TopologyPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TopologyPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TopologyPlugin,
      qt_meta_data_TopologyPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TopologyPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TopologyPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TopologyPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TopologyPlugin))
        return static_cast<void*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TopologyPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< TopologyPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TopologyPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TopologyPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TopologyPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TopologyPlugin::addHiddenPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TopologyPlugin::createBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void TopologyPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TopologyPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TopologyPlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE

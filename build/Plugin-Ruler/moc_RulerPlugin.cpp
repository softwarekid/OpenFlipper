/****************************************************************************
** Meta object code from reading C++ file 'RulerPlugin.hh'
**
** Created: Sat May 18 02:58:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Ruler/RulerPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RulerPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RulerPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   34,   43,   43, 0x05,
      44,   69,   43,   43, 0x05,
      75,   43,   43,   43, 0x05,
      88,  131,   43,   43, 0x05,

 // slots: signature, parameters, type, tag, flags
     152,   69,   43,   43, 0x0a,
     185,  214,   43,   43, 0x0a,
     221,   43,   43,   43, 0x08,
     240,   43,   43,   43, 0x08,
     261,   43,   43,   43, 0x08,
     276,   43,   43,   43, 0x08,
     297,   43,   43,   43, 0x08,
     314,   43,  324,   43, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RulerPlugin[] = {
    "RulerPlugin\0addToolbar(QToolBar*)\0"
    "_toolbar\0\0addPickMode(std::string)\0"
    "_mode\0updateView()\0"
    "setPickModeMouseTracking(std::string,bool)\0"
    "_mode,_mouseTracking\0"
    "slotPickModeChanged(std::string)\0"
    "slotMouseEvent(QMouseEvent*)\0_event\0"
    "initializePlugin()\0pluginsInitialized()\0"
    "showDistance()\0slotChangePickMode()\0"
    "slotAllCleared()\0version()\0QString\0"
};

void RulerPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RulerPlugin *_t = static_cast<RulerPlugin *>(_o);
        switch (_id) {
        case 0: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 1: _t->addPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 2: _t->updateView(); break;
        case 3: _t->setPickModeMouseTracking((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 5: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->initializePlugin(); break;
        case 7: _t->pluginsInitialized(); break;
        case 8: _t->showDistance(); break;
        case 9: _t->slotChangePickMode(); break;
        case 10: _t->slotAllCleared(); break;
        case 11: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RulerPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RulerPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RulerPlugin,
      qt_meta_data_RulerPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RulerPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RulerPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RulerPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RulerPlugin))
        return static_cast<void*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< RulerPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< RulerPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int RulerPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void RulerPlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RulerPlugin::addPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RulerPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void RulerPlugin::setPickModeMouseTracking(const std::string & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

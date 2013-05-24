/****************************************************************************
** Meta object code from reading C++ file 'TypeLight.hh'
**
** Created: Sat May 18 03:04:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-TypePlugins/Plugin-TypeLight/TypeLight.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TypeLight.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TypeLightPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   37,   52,   52, 0x05,
      53,   66,   52,   52, 0x05,
      75,  105,   52,   52, 0x05,
     115,  137,   52,   52, 0x05,
     141,  137,   52,   52, 0x05,
     159,  189,   52,   52, 0x05,
     199,   52,   52,   52, 0x05,
     212,  243,   52,   52, 0x05,
     258,  283,   52,   52, 0x05,
     289,  283,   52,   52, 0x05,
     320,  363,   52,   52, 0x05,
     384,  426,   52,   52, 0x05,

 // slots: signature, parameters, type, tag, flags
     441,   52,   52,   52, 0x08,
     458,  491,   52,   52, 0x08,
     501,   52,   52,   52, 0x08,
     518,   52,   52,   52, 0x08,
     537,   52,   52,   52, 0x08,
     559,  137,   52,   52, 0x08,
     581,  137,   52,   52, 0x08,
     600,  634,   52,   52, 0x08,
     641,   52,  651,   52, 0x0a,
     659,   52,  670,   52, 0x0a,
     674,   52,  690,   52, 0x0a,
     699,   52,   52,   52, 0x0a,
     720,  745,  670,   52, 0x0a,
     751,  778,   52,   52, 0x08,
     787,  817,   52,   52, 0x08,
     825,  778,   52,   52, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TypeLightPlugin[] = {
    "TypeLightPlugin\0log(Logtype,QString)\0"
    "_type,_message\0\0log(QString)\0_message\0"
    "addEmptyObject(DataType,int&)\0_type,_id\0"
    "emptyObjectAdded(int)\0_id\0deleteObject(int)\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "updateView()\0getToolBar(QString,QToolBar*&)\0"
    "_name,_toolbar\0addPickMode(std::string)\0"
    "_mode\0addHiddenPickMode(std::string)\0"
    "setPickModeMouseTracking(std::string,bool)\0"
    "_mode,_mouseTracking\0"
    "setPickModeToolbar(std::string,QToolBar*)\0"
    "_mode,_toolbar\0noguiSupported()\0"
    "slotPickModeChanged(std::string)\0"
    "_pickMode\0slotAllCleared()\0"
    "addDefaultLights()\0removeDefaultLights()\0"
    "addedEmptyObject(int)\0objectDeleted(int)\0"
    "slotMouseEventLight(QMouseEvent*)\0"
    "_event\0version()\0QString\0addEmpty()\0"
    "int\0supportedType()\0DataType\0"
    "pluginsInitialized()\0addDefaultLight(QString)\0"
    "_name\0slotLightModeRequest(bool)\0"
    "_checked\0slotPickModeRequest(QAction*)\0"
    "_action\0slotSetAllOrTarget(bool)\0"
};

void TypeLightPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TypeLightPlugin *_t = static_cast<TypeLightPlugin *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 6: _t->updateView(); break;
        case 7: _t->getToolBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 8: _t->addPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 9: _t->addHiddenPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 10: _t->setPickModeMouseTracking((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 11: _t->setPickModeToolbar((*reinterpret_cast< const std::string(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 12: _t->noguiSupported(); break;
        case 13: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 14: _t->slotAllCleared(); break;
        case 15: _t->addDefaultLights(); break;
        case 16: _t->removeDefaultLights(); break;
        case 17: _t->addedEmptyObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->slotMouseEventLight((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 20: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: { int _r = _t->addEmpty();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 22: { DataType _r = _t->supportedType();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 23: _t->pluginsInitialized(); break;
        case 24: { int _r = _t->addDefaultLight((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 25: _t->slotLightModeRequest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->slotPickModeRequest((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 27: _t->slotSetAllOrTarget((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TypeLightPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TypeLightPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TypeLightPlugin,
      qt_meta_data_TypeLightPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TypeLightPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TypeLightPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TypeLightPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TypeLightPlugin))
        return static_cast<void*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "TypeInterface"))
        return static_cast< TypeInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TypeInterface/1.1"))
        return static_cast< TypeInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< TypeLightPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< TypeLightPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TypeLightPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void TypeLightPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TypeLightPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TypeLightPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TypeLightPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TypeLightPlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TypeLightPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TypeLightPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void TypeLightPlugin::getToolBar(QString _t1, QToolBar * & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TypeLightPlugin::addPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TypeLightPlugin::addHiddenPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TypeLightPlugin::setPickModeMouseTracking(const std::string & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void TypeLightPlugin::setPickModeToolbar(const std::string & _t1, QToolBar * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE

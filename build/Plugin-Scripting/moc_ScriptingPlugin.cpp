/****************************************************************************
** Meta object code from reading C++ file 'ScriptingPlugin.hh'
**
** Created: Sat May 18 02:58:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Scripting/ScriptingPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptingPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ScriptingPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   29,   29,   29, 0x05,
      30,   66,   29,   29, 0x05,
      74,  110,   29,   29, 0x05,
     121,  142,   29,   29, 0x05,
     157,  170,   29,   29, 0x05,
     179,  216,   29,   29, 0x05,
     236,  295,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
     344,  376,   29,   29, 0x08,
     402,  429,   29,   29, 0x08,
     437,  468,   29,   29, 0x08,
     478,   29,   29,   29, 0x08,
     495,   29,   29,   29, 0x08,
     512,   29,   29,   29, 0x08,
     531,   29,   29,   29, 0x08,
     552,   29,   29,   29, 0x08,
     569,   29,   29,   29, 0x08,
     595,   29,   29,   29, 0x08,
     615,  653,   29,   29, 0x08,
     659,  653,   29,   29, 0x08,
     703,   29,   29,   29, 0x08,
     721,   29,   29,   29, 0x08,
     742,   29,   29,   29, 0x08,
     763,   29,   29,   29, 0x0a,
     782,   29,   29,   29, 0x0a,
     801,  829,   29,   29, 0x0a,
     835,  468,   29,   29, 0x0a,
     859,   29,   29,   29, 0x0a,
     873,   29,   29,   29, 0x0a,
     888,  918,   29,   29, 0x0a,
     929,  955,   29,   29, 0x2a,
     963,  985,   29,   29, 0x2a,
     990, 1001,   29,   29, 0x0a,
    1010, 1026,   29,   29, 0x0a,
    1036,   29,   29,   29, 0x0a,
    1049, 1026,   29,   29, 0x0a,
    1067,   29, 1077,   29, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ScriptingPlugin[] = {
    "ScriptingPlugin\0updateView()\0\0"
    "getScriptingEngine(QScriptEngine*&)\0"
    "_engine\0getAvailableFunctions(QStringList&)\0"
    "_functions\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "getMenubarMenu(QString,QMenu*&,bool)\0"
    "_name,_menu,_create\0"
    "getDescription(QString,QString&,QStringList&,QStringList&)\0"
    "_function,_description,_parameters,_descriptions\0"
    "slotScriptInfo(QString,QString)\0"
    "_pluginName,_functionName\0"
    "slotExecuteScript(QString)\0_script\0"
    "slotExecuteFileScript(QString)\0_filename\0"
    "slotLoadScript()\0slotSaveScript()\0"
    "slotSaveScriptAs()\0pluginsInitialized()\0"
    "noguiSupported()\0slotExecuteScriptButton()\0"
    "slotScriptChanged()\0"
    "slotFunctionClicked(QListWidgetItem*)\0"
    "_item\0slotFunctionDoubleClicked(QListWidgetItem*)\0"
    "slotApplyFilter()\0slotHighlightError()\0"
    "slotDebuggerButton()\0showScriptWidget()\0"
    "hideScriptWidget()\0showScriptInEditor(QString)\0"
    "_code\0slotLoadScript(QString)\0"
    "clearEditor()\0waitContinue()\0"
    "waitContinue(QString,int,int)\0_msg,_x,_y\0"
    "waitContinue(QString,int)\0_msg,_x\0"
    "waitContinue(QString)\0_msg\0sleep(int)\0"
    "_seconds\0sleepmsecs(int)\0_mseconds\0"
    "frameStart()\0waitFrameEnd(int)\0version()\0"
    "QString\0"
};

void ScriptingPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ScriptingPlugin *_t = static_cast<ScriptingPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->getScriptingEngine((*reinterpret_cast< QScriptEngine*(*)>(_a[1]))); break;
        case 2: _t->getAvailableFunctions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->getMenubarMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMenu*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->getDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 7: _t->slotScriptInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->slotExecuteScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slotExecuteFileScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slotLoadScript(); break;
        case 11: _t->slotSaveScript(); break;
        case 12: _t->slotSaveScriptAs(); break;
        case 13: _t->pluginsInitialized(); break;
        case 14: _t->noguiSupported(); break;
        case 15: _t->slotExecuteScriptButton(); break;
        case 16: _t->slotScriptChanged(); break;
        case 17: _t->slotFunctionClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 18: _t->slotFunctionDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 19: _t->slotApplyFilter(); break;
        case 20: _t->slotHighlightError(); break;
        case 21: _t->slotDebuggerButton(); break;
        case 22: _t->showScriptWidget(); break;
        case 23: _t->hideScriptWidget(); break;
        case 24: _t->showScriptInEditor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->slotLoadScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->clearEditor(); break;
        case 27: _t->waitContinue(); break;
        case 28: _t->waitContinue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 29: _t->waitContinue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 30: _t->waitContinue((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: _t->sleep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->sleepmsecs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->frameStart(); break;
        case 34: _t->waitFrameEnd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ScriptingPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ScriptingPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScriptingPlugin,
      qt_meta_data_ScriptingPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ScriptingPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ScriptingPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ScriptingPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptingPlugin))
        return static_cast<void*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< ScriptingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< ScriptingPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int ScriptingPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void ScriptingPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ScriptingPlugin::getScriptingEngine(QScriptEngine * & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScriptingPlugin::getAvailableFunctions(QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ScriptingPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ScriptingPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ScriptingPlugin::getMenubarMenu(QString _t1, QMenu * & _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ScriptingPlugin::getDescription(QString _t1, QString & _t2, QStringList & _t3, QStringList & _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

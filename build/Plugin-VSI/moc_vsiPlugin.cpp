/****************************************************************************
** Meta object code from reading C++ file 'vsiPlugin.hh'
**
** Created: Sat May 18 02:59:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/vsiPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vsiPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VsiPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,   47,   67,   67, 0x05,
      68,  104,   67,   67, 0x05,
     112,  140,   67,   67, 0x05,
     160,  198,   67,   67, 0x05,

 // slots: signature, parameters, type, tag, flags
     232,  262,  279,   67, 0x0a,
     292,  312,   67,   67, 0x0a,
     321,  312,  342,   67, 0x0a,
     347,  312,  342,   67, 0x0a,
     368,   67,  378,   67, 0x0a,
     386,   67,   67,   67, 0x08,
     407,   67,   67,   67, 0x08,
     424,   67,   67,   67, 0x08,
     443,  471,   67,   67, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VsiPlugin[] = {
    "VsiPlugin\0getMenubarMenu(QString,QMenu*&,bool)\0"
    "_name,_menu,_create\0\0"
    "getScriptingEngine(QScriptEngine*&)\0"
    "_engine\0pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0"
    "functionExists(QString,QString,bool&)\0"
    "_pluginName,_functionName,_exists\0"
    "askForInputs(QString,QString)\0"
    "_element,_inputs\0QScriptValue\0"
    "messageBox(QString)\0_message\0"
    "questionBox(QString)\0bool\0"
    "continueBox(QString)\0version()\0QString\0"
    "pluginsInitialized()\0noguiSupported()\0"
    "showScriptEditor()\0showInScriptEditor(QString)\0"
    "_script\0"
};

void VsiPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VsiPlugin *_t = static_cast<VsiPlugin *>(_o);
        switch (_id) {
        case 0: _t->getMenubarMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMenu*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->getScriptingEngine((*reinterpret_cast< QScriptEngine*(*)>(_a[1]))); break;
        case 2: _t->pluginExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->functionExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: { QScriptValue _r = _t->askForInputs((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 5: _t->messageBox((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { bool _r = _t->questionBox((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->continueBox((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: _t->pluginsInitialized(); break;
        case 10: _t->noguiSupported(); break;
        case 11: _t->showScriptEditor(); break;
        case 12: _t->showInScriptEditor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VsiPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VsiPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VsiPlugin,
      qt_meta_data_VsiPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VsiPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VsiPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VsiPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VsiPlugin))
        return static_cast<void*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< VsiPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< VsiPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int VsiPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void VsiPlugin::getMenubarMenu(QString _t1, QMenu * & _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VsiPlugin::getScriptingEngine(QScriptEngine * & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VsiPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void VsiPlugin::functionExists(QString _t1, QString _t2, bool & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
static const uint qt_meta_data_QContinueBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QContinueBox[] = {
    "QContinueBox\0clicked()\0\0"
};

void QContinueBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QContinueBox *_t = static_cast<QContinueBox *>(_o);
        switch (_id) {
        case 0: _t->clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QContinueBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QContinueBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QContinueBox,
      qt_meta_data_QContinueBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QContinueBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QContinueBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QContinueBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QContinueBox))
        return static_cast<void*>(const_cast< QContinueBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int QContinueBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

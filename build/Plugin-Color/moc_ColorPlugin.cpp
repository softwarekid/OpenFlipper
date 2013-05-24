/****************************************************************************
** Meta object code from reading C++ file 'ColorPlugin.hh'
**
** Created: Sat May 18 02:52:43 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Color/ColorPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   25,   25,   25, 0x05,
      26,   46,   25,   25, 0x05,
      60,   95,   25,   25, 0x05,
     109,  131,   25,   25, 0x05,
     140,  131,   25,   25, 0x05,
     165,  196,   25,   25, 0x05,
     214,  241,   25,   25, 0x25,

 // slots: signature, parameters, type, tag, flags
     250,   25,   25,   25, 0x08,
     271,   25,   25,   25, 0x08,
     286,  315,   25,   25, 0x08,
     320,  315,   25,   25, 0x08,
     349,   25,   25,   25, 0x08,
     366,   25,   25,   25, 0x0a,
     384,   25,   25,   25, 0x0a,
     407,   25,   25,   25, 0x0a,
     423,  450,   25,   25, 0x0a,
     457,  493,   25,   25, 0x0a,
     510,  493,   25,   25, 0x0a,
     545,  493,   25,   25, 0x0a,
     580,  493,   25,   25, 0x0a,
     616,   25,  626,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ColorPlugin[] = {
    "ColorPlugin\0updateView()\0\0scriptInfo(QString)\0"
    "_functionName\0addMenubarAction(QAction*,QString)\0"
    "_action,_type\0addToolbar(QToolBar*)\0"
    "_toolbar\0removeToolbar(QToolBar*)\0"
    "showStatusMessage(QString,int)\0"
    "_message,_timeout\0showStatusMessage(QString)\0"
    "_message\0pluginsInitialized()\0"
    "applyOptions()\0loadIniFileOptions(INIFile&)\0"
    "_ini\0saveIniFileOptions(INIFile&)\0"
    "getColorDialog()\0setDefaultColor()\0"
    "setPresentationColor()\0setPaperColor()\0"
    "setBackgroundColor(Vector)\0_color\0"
    "setObjectEmissiveColor(int,Vector4)\0"
    "_objectId,_color\0setObjectAmbientColor(int,Vector4)\0"
    "setObjectDiffuseColor(int,Vector4)\0"
    "setObjectSpecularColor(int,Vector4)\0"
    "version()\0QString\0"
};

void ColorPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorPlugin *_t = static_cast<ColorPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->scriptInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addMenubarAction((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 4: _t->removeToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 5: _t->showStatusMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->showStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->pluginsInitialized(); break;
        case 8: _t->applyOptions(); break;
        case 9: _t->loadIniFileOptions((*reinterpret_cast< INIFile(*)>(_a[1]))); break;
        case 10: _t->saveIniFileOptions((*reinterpret_cast< INIFile(*)>(_a[1]))); break;
        case 11: _t->getColorDialog(); break;
        case 12: _t->setDefaultColor(); break;
        case 13: _t->setPresentationColor(); break;
        case 14: _t->setPaperColor(); break;
        case 15: _t->setBackgroundColor((*reinterpret_cast< Vector(*)>(_a[1]))); break;
        case 16: _t->setObjectEmissiveColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Vector4(*)>(_a[2]))); break;
        case 17: _t->setObjectAmbientColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Vector4(*)>(_a[2]))); break;
        case 18: _t->setObjectDiffuseColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Vector4(*)>(_a[2]))); break;
        case 19: _t->setObjectSpecularColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Vector4(*)>(_a[2]))); break;
        case 20: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ColorPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ColorPlugin,
      qt_meta_data_ColorPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorPlugin))
        return static_cast<void*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "StatusbarInterface"))
        return static_cast< StatusbarInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OptionsInterface"))
        return static_cast< OptionsInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "INIInterface"))
        return static_cast< INIInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.StatusbarInterface/1.0"))
        return static_cast< StatusbarInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.OptionsInterface/1.0"))
        return static_cast< OptionsInterface*>(const_cast< ColorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.INIInterface/1.2"))
        return static_cast< INIInterface*>(const_cast< ColorPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int ColorPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void ColorPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ColorPlugin::scriptInfo(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ColorPlugin::addMenubarAction(QAction * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ColorPlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ColorPlugin::removeToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ColorPlugin::showStatusMessage(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

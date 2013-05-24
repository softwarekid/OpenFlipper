/****************************************************************************
** Meta object code from reading C++ file 'RenderPickingPlugin.hh'
**
** Created: Sat May 18 03:02:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Renderers/Plugin-Render-Picking/RenderPickingPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RenderPickingPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RenderPickingPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   30,   31,   30, 0x0a,
      39,   30,   55,   30, 0x0a,
      64,   30,   30,   30, 0x08,
      83,  131,   30,   30, 0x08,
     152,   30,   31,   30, 0x08,
     167,  225,   30,   30, 0x08,
     231,   30,   31,   30, 0x08,
     245,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RenderPickingPlugin[] = {
    "RenderPickingPlugin\0version()\0\0QString\0"
    "optionsAction()\0QAction*\0initializePlugin()\0"
    "render(ACG::GLState*,Viewer::ViewerProperties&)\0"
    "_glState,_properties\0rendererName()\0"
    "supportedDrawModes(ACG::SceneGraph::DrawModes::DrawMode&)\0"
    "_mode\0checkOpenGL()\0slotPickTargetChanged(QAction*)\0"
};

void RenderPickingPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RenderPickingPlugin *_t = static_cast<RenderPickingPlugin *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QAction* _r = _t->optionsAction();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = _r; }  break;
        case 2: _t->initializePlugin(); break;
        case 3: _t->render((*reinterpret_cast< ACG::GLState*(*)>(_a[1])),(*reinterpret_cast< Viewer::ViewerProperties(*)>(_a[2]))); break;
        case 4: { QString _r = _t->rendererName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: _t->supportedDrawModes((*reinterpret_cast< ACG::SceneGraph::DrawModes::DrawMode(*)>(_a[1]))); break;
        case 6: { QString _r = _t->checkOpenGL();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: _t->slotPickTargetChanged((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RenderPickingPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RenderPickingPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RenderPickingPlugin,
      qt_meta_data_RenderPickingPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RenderPickingPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RenderPickingPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RenderPickingPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RenderPickingPlugin))
        return static_cast<void*>(const_cast< RenderPickingPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< RenderPickingPlugin*>(this));
    if (!strcmp(_clname, "RenderInterface"))
        return static_cast< RenderInterface*>(const_cast< RenderPickingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< RenderPickingPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RenderInterface/1.0"))
        return static_cast< RenderInterface*>(const_cast< RenderPickingPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int RenderPickingPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'Renderer.hh'
**
** Created: Sat May 18 03:02:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Renderers/Plugin-Render-Classic/Renderer.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Renderer.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Renderer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,   30,   45,   45, 0x05,
      46,   59,   45,   45, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   45,   78,   45, 0x0a,
      86,   45,   45,   45, 0x08,
     105,  153,   45,   45, 0x08,
     174,   45,   78,   45, 0x08,
     189,  247,   45,   45, 0x08,
     253,   45,   78,   45, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Renderer[] = {
    "Renderer\0log(Logtype,QString)\0"
    "_type,_message\0\0log(QString)\0_message\0"
    "version()\0QString\0initializePlugin()\0"
    "render(ACG::GLState*,Viewer::ViewerProperties&)\0"
    "_glState,_properties\0rendererName()\0"
    "supportedDrawModes(ACG::SceneGraph::DrawModes::DrawMode&)\0"
    "_mode\0checkOpenGL()\0"
};

void Renderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Renderer *_t = static_cast<Renderer *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: _t->initializePlugin(); break;
        case 4: _t->render((*reinterpret_cast< ACG::GLState*(*)>(_a[1])),(*reinterpret_cast< Viewer::ViewerProperties(*)>(_a[2]))); break;
        case 5: { QString _r = _t->rendererName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: _t->supportedDrawModes((*reinterpret_cast< ACG::SceneGraph::DrawModes::DrawMode(*)>(_a[1]))); break;
        case 7: { QString _r = _t->checkOpenGL();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Renderer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Renderer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Renderer,
      qt_meta_data_Renderer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Renderer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Renderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Renderer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Renderer))
        return static_cast<void*>(const_cast< Renderer*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< Renderer*>(this));
    if (!strcmp(_clname, "RenderInterface"))
        return static_cast< RenderInterface*>(const_cast< Renderer*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< Renderer*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< Renderer*>(this));
    if (!strcmp(_clname, "OpenFlipper.RenderInterface/1.0"))
        return static_cast< RenderInterface*>(const_cast< Renderer*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< Renderer*>(this));
    return QObject::qt_metacast(_clname);
}

int Renderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Renderer::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Renderer::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

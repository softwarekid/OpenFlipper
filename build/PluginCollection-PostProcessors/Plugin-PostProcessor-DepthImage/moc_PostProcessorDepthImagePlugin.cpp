/****************************************************************************
** Meta object code from reading C++ file 'PostProcessorDepthImagePlugin.hh'
**
** Created: Sat May 18 03:02:11 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-PostProcessors/Plugin-PostProcessor-DepthImage/PostProcessorDepthImagePlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PostProcessorDepthImagePlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PostProcessorDepthImagePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   40,   41,   40, 0x0a,
      49,   96,   40,   40, 0x08,
     105,   96,   40,   40, 0x08,
     132,   40,   41,   40, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PostProcessorDepthImagePlugin[] = {
    "PostProcessorDepthImagePlugin\0version()\0"
    "\0QString\0updateDepthStencilTextureBuffer(ACG::GLState*)\0"
    "_glstate\0postProcess(ACG::GLState*)\0"
    "postProcessorName()\0"
};

void PostProcessorDepthImagePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PostProcessorDepthImagePlugin *_t = static_cast<PostProcessorDepthImagePlugin *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: _t->updateDepthStencilTextureBuffer((*reinterpret_cast< ACG::GLState*(*)>(_a[1]))); break;
        case 2: _t->postProcess((*reinterpret_cast< ACG::GLState*(*)>(_a[1]))); break;
        case 3: { QString _r = _t->postProcessorName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PostProcessorDepthImagePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PostProcessorDepthImagePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PostProcessorDepthImagePlugin,
      qt_meta_data_PostProcessorDepthImagePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PostProcessorDepthImagePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PostProcessorDepthImagePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PostProcessorDepthImagePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PostProcessorDepthImagePlugin))
        return static_cast<void*>(const_cast< PostProcessorDepthImagePlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PostProcessorDepthImagePlugin*>(this));
    if (!strcmp(_clname, "PostProcessorInterface"))
        return static_cast< PostProcessorInterface*>(const_cast< PostProcessorDepthImagePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PostProcessorDepthImagePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PostProcessorInterface/1.0"))
        return static_cast< PostProcessorInterface*>(const_cast< PostProcessorDepthImagePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PostProcessorDepthImagePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

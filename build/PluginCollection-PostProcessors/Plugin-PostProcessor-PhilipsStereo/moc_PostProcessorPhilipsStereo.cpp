/****************************************************************************
** Meta object code from reading C++ file 'PostProcessorPhilipsStereo.hh'
**
** Created: Sat May 18 03:02:13 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/PostProcessorPhilipsStereo.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PostProcessorPhilipsStereo.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PostProcessorPhilipsStereoPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   46,   46,   46, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   46,   57,   46, 0x0a,
      65,   46,   57,   46, 0x0a,
      85,   46,  101,   46, 0x08,
     110,  137,   46,   46, 0x08,
     146,   46,   46,   46, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PostProcessorPhilipsStereoPlugin[] = {
    "PostProcessorPhilipsStereoPlugin\0"
    "updateView()\0\0version()\0QString\0"
    "postProcessorName()\0optionsAction()\0"
    "QAction*\0postProcess(ACG::GLState*)\0"
    "_glstate\0slotShowOptionsMenu()\0"
};

void PostProcessorPhilipsStereoPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PostProcessorPhilipsStereoPlugin *_t = static_cast<PostProcessorPhilipsStereoPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->postProcessorName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QAction* _r = _t->optionsAction();
            if (_a[0]) *reinterpret_cast< QAction**>(_a[0]) = _r; }  break;
        case 4: _t->postProcess((*reinterpret_cast< ACG::GLState*(*)>(_a[1]))); break;
        case 5: _t->slotShowOptionsMenu(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PostProcessorPhilipsStereoPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PostProcessorPhilipsStereoPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PostProcessorPhilipsStereoPlugin,
      qt_meta_data_PostProcessorPhilipsStereoPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PostProcessorPhilipsStereoPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PostProcessorPhilipsStereoPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PostProcessorPhilipsStereoPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PostProcessorPhilipsStereoPlugin))
        return static_cast<void*>(const_cast< PostProcessorPhilipsStereoPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PostProcessorPhilipsStereoPlugin*>(this));
    if (!strcmp(_clname, "PostProcessorInterface"))
        return static_cast< PostProcessorInterface*>(const_cast< PostProcessorPhilipsStereoPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PostProcessorPhilipsStereoPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.PostProcessorInterface/1.0"))
        return static_cast< PostProcessorInterface*>(const_cast< PostProcessorPhilipsStereoPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PostProcessorPhilipsStereoPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PostProcessorPhilipsStereoPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

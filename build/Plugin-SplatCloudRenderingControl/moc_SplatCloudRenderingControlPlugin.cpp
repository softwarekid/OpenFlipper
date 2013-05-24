/****************************************************************************
** Meta object code from reading C++ file 'SplatCloudRenderingControlPlugin.hh'
**
** Created: Sat May 18 02:59:12 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-SplatCloudRenderingControl/SplatCloudRenderingControlPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SplatCloudRenderingControlPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplatCloudRenderingControlPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   63,   79,   79, 0x05,
      80,  116,   79,   79, 0x05,
     136,  190,   79,   79, 0x05,
     216,  261,   79,   79, 0x05,
     280,  324,   79,   79, 0x05,
     344,  392,   79,   79, 0x05,
     416,  452,   79,   79, 0x05,
     468,  481,   79,   79, 0x05,
     490,  511,   79,   79, 0x05,

 // slots: signature, parameters, type, tag, flags
     526,   79,   79,   79, 0x08,
     545,  567,   79,   79, 0x08,
     577,  567,   79,   79, 0x08,
     604,   79,   79,   79, 0x08,
     644,   79,   79,   79, 0x08,
     682,   79,   79,   79, 0x08,
     721,   79,   79,   79, 0x08,
     763,   79,   79,   79, 0x08,
     811,   79,   79,   79, 0x08,
     860,   79,   79,   79, 0x08,
     900,   79,   79,   79, 0x08,
     938,   79,   79,   79, 0x08,
     972,   79,   79,   79, 0x08,
    1008,   79,   79,   79, 0x08,
    1050,   79,   79,   79, 0x08,
    1089,   79,   79,   79, 0x08,
    1126,   79,   79,   79, 0x08,
    1177,   79,   79,   79, 0x08,
    1229,   79,   79,   79, 0x08,
    1282,   79,   79,   79, 0x08,
    1338,   79, 1348,   79, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SplatCloudRenderingControlPlugin[] = {
    "SplatCloudRenderingControlPlugin\0"
    "updatedObject(int,UpdateType)\0"
    "_objectId,_type\0\0addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0"
    "addContextMenuItem(QAction*,DataType,ContextMenuType)\0"
    "_action,_objectType,_type\0"
    "defineViewModeToolboxes(QString,QStringList)\0"
    "_mode,_usedWidgets\0"
    "defineViewModeToolbars(QString,QStringList)\0"
    "_mode,_usedToolbars\0"
    "defineViewModeContextMenus(QString,QStringList)\0"
    "_mode,_usedContextMenus\0"
    "defineViewModeIcon(QString,QString)\0"
    "_mode,_iconName\0log(QString)\0_message\0"
    "log(Logtype,QString)\0_type,_message\0"
    "initializePlugin()\0addedEmptyObject(int)\0"
    "_objectId\0slotUpdateContextMenu(int)\0"
    "slotToolboxPointsizeScaleValueChanged()\0"
    "slotToolboxDefaultColorValueChanged()\0"
    "slotToolboxDefaultNormalValueChanged()\0"
    "slotToolboxDefaultPointsizeValueChanged()\0"
    "slotToolboxEnableBackfaceCullingButtonClicked()\0"
    "slotToolboxDisableBackfaceCullingButtonClicked()\0"
    "slotToolboxReloadShadersButtonClicked()\0"
    "slotToolboxRebuildVBOsButtonClicked()\0"
    "slotContextScaleActionTriggered()\0"
    "slotContextCullingActionTriggered()\0"
    "slotContextReloadShadersActionTriggered()\0"
    "slotContextRebuildVBOActionTriggered()\0"
    "slotContextDefaultsActionTriggered()\0"
    "slotContextScaleWidgetPointsizeScaleValueChanged()\0"
    "slotContextDefaultsWidgetDefaultColorValueChanged()\0"
    "slotContextDefaultsWidgetDefaultNormalValueChanged()\0"
    "slotContextDefaultsWidgetDefaultPointsizeValueChanged()\0"
    "version()\0QString\0"
};

void SplatCloudRenderingControlPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SplatCloudRenderingControlPlugin *_t = static_cast<SplatCloudRenderingControlPlugin *>(_o);
        switch (_id) {
        case 0: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 1: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 2: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< ContextMenuType(*)>(_a[3]))); break;
        case 3: _t->defineViewModeToolboxes((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 4: _t->defineViewModeToolbars((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 5: _t->defineViewModeContextMenus((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 6: _t->defineViewModeIcon((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->initializePlugin(); break;
        case 10: _t->addedEmptyObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotUpdateContextMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slotToolboxPointsizeScaleValueChanged(); break;
        case 13: _t->slotToolboxDefaultColorValueChanged(); break;
        case 14: _t->slotToolboxDefaultNormalValueChanged(); break;
        case 15: _t->slotToolboxDefaultPointsizeValueChanged(); break;
        case 16: _t->slotToolboxEnableBackfaceCullingButtonClicked(); break;
        case 17: _t->slotToolboxDisableBackfaceCullingButtonClicked(); break;
        case 18: _t->slotToolboxReloadShadersButtonClicked(); break;
        case 19: _t->slotToolboxRebuildVBOsButtonClicked(); break;
        case 20: _t->slotContextScaleActionTriggered(); break;
        case 21: _t->slotContextCullingActionTriggered(); break;
        case 22: _t->slotContextReloadShadersActionTriggered(); break;
        case 23: _t->slotContextRebuildVBOActionTriggered(); break;
        case 24: _t->slotContextDefaultsActionTriggered(); break;
        case 25: _t->slotContextScaleWidgetPointsizeScaleValueChanged(); break;
        case 26: _t->slotContextDefaultsWidgetDefaultColorValueChanged(); break;
        case 27: _t->slotContextDefaultsWidgetDefaultNormalValueChanged(); break;
        case 28: _t->slotContextDefaultsWidgetDefaultPointsizeValueChanged(); break;
        case 29: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SplatCloudRenderingControlPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SplatCloudRenderingControlPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SplatCloudRenderingControlPlugin,
      qt_meta_data_SplatCloudRenderingControlPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplatCloudRenderingControlPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplatCloudRenderingControlPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplatCloudRenderingControlPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplatCloudRenderingControlPlugin))
        return static_cast<void*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "ViewModeInterface"))
        return static_cast< ViewModeInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ViewModeInterface/1.0"))
        return static_cast< ViewModeInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< SplatCloudRenderingControlPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int SplatCloudRenderingControlPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void SplatCloudRenderingControlPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SplatCloudRenderingControlPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SplatCloudRenderingControlPlugin::addContextMenuItem(QAction * _t1, DataType _t2, ContextMenuType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SplatCloudRenderingControlPlugin::defineViewModeToolboxes(QString _t1, QStringList _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SplatCloudRenderingControlPlugin::defineViewModeToolbars(QString _t1, QStringList _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SplatCloudRenderingControlPlugin::defineViewModeContextMenus(QString _t1, QStringList _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SplatCloudRenderingControlPlugin::defineViewModeIcon(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SplatCloudRenderingControlPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SplatCloudRenderingControlPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE

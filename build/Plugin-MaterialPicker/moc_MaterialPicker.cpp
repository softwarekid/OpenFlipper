/****************************************************************************
** Meta object code from reading C++ file 'MaterialPicker.hh'
**
** Created: Sat May 18 02:56:27 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-MaterialPicker/MaterialPicker.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MaterialPicker.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaterialPicker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   40,   46,   46, 0x05,
      47,   46,   46,   46, 0x05,
      60,   96,   46,   46, 0x05,
     116,  168,   46,   46, 0x05,
     207,  254,   46,   46, 0x25,

 // slots: signature, parameters, type, tag, flags
     283,  312,   46,   46, 0x0a,
     319,   40,   46,   46, 0x0a,
     352,  312,   46,   46, 0x0a,
     377,   46,   46,   46, 0x08,
     396,   46,   46,   46, 0x08,
     417,   46,   46,   46, 0x08,
     440,   46,   46,   46, 0x08,
     463,   46,   46,   46, 0x08,
     487,  514,   46,   46, 0x08,
     520,   46,   46,   46, 0x08,
     538,  595,   46,   46, 0x08,
     609,  514,   46,   46, 0x08,
     639,  676,  687,   46, 0x08,
     695,   46,   46,   46, 0x08,
     707,  514,   46,   46, 0x08,
     736,  762,   46,   46, 0x08,
     769,  787,   46,   46, 0x08,
     792,   46,   46,   46, 0x08,
     817,  843,   46,   46, 0x08,
     849,   46,   46,   46, 0x08,
     871,   46,  687,   46, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MaterialPicker[] = {
    "MaterialPicker\0addPickMode(std::string)\0"
    "_mode\0\0updateView()\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0"
    "registerKey(int,Qt::KeyboardModifiers,QString,bool)\0"
    "_key,_modifiers,_description,_multiUse\0"
    "registerKey(int,Qt::KeyboardModifiers,QString)\0"
    "_key,_modifiers,_description\0"
    "slotMouseEvent(QMouseEvent*)\0_event\0"
    "slotPickModeChanged(std::string)\0"
    "slotKeyEvent(QKeyEvent*)\0initializePlugin()\0"
    "pluginsInitialized()\0slotPickMaterialMode()\0"
    "slotFillMaterialMode()\0slotRemoveCurrentItem()\0"
    "editMode(QListWidgetItem*)\0_item\0"
    "editModeCurrent()\0"
    "saveNewName(QWidget*,QAbstractItemDelegate::EndEditHint)\0"
    "_editor,_hint\0saveNewName(QListWidgetItem*)\0"
    "materialString(MaterialInfo,QString)\0"
    "_mat,_name\0QString\0clearList()\0"
    "removeItem(QListWidgetItem*)\0"
    "createContextMenu(QPoint)\0_point\0"
    "changeHotKey(int)\0_key\0slotMaterialProperties()\0"
    "slotEnableListWidget(int)\0_save\0"
    "slotMaterialChanged()\0version()\0"
};

void MaterialPicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaterialPicker *_t = static_cast<MaterialPicker *>(_o);
        switch (_id) {
        case 0: _t->addPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->updateView(); break;
        case 2: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 3: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 4: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->slotPickModeChanged((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 7: _t->slotKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 8: _t->initializePlugin(); break;
        case 9: _t->pluginsInitialized(); break;
        case 10: _t->slotPickMaterialMode(); break;
        case 11: _t->slotFillMaterialMode(); break;
        case 12: _t->slotRemoveCurrentItem(); break;
        case 13: _t->editMode((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->editModeCurrent(); break;
        case 15: _t->saveNewName((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QAbstractItemDelegate::EndEditHint(*)>(_a[2]))); break;
        case 16: _t->saveNewName((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 17: { QString _r = _t->materialString((*reinterpret_cast< const MaterialInfo(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 18: _t->clearList(); break;
        case 19: _t->removeItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 20: _t->createContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 21: _t->changeHotKey((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 22: _t->slotMaterialProperties(); break;
        case 23: _t->slotEnableListWidget((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->slotMaterialChanged(); break;
        case 25: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaterialPicker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaterialPicker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MaterialPicker,
      qt_meta_data_MaterialPicker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaterialPicker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaterialPicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaterialPicker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaterialPicker))
        return static_cast<void*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "MouseInterface"))
        return static_cast< MouseInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "PickingInterface"))
        return static_cast< PickingInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "OpenFlipper.MouseInterface/1.0"))
        return static_cast< MouseInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "OpenFlipper.PickingInterface/1.1"))
        return static_cast< PickingInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< MaterialPicker*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< MaterialPicker*>(this));
    return QObject::qt_metacast(_clname);
}

int MaterialPicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MaterialPicker::addPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MaterialPicker::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MaterialPicker::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MaterialPicker::registerKey(int _t1, Qt::KeyboardModifiers _t2, QString _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'OVMPropertyModel.hh'
**
** Created: Sat May 18 02:57:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/OpenVolumeMesh/OVMPropertyModel.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OVMPropertyModel.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OVMPropertyModelSubclass[] = {

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
      25,   39,   39,   39, 0x0a,
      40,   39,   39,   39, 0x0a,
      59,   39,   39,   39, 0x0a,
      78,   39,   39,   39, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OVMPropertyModelSubclass[] = {
    "OVMPropertyModelSubclass\0slotCombine()\0"
    "\0slotSaveProperty()\0slotLoadProperty()\0"
    "slotPickProperty()\0"
};

void OVMPropertyModelSubclass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OVMPropertyModelSubclass *_t = static_cast<OVMPropertyModelSubclass *>(_o);
        switch (_id) {
        case 0: _t->slotCombine(); break;
        case 1: _t->slotSaveProperty(); break;
        case 2: _t->slotLoadProperty(); break;
        case 3: _t->slotPickProperty(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OVMPropertyModelSubclass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OVMPropertyModelSubclass::staticMetaObject = {
    { &PropertyModel::staticMetaObject, qt_meta_stringdata_OVMPropertyModelSubclass,
      qt_meta_data_OVMPropertyModelSubclass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OVMPropertyModelSubclass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OVMPropertyModelSubclass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OVMPropertyModelSubclass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OVMPropertyModelSubclass))
        return static_cast<void*>(const_cast< OVMPropertyModelSubclass*>(this));
    return PropertyModel::qt_metacast(_clname);
}

int OVMPropertyModelSubclass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PropertyModel::qt_metacall(_c, _id, _a);
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

/****************************************************************************
** Meta object code from reading C++ file 'OMPropertyModel.hh'
**
** Created: Sat May 18 02:57:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/OpenMesh/OMPropertyModel.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OMPropertyModel.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OMPropertyModelSubclass[] = {

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
      24,   38,   38,   38, 0x0a,
      39,   38,   38,   38, 0x0a,
      58,   38,   38,   38, 0x0a,
      77,   38,   38,   38, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OMPropertyModelSubclass[] = {
    "OMPropertyModelSubclass\0slotCombine()\0"
    "\0slotSaveProperty()\0slotLoadProperty()\0"
    "slotPickProperty()\0"
};

void OMPropertyModelSubclass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OMPropertyModelSubclass *_t = static_cast<OMPropertyModelSubclass *>(_o);
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

const QMetaObjectExtraData OMPropertyModelSubclass::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OMPropertyModelSubclass::staticMetaObject = {
    { &PropertyModel::staticMetaObject, qt_meta_stringdata_OMPropertyModelSubclass,
      qt_meta_data_OMPropertyModelSubclass, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OMPropertyModelSubclass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OMPropertyModelSubclass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OMPropertyModelSubclass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OMPropertyModelSubclass))
        return static_cast<void*>(const_cast< OMPropertyModelSubclass*>(this));
    return PropertyModel::qt_metacast(_clname);
}

int OMPropertyModelSubclass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

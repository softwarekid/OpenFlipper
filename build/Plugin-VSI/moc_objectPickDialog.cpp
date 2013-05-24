/****************************************************************************
** Meta object code from reading C++ file 'objectPickDialog.hh'
**
** Created: Sat May 18 02:59:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/types/objectId/objectPickDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'objectPickDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__ObjectPickDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   45,   52,   52, 0x08,
      53,   92,   52,   52, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VSI__ObjectPickDialog[] = {
    "VSI::ObjectPickDialog\0activated(QModelIndex)\0"
    "_index\0\0slotMouseEventClick(QMouseEvent*,bool)\0"
    "_event,_double\0"
};

void VSI::ObjectPickDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ObjectPickDialog *_t = static_cast<ObjectPickDialog *>(_o);
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->slotMouseEventClick((*reinterpret_cast< QMouseEvent*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VSI::ObjectPickDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::ObjectPickDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VSI__ObjectPickDialog,
      qt_meta_data_VSI__ObjectPickDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::ObjectPickDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::ObjectPickDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::ObjectPickDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__ObjectPickDialog))
        return static_cast<void*>(const_cast< ObjectPickDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VSI::ObjectPickDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

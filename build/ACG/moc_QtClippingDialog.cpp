/****************************************************************************
** Meta object code from reading C++ file 'QtClippingDialog.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtClippingDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtClippingDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtClippingDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   79,   85,   85, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,   85,   85,   85, 0x08,
      98,  115,   85,   85, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtClippingDialog[] = {
    "ACG::QtWidgets::QtClippingDialog\0"
    "signalNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "_node\0\0set_plane()\0sweep_plane(int)\0"
    "_i\0"
};

void ACG::QtWidgets::QtClippingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtClippingDialog *_t = static_cast<QtClippingDialog *>(_o);
        switch (_id) {
        case 0: _t->signalNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 1: _t->set_plane(); break;
        case 2: _t->sweep_plane((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtClippingDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtClippingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtClippingDialog,
      qt_meta_data_ACG__QtWidgets__QtClippingDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtClippingDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtClippingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtClippingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtClippingDialog))
        return static_cast<void*>(const_cast< QtClippingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ACG::QtWidgets::QtClippingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ACG::QtWidgets::QtClippingDialog::signalNodeChanged(ACG::SceneGraph::BaseNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

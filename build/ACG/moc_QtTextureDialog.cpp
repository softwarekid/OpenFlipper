/****************************************************************************
** Meta object code from reading C++ file 'QtTextureDialog.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtTextureDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtTextureDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtTextureDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   78,   84,   84, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,  108,   84,   84, 0x08,
     111,   84,   84,   84, 0x08,
     126,   84,   84,   84, 0x08,
     140,   84,   84,   84, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtTextureDialog[] = {
    "ACG::QtWidgets::QtTextureDialog\0"
    "signalNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "_node\0\0changeMipmapping(bool)\0_b\0"
    "applyChanges()\0undoChanges()\0reject()\0"
};

void ACG::QtWidgets::QtTextureDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtTextureDialog *_t = static_cast<QtTextureDialog *>(_o);
        switch (_id) {
        case 0: _t->signalNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 1: _t->changeMipmapping((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->applyChanges(); break;
        case 3: _t->undoChanges(); break;
        case 4: _t->reject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtTextureDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtTextureDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtTextureDialog,
      qt_meta_data_ACG__QtWidgets__QtTextureDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtTextureDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtTextureDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtTextureDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtTextureDialog))
        return static_cast<void*>(const_cast< QtTextureDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ACG::QtWidgets::QtTextureDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ACG::QtWidgets::QtTextureDialog::signalNodeChanged(ACG::SceneGraph::BaseNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

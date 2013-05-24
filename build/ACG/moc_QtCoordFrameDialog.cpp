/****************************************************************************
** Meta object code from reading C++ file 'QtCoordFrameDialog.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtCoordFrameDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtCoordFrameDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtCoordFrameDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   81,   87,   87, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,   87,   87,   87, 0x08,
     102,   87,   87,   87, 0x08,
     116,   87,   87,   87, 0x08,
     130,   87,   87,   87, 0x08,
     144,   87,   87,   87, 0x08,
     158,   87,   87,   87, 0x08,
     172,   87,   87,   87, 0x08,
     186,   87,   87,   87, 0x08,
     200,   87,   87,   87, 0x08,
     214,   87,   87,   87, 0x08,
     230,   87,   87,   87, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtCoordFrameDialog[] = {
    "ACG::QtWidgets::QtCoordFrameDialog\0"
    "signalNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "_node\0\0add_x_plane()\0add_y_plane()\0"
    "add_z_plane()\0del_x_plane()\0del_y_plane()\0"
    "del_z_plane()\0mod_x_plane()\0mod_y_plane()\0"
    "mod_z_plane()\0apply_changes()\0"
    "undo_changes()\0"
};

void ACG::QtWidgets::QtCoordFrameDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtCoordFrameDialog *_t = static_cast<QtCoordFrameDialog *>(_o);
        switch (_id) {
        case 0: _t->signalNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 1: _t->add_x_plane(); break;
        case 2: _t->add_y_plane(); break;
        case 3: _t->add_z_plane(); break;
        case 4: _t->del_x_plane(); break;
        case 5: _t->del_y_plane(); break;
        case 6: _t->del_z_plane(); break;
        case 7: _t->mod_x_plane(); break;
        case 8: _t->mod_y_plane(); break;
        case 9: _t->mod_z_plane(); break;
        case 10: _t->apply_changes(); break;
        case 11: _t->undo_changes(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtCoordFrameDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtCoordFrameDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtCoordFrameDialog,
      qt_meta_data_ACG__QtWidgets__QtCoordFrameDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtCoordFrameDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtCoordFrameDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtCoordFrameDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtCoordFrameDialog))
        return static_cast<void*>(const_cast< QtCoordFrameDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ACG::QtWidgets::QtCoordFrameDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ACG::QtWidgets::QtCoordFrameDialog::signalNodeChanged(ACG::SceneGraph::BaseNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'SnapshotDialog.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/snapshotDialog/SnapshotDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SnapshotDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SnapshotDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   42,   57,   57, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   57,   57,   57, 0x08,
      67,   57,   57,   57, 0x08,
      78,   57,   57,   57, 0x08,
     101,  123,   57,   57, 0x08,
     126,  149,   57,   57, 0x08,
     152,   57,   57,   57, 0x08,
     172,   57,   57,   57, 0x08,
     193,   57,   57,   57, 0x08,
     206,   57,   57,   57, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SnapshotDialog[] = {
    "SnapshotDialog\0resizeApplication(int,int)\0"
    "_width,_height\0\0slotOk()\0findFile()\0"
    "slotChangeResolution()\0snapWidthChanged(int)\0"
    "_w\0snapHeightChanged(int)\0_h\0"
    "keepAspectChanged()\0multisampleChanged()\0"
    "saveStates()\0loadStates()\0"
};

void SnapshotDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SnapshotDialog *_t = static_cast<SnapshotDialog *>(_o);
        switch (_id) {
        case 0: _t->resizeApplication((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slotOk(); break;
        case 2: _t->findFile(); break;
        case 3: _t->slotChangeResolution(); break;
        case 4: _t->snapWidthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->snapHeightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->keepAspectChanged(); break;
        case 7: _t->multisampleChanged(); break;
        case 8: _t->saveStates(); break;
        case 9: _t->loadStates(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SnapshotDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SnapshotDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SnapshotDialog,
      qt_meta_data_SnapshotDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SnapshotDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SnapshotDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SnapshotDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SnapshotDialog))
        return static_cast<void*>(const_cast< SnapshotDialog*>(this));
    if (!strcmp(_clname, "Ui::SnapshotDialog"))
        return static_cast< Ui::SnapshotDialog*>(const_cast< SnapshotDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SnapshotDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SnapshotDialog::resizeApplication(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

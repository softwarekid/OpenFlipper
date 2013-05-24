/****************************************************************************
** Meta object code from reading C++ file 'QtWheel.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtWheel.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtWheel.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtWheel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   47,   54,   54, 0x05,
      55,   47,   54,   54, 0x05,
      78,   54,   54,   54, 0x05,
      87,   54,   54,   54, 0x05,
      98,   54,   54,   54, 0x05,

 // slots: signature, parameters, type, tag, flags
     110,  149,   54,   54, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtWheel[] = {
    "ACG::QtWidgets::QtWheel\0angleChangedTo(double)\0"
    "_angle\0\0angleChangedBy(double)\0gearUp()\0"
    "gearDown()\0hideWheel()\0"
    "slotCustomContextMenuRequested(QPoint)\0"
    "pos\0"
};

void ACG::QtWidgets::QtWheel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtWheel *_t = static_cast<QtWheel *>(_o);
        switch (_id) {
        case 0: _t->angleChangedTo((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->angleChangedBy((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->gearUp(); break;
        case 3: _t->gearDown(); break;
        case 4: _t->hideWheel(); break;
        case 5: _t->slotCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtWheel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtWheel::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtWheel,
      qt_meta_data_ACG__QtWidgets__QtWheel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtWheel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtWheel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtWheel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtWheel))
        return static_cast<void*>(const_cast< QtWheel*>(this));
    return QFrame::qt_metacast(_clname);
}

int ACG::QtWidgets::QtWheel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void ACG::QtWidgets::QtWheel::angleChangedTo(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ACG::QtWidgets::QtWheel::angleChangedBy(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ACG::QtWidgets::QtWheel::gearUp()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ACG::QtWidgets::QtWheel::gearDown()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ACG::QtWidgets::QtWheel::hideWheel()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE

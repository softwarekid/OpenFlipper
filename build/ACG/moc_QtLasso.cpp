/****************************************************************************
** Meta object code from reading C++ file 'QtLasso.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtLasso.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtLasso.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtLasso[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   63,   63,   63, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   93,   63,   63, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtLasso[] = {
    "ACG::QtLasso\0"
    "signalLassoSelection(ACG::QtLasso::SelectionMode)\0"
    "\0slotMouseEvent(QMouseEvent*)\0_event\0"
};

void ACG::QtLasso::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtLasso *_t = static_cast<QtLasso *>(_o);
        switch (_id) {
        case 0: _t->signalLassoSelection((*reinterpret_cast< ACG::QtLasso::SelectionMode(*)>(_a[1]))); break;
        case 1: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtLasso::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtLasso::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ACG__QtLasso,
      qt_meta_data_ACG__QtLasso, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtLasso::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtLasso::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtLasso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtLasso))
        return static_cast<void*>(const_cast< QtLasso*>(this));
    return QObject::qt_metacast(_clname);
}

int ACG::QtLasso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ACG::QtLasso::signalLassoSelection(ACG::QtLasso::SelectionMode _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

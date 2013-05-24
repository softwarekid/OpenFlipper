/****************************************************************************
** Meta object code from reading C++ file 'Utils.hh'
**
** Created: Sat May 18 02:57:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/Utils.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Utils.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewNameMessageBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   32,   32,   32, 0x08,
      33,   32,   32,   32, 0x08,
      46,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewNameMessageBox[] = {
    "NewNameMessageBox\0slotReplace()\0\0"
    "slotRename()\0slotCancel()\0"
};

void NewNameMessageBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewNameMessageBox *_t = static_cast<NewNameMessageBox *>(_o);
        switch (_id) {
        case 0: _t->slotReplace(); break;
        case 1: _t->slotRename(); break;
        case 2: _t->slotCancel(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData NewNameMessageBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewNameMessageBox::staticMetaObject = {
    { &QMessageBox::staticMetaObject, qt_meta_stringdata_NewNameMessageBox,
      qt_meta_data_NewNameMessageBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewNameMessageBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewNameMessageBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewNameMessageBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewNameMessageBox))
        return static_cast<void*>(const_cast< NewNameMessageBox*>(this));
    return QMessageBox::qt_metacast(_clname);
}

int NewNameMessageBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMessageBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'HelperClasses.hh'
**
** Created: Sat May 18 03:02:38 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-Selection/Plugin-SelectionBase/HelperClasses.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HelperClasses.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ActionButton[] = {

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
      13,   30,   39,   39, 0x08,
      40,   39,   39,   39, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ActionButton[] = {
    "ActionButton\0setChecked(bool)\0_checked\0"
    "\0changeRegistered()\0"
};

void ActionButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ActionButton *_t = static_cast<ActionButton *>(_o);
        switch (_id) {
        case 0: _t->setChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->changeRegistered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ActionButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ActionButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_ActionButton,
      qt_meta_data_ActionButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ActionButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ActionButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ActionButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ActionButton))
        return static_cast<void*>(const_cast< ActionButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int ActionButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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

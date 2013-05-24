/****************************************************************************
** Meta object code from reading C++ file 'QtFlapBox.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtFlapBox.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtFlapBox.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtFlapBox[] = {

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
      26,   44,   44,   44, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   44,   44,   44, 0x08,
      61,   44,   44,   44, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtFlapBox[] = {
    "ACG::QtWidgets::QtFlapBox\0sizeHintChanged()\0"
    "\0buttonClicked()\0widgetDestroyed(QObject*)\0"
};

void ACG::QtWidgets::QtFlapBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtFlapBox *_t = static_cast<QtFlapBox *>(_o);
        switch (_id) {
        case 0: _t->sizeHintChanged(); break;
        case 1: _t->buttonClicked(); break;
        case 2: _t->widgetDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtFlapBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtFlapBox::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtFlapBox,
      qt_meta_data_ACG__QtWidgets__QtFlapBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtFlapBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtFlapBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtFlapBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtFlapBox))
        return static_cast<void*>(const_cast< QtFlapBox*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int ACG::QtWidgets::QtFlapBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
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
void ACG::QtWidgets::QtFlapBox::sizeHintChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

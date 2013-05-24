/****************************************************************************
** Meta object code from reading C++ file 'QtGraphicsButton.hh'
**
** Created: Sat May 18 02:51:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/glWidget/QtGraphicsButton.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtGraphicsButton.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtGraphicsButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   27,   27,   27, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QtGraphicsButton[] = {
    "QtGraphicsButton\0pressed()\0\0"
};

void QtGraphicsButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtGraphicsButton *_t = static_cast<QtGraphicsButton *>(_o);
        switch (_id) {
        case 0: _t->pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QtGraphicsButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtGraphicsButton::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtGraphicsButton,
      qt_meta_data_QtGraphicsButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtGraphicsButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtGraphicsButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtGraphicsButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtGraphicsButton))
        return static_cast<void*>(const_cast< QtGraphicsButton*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< QtGraphicsButton*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< QtGraphicsButton*>(this));
    return QObject::qt_metacast(_clname);
}

int QtGraphicsButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QtGraphicsButton::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

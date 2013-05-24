/****************************************************************************
** Meta object code from reading C++ file 'SideElement.hh'
**
** Created: Sat May 18 02:52:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/coreWidget/SideElement.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SideElement.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SideElement[] = {

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
      12,   32,   41,   41, 0x08,
      42,   41,   41,   41, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SideElement[] = {
    "SideElement\0detachPressed(bool)\0"
    "_checked\0\0dialogClosed()\0"
};

void SideElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SideElement *_t = static_cast<SideElement *>(_o);
        switch (_id) {
        case 0: _t->detachPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->dialogClosed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SideElement::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SideElement::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SideElement,
      qt_meta_data_SideElement, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SideElement::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SideElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SideElement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SideElement))
        return static_cast<void*>(const_cast< SideElement*>(this));
    return QWidget::qt_metacast(_clname);
}

int SideElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

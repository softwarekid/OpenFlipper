/****************************************************************************
** Meta object code from reading C++ file 'numWidget.hh'
**
** Created: Sat May 18 02:59:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/types/numWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__NumWidget[] = {

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
      15,   39,   46,   46, 0x08,
      47,   39,   46,   46, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VSI__NumWidget[] = {
    "VSI::NumWidget\0sliderValueChanged(int)\0"
    "_value\0\0spinValueChanged(double)\0"
};

void VSI::NumWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NumWidget *_t = static_cast<NumWidget *>(_o);
        switch (_id) {
        case 0: _t->sliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->spinValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VSI::NumWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::NumWidget::staticMetaObject = {
    { &TypeWidget::staticMetaObject, qt_meta_stringdata_VSI__NumWidget,
      qt_meta_data_VSI__NumWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::NumWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::NumWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::NumWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__NumWidget))
        return static_cast<void*>(const_cast< NumWidget*>(this));
    return TypeWidget::qt_metacast(_clname);
}

int VSI::NumWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TypeWidget::qt_metacall(_c, _id, _a);
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

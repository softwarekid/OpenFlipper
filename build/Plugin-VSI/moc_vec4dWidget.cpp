/****************************************************************************
** Meta object code from reading C++ file 'vec4dWidget.hh'
**
** Created: Sat May 18 02:59:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/types/vec4dWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vec4dWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__Vec4DWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   35,   35,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VSI__Vec4DWidget[] = {
    "VSI::Vec4DWidget\0editingFinished()\0\0"
};

void VSI::Vec4DWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Vec4DWidget *_t = static_cast<Vec4DWidget *>(_o);
        switch (_id) {
        case 0: _t->editingFinished(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VSI::Vec4DWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::Vec4DWidget::staticMetaObject = {
    { &TypeWidget::staticMetaObject, qt_meta_stringdata_VSI__Vec4DWidget,
      qt_meta_data_VSI__Vec4DWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::Vec4DWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::Vec4DWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::Vec4DWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__Vec4DWidget))
        return static_cast<void*>(const_cast< Vec4DWidget*>(this));
    return TypeWidget::qt_metacast(_clname);
}

int VSI::Vec4DWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TypeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

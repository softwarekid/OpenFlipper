/****************************************************************************
** Meta object code from reading C++ file 'VectorWidget.hh'
**
** Created: Sat May 18 02:57:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/Widgets/VectorWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VectorWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VectorWidget[] = {

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
      13,   27,   27,   27, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_VectorWidget[] = {
    "VectorWidget\0widgetShown()\0\0"
};

void VectorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VectorWidget *_t = static_cast<VectorWidget *>(_o);
        switch (_id) {
        case 0: _t->widgetShown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VectorWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VectorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VectorWidget,
      qt_meta_data_VectorWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VectorWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VectorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VectorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VectorWidget))
        return static_cast<void*>(const_cast< VectorWidget*>(this));
    if (!strcmp(_clname, "Ui::VectorWidget"))
        return static_cast< Ui::VectorWidget*>(const_cast< VectorWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int VectorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void VectorWidget::widgetShown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

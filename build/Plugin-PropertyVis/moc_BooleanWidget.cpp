/****************************************************************************
** Meta object code from reading C++ file 'BooleanWidget.hh'
**
** Created: Sat May 18 02:57:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/Widgets/BooleanWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BooleanWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BooleanWidget[] = {

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
      14,   28,   28,   28, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_BooleanWidget[] = {
    "BooleanWidget\0widgetShown()\0\0"
};

void BooleanWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BooleanWidget *_t = static_cast<BooleanWidget *>(_o);
        switch (_id) {
        case 0: _t->widgetShown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BooleanWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BooleanWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BooleanWidget,
      qt_meta_data_BooleanWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BooleanWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BooleanWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BooleanWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BooleanWidget))
        return static_cast<void*>(const_cast< BooleanWidget*>(this));
    if (!strcmp(_clname, "Ui::BooleanWidget"))
        return static_cast< Ui::BooleanWidget*>(const_cast< BooleanWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BooleanWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void BooleanWidget::widgetShown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
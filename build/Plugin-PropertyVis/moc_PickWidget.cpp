/****************************************************************************
** Meta object code from reading C++ file 'PickWidget.hh'
**
** Created: Sat May 18 02:57:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PropertyVis/Widgets/PickWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PickWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PickWidget[] = {

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
      11,   25,   25,   25, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PickWidget[] = {
    "PickWidget\0widgetShown()\0\0"
};

void PickWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PickWidget *_t = static_cast<PickWidget *>(_o);
        switch (_id) {
        case 0: _t->widgetShown(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PickWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PickWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PickWidget,
      qt_meta_data_PickWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PickWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PickWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PickWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PickWidget))
        return static_cast<void*>(const_cast< PickWidget*>(this));
    if (!strcmp(_clname, "Ui::PickWidget"))
        return static_cast< Ui::PickWidget*>(const_cast< PickWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PickWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PickWidget::widgetShown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

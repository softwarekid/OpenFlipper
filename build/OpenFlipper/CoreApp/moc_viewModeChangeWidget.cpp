/****************************************************************************
** Meta object code from reading C++ file 'viewModeChangeWidget.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/viewModeWidget/viewModeChangeWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewModeChangeWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_viewModeChangeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   77,  123,  123, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,  153,  123,  123, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_viewModeChangeWidget[] = {
    "viewModeChangeWidget\0"
    "changeView(QString,QStringList,QStringList,QStringList)\0"
    "_mode,_toolboxWidgets,_toolbars,_contextmenus\0"
    "\0slotModeClicked(QModelIndex)\0_id\0"
};

void viewModeChangeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        viewModeChangeWidget *_t = static_cast<viewModeChangeWidget *>(_o);
        switch (_id) {
        case 0: _t->changeView((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 1: _t->slotModeClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData viewModeChangeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject viewModeChangeWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_viewModeChangeWidget,
      qt_meta_data_viewModeChangeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &viewModeChangeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *viewModeChangeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *viewModeChangeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_viewModeChangeWidget))
        return static_cast<void*>(const_cast< viewModeChangeWidget*>(this));
    if (!strcmp(_clname, "Ui::ViewModeChangeDialog"))
        return static_cast< Ui::ViewModeChangeDialog*>(const_cast< viewModeChangeWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int viewModeChangeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void viewModeChangeWidget::changeView(QString _t1, QStringList _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

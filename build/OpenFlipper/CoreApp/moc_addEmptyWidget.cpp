/****************************************************************************
** Meta object code from reading C++ file 'addEmptyWidget.hh'
**
** Created: Sat May 18 02:52:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/addEmptyWidget/addEmptyWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addEmptyWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addEmptyWidget[] = {

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
      15,   37,   45,   45, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   45,   45,   45, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_addEmptyWidget[] = {
    "addEmptyWidget\0chosen(DataType,int&)\0"
    "type,id\0\0slotAddEmpty()\0"
};

void addEmptyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        addEmptyWidget *_t = static_cast<addEmptyWidget *>(_o);
        switch (_id) {
        case 0: _t->chosen((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slotAddEmpty(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData addEmptyWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject addEmptyWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addEmptyWidget,
      qt_meta_data_addEmptyWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &addEmptyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *addEmptyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *addEmptyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addEmptyWidget))
        return static_cast<void*>(const_cast< addEmptyWidget*>(this));
    if (!strcmp(_clname, "Ui::addEmpty"))
        return static_cast< Ui::addEmpty*>(const_cast< addEmptyWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int addEmptyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void addEmptyWidget::chosen(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

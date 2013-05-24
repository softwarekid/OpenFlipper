/****************************************************************************
** Meta object code from reading C++ file 'BlockingWidget.hh'
**
** Created: Sat May 18 02:52:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/processManagerWidget/BlockingWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BlockingWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BlockingWidget[] = {

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
      15,   40,   47,   47, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   47,   47,   47, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BlockingWidget[] = {
    "BlockingWidget\0cancelRequested(QString)\0"
    "_jobId\0\0cancelPressed()\0"
};

void BlockingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BlockingWidget *_t = static_cast<BlockingWidget *>(_o);
        switch (_id) {
        case 0: _t->cancelRequested((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cancelPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BlockingWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BlockingWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BlockingWidget,
      qt_meta_data_BlockingWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BlockingWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BlockingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BlockingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BlockingWidget))
        return static_cast<void*>(const_cast< BlockingWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BlockingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void BlockingWidget::cancelRequested(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'rendererObjectWidget.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/rendererWidget/rendererObjectWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rendererObjectWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RendererObjectWidget[] = {

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
      21,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RendererObjectWidget[] = {
    "RendererObjectWidget\0update()\0\0"
};

void RendererObjectWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RendererObjectWidget *_t = static_cast<RendererObjectWidget *>(_o);
        switch (_id) {
        case 0: _t->update(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RendererObjectWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RendererObjectWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RendererObjectWidget,
      qt_meta_data_RendererObjectWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RendererObjectWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RendererObjectWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RendererObjectWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RendererObjectWidget))
        return static_cast<void*>(const_cast< RendererObjectWidget*>(this));
    if (!strcmp(_clname, "Ui::RendererObjectWidget"))
        return static_cast< Ui::RendererObjectWidget*>(const_cast< RendererObjectWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int RendererObjectWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

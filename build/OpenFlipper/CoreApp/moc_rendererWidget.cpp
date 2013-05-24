/****************************************************************************
** Meta object code from reading C++ file 'rendererWidget.hh'
**
** Created: Sat May 18 02:52:53 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/rendererWidget/rendererWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rendererWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RendererDialog[] = {

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
      47,   46,   46,   46, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RendererDialog[] = {
    "RendererDialog\0slotContextMenu(QPoint)\0"
    "_point\0\0slotActivateRenderer()\0"
};

void RendererDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RendererDialog *_t = static_cast<RendererDialog *>(_o);
        switch (_id) {
        case 0: _t->slotContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->slotActivateRenderer(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RendererDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RendererDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RendererDialog,
      qt_meta_data_RendererDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RendererDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RendererDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RendererDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RendererDialog))
        return static_cast<void*>(const_cast< RendererDialog*>(this));
    if (!strcmp(_clname, "Ui::RendererWidget"))
        return static_cast< Ui::RendererWidget*>(const_cast< RendererDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RendererDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE

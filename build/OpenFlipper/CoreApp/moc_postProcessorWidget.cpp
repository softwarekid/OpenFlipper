/****************************************************************************
** Meta object code from reading C++ file 'postProcessorWidget.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/postProcessorWidget/postProcessorWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'postProcessorWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PostProcessorDialog[] = {

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
      20,   44,   51,   51, 0x08,
      52,   51,   51,   51, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PostProcessorDialog[] = {
    "PostProcessorDialog\0slotContextMenu(QPoint)\0"
    "_point\0\0slotActivatePostProcessor()\0"
};

void PostProcessorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PostProcessorDialog *_t = static_cast<PostProcessorDialog *>(_o);
        switch (_id) {
        case 0: _t->slotContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->slotActivatePostProcessor(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PostProcessorDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PostProcessorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PostProcessorDialog,
      qt_meta_data_PostProcessorDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PostProcessorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PostProcessorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PostProcessorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PostProcessorDialog))
        return static_cast<void*>(const_cast< PostProcessorDialog*>(this));
    if (!strcmp(_clname, "Ui::PostProcessorWidget"))
        return static_cast< Ui::PostProcessorWidget*>(const_cast< PostProcessorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PostProcessorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

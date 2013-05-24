/****************************************************************************
** Meta object code from reading C++ file 'LightWidget.hh'
**
** Created: Sat May 18 02:51:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ObjectTypes/Light/LightWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LightWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LightWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   33,   33,   33, 0x08,
      34,   33,   33,   33, 0x08,
      57,   33,   33,   33, 0x08,
      74,   33,   33,   33, 0x08,
      91,   33,   33,   33, 0x08,
     109,  132,   33,   33, 0x08,
     142,   33,   33,   33, 0x08,
     158,   33,   33,   33, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LightWidget[] = {
    "LightWidget\0directionalToggled()\0\0"
    "fixedPositionChanged()\0ambientChanged()\0"
    "diffuseChanged()\0specularChanged()\0"
    "brightnessChanged(int)\0_newValue\0"
    "radiusChanged()\0spotChanged()\0"
};

void LightWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LightWidget *_t = static_cast<LightWidget *>(_o);
        switch (_id) {
        case 0: _t->directionalToggled(); break;
        case 1: _t->fixedPositionChanged(); break;
        case 2: _t->ambientChanged(); break;
        case 3: _t->diffuseChanged(); break;
        case 4: _t->specularChanged(); break;
        case 5: _t->brightnessChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->radiusChanged(); break;
        case 7: _t->spotChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LightWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LightWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LightWidget,
      qt_meta_data_LightWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LightWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LightWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LightWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LightWidget))
        return static_cast<void*>(const_cast< LightWidget*>(this));
    if (!strcmp(_clname, "Ui::LightWidgetBase"))
        return static_cast< Ui::LightWidgetBase*>(const_cast< LightWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int LightWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'philipsStereoSettingsWidget.hh'
**
** Created: Sat May 18 03:02:14 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-PostProcessors/Plugin-PostProcessor-PhilipsStereo/widgets/philipsStereoSettingsWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'philipsStereoSettingsWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PhilipsStereoSettingsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   41,   41,   41, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   41,   41,   41, 0x08,
      57,   41,   41,   41, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PhilipsStereoSettingsWidget[] = {
    "PhilipsStereoSettingsWidget\0updateView()\0"
    "\0updateValues()\0closeWidget()\0"
};

void PhilipsStereoSettingsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PhilipsStereoSettingsWidget *_t = static_cast<PhilipsStereoSettingsWidget *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updateValues(); break;
        case 2: _t->closeWidget(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PhilipsStereoSettingsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PhilipsStereoSettingsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PhilipsStereoSettingsWidget,
      qt_meta_data_PhilipsStereoSettingsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PhilipsStereoSettingsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PhilipsStereoSettingsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PhilipsStereoSettingsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhilipsStereoSettingsWidget))
        return static_cast<void*>(const_cast< PhilipsStereoSettingsWidget*>(this));
    if (!strcmp(_clname, "Ui::PhilipsStereoSettingsWidget"))
        return static_cast< Ui::PhilipsStereoSettingsWidget*>(const_cast< PhilipsStereoSettingsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PhilipsStereoSettingsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PhilipsStereoSettingsWidget::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

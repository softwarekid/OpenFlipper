/****************************************************************************
** Meta object code from reading C++ file 'PluginDialog.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/PluginDialog/PluginDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PluginDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PluginDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   34,   40,   40, 0x05,
      41,   34,   40,   40, 0x05,
      64,   40,   40,   40, 0x05,
      77,  120,   40,   40, 0x05,

 // slots: signature, parameters, type, tag, flags
     161,  185,   40,   40, 0x08,
     192,   40,   40,   40, 0x08,
     209,   40,   40,   40, 0x08,
     227,   40,   40,   40, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PluginDialog[] = {
    "PluginDialog\0blockPlugin(QString)\0"
    "_name\0\0unBlockPlugin(QString)\0"
    "loadPlugin()\0loadPlugin(QString,bool,QString&,QObject*)\0"
    "_filename,_silent,_licenseErrors,_plugin\0"
    "slotContextMenu(QPoint)\0_point\0"
    "slotLoadPlugin()\0slotBlockPlugin()\0"
    "slotUnBlockPlugin()\0"
};

void PluginDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PluginDialog *_t = static_cast<PluginDialog *>(_o);
        switch (_id) {
        case 0: _t->blockPlugin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->unBlockPlugin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->loadPlugin(); break;
        case 3: _t->loadPlugin((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QObject*(*)>(_a[4]))); break;
        case 4: _t->slotContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->slotLoadPlugin(); break;
        case 6: _t->slotBlockPlugin(); break;
        case 7: _t->slotUnBlockPlugin(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PluginDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PluginDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PluginDialog,
      qt_meta_data_PluginDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PluginDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PluginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PluginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginDialog))
        return static_cast<void*>(const_cast< PluginDialog*>(this));
    if (!strcmp(_clname, "Ui::PluginDialog"))
        return static_cast< Ui::PluginDialog*>(const_cast< PluginDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PluginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void PluginDialog::blockPlugin(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PluginDialog::unBlockPlugin(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PluginDialog::loadPlugin()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void PluginDialog::loadPlugin(const QString & _t1, bool _t2, QString & _t3, QObject * _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

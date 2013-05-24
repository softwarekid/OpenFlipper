/****************************************************************************
** Meta object code from reading C++ file 'PrintPlugin.hh'
**
** Created: Sat May 18 02:57:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Print/PrintPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PrintPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrintPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   47,   61,   61, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   61,   61,   61, 0x08,
      83,  108,   61,   61, 0x08,
     115,   61,   61,   61, 0x0a,
     127,   61,  137,   61, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PrintPlugin[] = {
    "PrintPlugin\0addMenubarAction(QAction*,QString)\0"
    "_action,_type\0\0pluginsInitialized()\0"
    "slotKeyEvent(QKeyEvent*)\0_event\0"
    "printView()\0version()\0QString\0"
};

void PrintPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PrintPlugin *_t = static_cast<PrintPlugin *>(_o);
        switch (_id) {
        case 0: _t->addMenubarAction((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->pluginsInitialized(); break;
        case 2: _t->slotKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->printView(); break;
        case 4: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PrintPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PrintPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PrintPlugin,
      qt_meta_data_PrintPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrintPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrintPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrintPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrintPlugin))
        return static_cast<void*>(const_cast< PrintPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PrintPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< PrintPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< PrintPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PrintPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< PrintPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< PrintPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PrintPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PrintPlugin::addMenubarAction(QAction * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

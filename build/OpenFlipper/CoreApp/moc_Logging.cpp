/****************************************************************************
** Meta object code from reading C++ file 'Logging.hh'
**
** Created: Sat May 18 02:52:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/Logging/Logging.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Logging.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PluginLogger[] = {

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
      13,   34,   36,   36, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   62,   36,   36, 0x08,
      77,   94,   36,   36, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PluginLogger[] = {
    "PluginLogger\0log(Logtype,QString)\0,\0"
    "\0slotLog(Logtype,QString)\0_type,_message\0"
    "slotLog(QString)\0_message\0"
};

void PluginLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PluginLogger *_t = static_cast<PluginLogger *>(_o);
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->slotLog((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->slotLog((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PluginLogger::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PluginLogger::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PluginLogger,
      qt_meta_data_PluginLogger, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PluginLogger::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PluginLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PluginLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginLogger))
        return static_cast<void*>(const_cast< PluginLogger*>(this));
    return QObject::qt_metacast(_clname);
}

int PluginLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void PluginLogger::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

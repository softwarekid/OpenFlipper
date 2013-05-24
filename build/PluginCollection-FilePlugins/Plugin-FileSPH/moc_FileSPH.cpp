/****************************************************************************
** Meta object code from reading C++ file 'FileSPH.hh'
**
** Created: Sat May 18 03:01:54 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-FilePlugins/Plugin-FileSPH/FileSPH.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileSPH.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileSPHPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   30,   34,   34, 0x05,
      35,   65,   34,   34, 0x05,
      75,  103,   34,   34, 0x05,
     123,  141,   34,   34, 0x05,
     155,  176,   34,   34, 0x05,
     191,  204,   34,   34, 0x05,
     213,  243,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
     253,   34,   34,   34, 0x08,
     269,   34,   34,   34, 0x08,
     286,   34,   34,   34, 0x08,
     305,  325,  335,   34, 0x0a,
     339,  141,  363,   34, 0x0a,
     368,   34,  378,   34, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileSPHPlugin[] = {
    "FileSPHPlugin\0openedFile(int)\0_id\0\0"
    "addEmptyObject(DataType,int&)\0_type,_id\0"
    "load(QString,DataType,int&)\0"
    "_filename,_type,_id\0save(int,QString)\0"
    "_id,_filename\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "fileOpened(int)\0noguiSupported()\0"
    "initializePlugin()\0loadObject(QString)\0"
    "_filename\0int\0saveObject(int,QString)\0"
    "bool\0version()\0QString\0"
};

void FileSPHPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileSPHPlugin *_t = static_cast<FileSPHPlugin *>(_o);
        switch (_id) {
        case 0: _t->openedFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->load((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->save((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 7: _t->fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->noguiSupported(); break;
        case 9: _t->initializePlugin(); break;
        case 10: { int _r = _t->loadObject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->saveObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileSPHPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileSPHPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileSPHPlugin,
      qt_meta_data_FileSPHPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileSPHPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileSPHPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileSPHPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileSPHPlugin))
        return static_cast<void*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "FileInterface"))
        return static_cast< FileInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.FileInterface/1.0"))
        return static_cast< FileInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< FileSPHPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< FileSPHPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int FileSPHPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void FileSPHPlugin::openedFile(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileSPHPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileSPHPlugin::load(QString _t1, DataType _t2, int & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileSPHPlugin::save(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileSPHPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FileSPHPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FileSPHPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

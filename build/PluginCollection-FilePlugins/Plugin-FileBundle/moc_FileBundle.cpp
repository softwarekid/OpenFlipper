/****************************************************************************
** Meta object code from reading C++ file 'FileBundle.hh'
**
** Created: Sat May 18 03:00:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-FilePlugins/Plugin-FileBundle/FileBundle.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileBundle.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileBundlePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   33,   43,   43, 0x05,
      44,   74,   43,   43, 0x05,
      90,   33,   43,   43, 0x05,
     108,  138,   43,   43, 0x05,
     154,  167,   43,   43, 0x05,
     176,  197,   43,   43, 0x05,

 // slots: signature, parameters, type, tag, flags
     212,   43,  222,   43, 0x0a,
     230,  250,  260,   43, 0x0a,
     264,  288,  308,   43, 0x0a,
     313,   43,   43,   43, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FileBundlePlugin[] = {
    "FileBundlePlugin\0openedFile(int)\0"
    "_objectId\0\0addEmptyObject(DataType,int&)\0"
    "_type,_objectId\0deleteObject(int)\0"
    "updatedObject(int,UpdateType)\0"
    "_objectId,_type\0log(QString)\0_message\0"
    "log(Logtype,QString)\0_type,_message\0"
    "version()\0QString\0loadObject(QString)\0"
    "_filename\0int\0saveObject(int,QString)\0"
    "_objectId,_filename\0bool\0noguiSupported()\0"
};

void FileBundlePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileBundlePlugin *_t = static_cast<FileBundlePlugin *>(_o);
        switch (_id) {
        case 0: _t->openedFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->loadObject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->saveObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->noguiSupported(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileBundlePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileBundlePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileBundlePlugin,
      qt_meta_data_FileBundlePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileBundlePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileBundlePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileBundlePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileBundlePlugin))
        return static_cast<void*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "FileInterface"))
        return static_cast< FileInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.FileInterface/1.0"))
        return static_cast< FileInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< FileBundlePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< FileBundlePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int FileBundlePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FileBundlePlugin::openedFile(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileBundlePlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileBundlePlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileBundlePlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileBundlePlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FileBundlePlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

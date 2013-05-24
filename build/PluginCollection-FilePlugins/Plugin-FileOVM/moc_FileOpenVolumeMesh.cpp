/****************************************************************************
** Meta object code from reading C++ file 'FileOpenVolumeMesh.hh'
**
** Created: Sat May 18 03:01:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-FilePlugins/Plugin-FileOVM/FileOpenVolumeMesh.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileOpenVolumeMesh.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileOpenVolumeMeshPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   41,   45,   45, 0x05,
      46,   76,   45,   45, 0x05,
      86,  114,   45,   45, 0x05,
     134,  152,   45,   45, 0x05,
     166,  187,   45,   45, 0x05,
     202,  215,   45,   45, 0x05,
     224,   41,   45,   45, 0x05,
     246,   45,   45,   45, 0x05,
     259,  289,   45,   45, 0x05,
     299,  351,   45,   45, 0x05,
     390,  437,   45,   45, 0x25,

 // slots: signature, parameters, type, tag, flags
     466,   45,   45,   45, 0x08,
     482,  512,   45,   45, 0x08,
     521,  512,   45,   45, 0x08,
     547,   45,   45,   45, 0x08,
     566,  586,  596,   45, 0x0a,
     600,  152,  624,   45, 0x0a,
     629,   45,  639,   45, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileOpenVolumeMeshPlugin[] = {
    "FileOpenVolumeMeshPlugin\0openedFile(int)\0"
    "_id\0\0addEmptyObject(DataType,int&)\0"
    "_type,_id\0load(QString,DataType,int&)\0"
    "_filename,_type,_id\0save(int,QString)\0"
    "_id,_filename\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "emptyObjectAdded(int)\0updateView()\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "registerKey(int,Qt::KeyboardModifiers,QString,bool)\0"
    "_key,_modifiers,_description,_multiUse\0"
    "registerKey(int,Qt::KeyboardModifiers,QString)\0"
    "_key,_modifiers,_description\0"
    "fileOpened(int)\0loadIniFileLast(INIFile&,int)\0"
    "_ini,_id\0saveIniFile(INIFile&,int)\0"
    "initializePlugin()\0loadObject(QString)\0"
    "_filename\0int\0saveObject(int,QString)\0"
    "bool\0version()\0QString\0"
};

void FileOpenVolumeMeshPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileOpenVolumeMeshPlugin *_t = static_cast<FileOpenVolumeMeshPlugin *>(_o);
        switch (_id) {
        case 0: _t->openedFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->load((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->save((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->emptyObjectAdded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updateView(); break;
        case 8: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 9: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 10: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 11: _t->fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->loadIniFileLast((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->saveIniFile((*reinterpret_cast< INIFile(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->initializePlugin(); break;
        case 15: { int _r = _t->loadObject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->saveObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileOpenVolumeMeshPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileOpenVolumeMeshPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileOpenVolumeMeshPlugin,
      qt_meta_data_FileOpenVolumeMeshPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileOpenVolumeMeshPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileOpenVolumeMeshPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileOpenVolumeMeshPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileOpenVolumeMeshPlugin))
        return static_cast<void*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "FileInterface"))
        return static_cast< FileInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "INIInterface"))
        return static_cast< INIInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.FileInterface/1.0"))
        return static_cast< FileInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.INIInterface/1.2"))
        return static_cast< INIInterface*>(const_cast< FileOpenVolumeMeshPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int FileOpenVolumeMeshPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void FileOpenVolumeMeshPlugin::openedFile(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileOpenVolumeMeshPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileOpenVolumeMeshPlugin::load(QString _t1, DataType _t2, int & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileOpenVolumeMeshPlugin::save(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileOpenVolumeMeshPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FileOpenVolumeMeshPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FileOpenVolumeMeshPlugin::emptyObjectAdded(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FileOpenVolumeMeshPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void FileOpenVolumeMeshPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void FileOpenVolumeMeshPlugin::registerKey(int _t1, Qt::KeyboardModifiers _t2, QString _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE

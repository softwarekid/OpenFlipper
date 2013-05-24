/****************************************************************************
** Meta object code from reading C++ file 'FileOBJ.hh'
**
** Created: Sat May 18 03:00:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-FilePlugins/Plugin-FileOBJ/FileOBJ.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileOBJ.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileOBJPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      21,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   30,   34,   34, 0x05,
      35,   65,   34,   34, 0x05,
      75,  103,   34,   34, 0x05,
     123,  141,   34,   34, 0x05,
     155,  176,   34,   34, 0x05,
     191,  204,   34,   34, 0x05,
     213,   34,   34,   34, 0x05,
     226,   30,   34,   34, 0x05,
     244,  275,   34,   34, 0x05,
     293,  204,   34,   34, 0x25,
     320,  368,   34,   34, 0x05,
     376,  404,   34,   34, 0x05,
     424,  460,   34,   34, 0x05,
     483,  510,   34,   34, 0x05,
     527,  577,   34,   34, 0x05,
     622,  660,   34,   34, 0x05,
     663,  694,   34,   34, 0x05,
     711,  743,   34,   34, 0x05,
     745,  660,   34,   34, 0x05,
     775,  660,   34,   34, 0x05,
     816,  743,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
     855,   34,   34,   34, 0x08,
     871,   34,   34,   34, 0x08,
     888,   34,   34,   34, 0x08,
     907,   34,   34,   34, 0x08,
     925,   34,   34,   34, 0x08,
     943,  970,   34,   34, 0x08,
     979,  999, 1009,   34, 0x0a,
    1013, 1042, 1009,   34, 0x0a,
    1058,  141, 1082,   34, 0x0a,
    1087,   34, 1097,   34, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FileOBJPlugin[] = {
    "FileOBJPlugin\0openedFile(int)\0_id\0\0"
    "addEmptyObject(DataType,int&)\0_type,_id\0"
    "load(QString,DataType,int&)\0"
    "_filename,_type,_id\0save(int,QString)\0"
    "_id,_filename\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "updateView()\0deleteObject(int)\0"
    "showStatusMessage(QString,int)\0"
    "_message,_timeout\0showStatusMessage(QString)\0"
    "setStatus(ApplicationStatus::applicationStatus)\0"
    "_status\0pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0"
    "setTextureMode(QString,QString,int)\0"
    "_textureName,_mode,_id\0"
    "switchTexture(QString,int)\0_textureName,_id\0"
    "addMultiTexture(QString,QString,QString,int,int&)\0"
    "_textureGroup,_name,_filename,_id,_textureId\0"
    "textureFilename(int,QString,QString&)\0"
    ",,\0textureIndex(QString,int,int&)\0"
    "_name,_id,_index\0getCurrentTexture(int,QString&)\0"
    ",\0textureName(int,int,QString&)\0"
    "getSubTextures(int,QString,QStringList&)\0"
    "textureIndexPropertyName(int,QString&)\0"
    "fileOpened(int)\0noguiSupported()\0"
    "initializePlugin()\0slotLoadDefault()\0"
    "slotSaveDefault()\0slotHandleCheckBoxes(bool)\0"
    "_checked\0loadObject(QString)\0_filename\0"
    "int\0loadObject(QString,DataType)\0"
    "_filename,_type\0saveObject(int,QString)\0"
    "bool\0version()\0QString\0"
};

void FileOBJPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FileOBJPlugin *_t = static_cast<FileOBJPlugin *>(_o);
        switch (_id) {
        case 0: _t->openedFile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->load((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->save((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updateView(); break;
        case 7: _t->deleteObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->showStatusMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->showStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setStatus((*reinterpret_cast< ApplicationStatus::applicationStatus(*)>(_a[1]))); break;
        case 11: _t->pluginExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->setTextureMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->switchTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->addMultiTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 15: _t->textureFilename((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 16: _t->textureIndex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 17: _t->getCurrentTexture((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 18: _t->textureName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 19: _t->getSubTextures((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 20: _t->textureIndexPropertyName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: _t->fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->noguiSupported(); break;
        case 23: _t->initializePlugin(); break;
        case 24: _t->slotLoadDefault(); break;
        case 25: _t->slotSaveDefault(); break;
        case 26: _t->slotHandleCheckBoxes((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: { int _r = _t->loadObject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 28: { int _r = _t->loadObject((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: { bool _r = _t->saveObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FileOBJPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FileOBJPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileOBJPlugin,
      qt_meta_data_FileOBJPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FileOBJPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FileOBJPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FileOBJPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileOBJPlugin))
        return static_cast<void*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "FileInterface"))
        return static_cast< FileInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "ScriptInterface"))
        return static_cast< ScriptInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "StatusbarInterface"))
        return static_cast< StatusbarInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "TextureInterface"))
        return static_cast< TextureInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.FileInterface/1.0"))
        return static_cast< FileInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ScriptInterface/1.1"))
        return static_cast< ScriptInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.StatusbarInterface/1.0"))
        return static_cast< StatusbarInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< FileOBJPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TextureInterface/1.0"))
        return static_cast< TextureInterface*>(const_cast< FileOBJPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int FileOBJPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void FileOBJPlugin::openedFile(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileOBJPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileOBJPlugin::load(QString _t1, DataType _t2, int & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileOBJPlugin::save(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FileOBJPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FileOBJPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FileOBJPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void FileOBJPlugin::deleteObject(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void FileOBJPlugin::showStatusMessage(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 10
void FileOBJPlugin::setStatus(ApplicationStatus::applicationStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void FileOBJPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void FileOBJPlugin::setTextureMode(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void FileOBJPlugin::switchTexture(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void FileOBJPlugin::addMultiTexture(QString _t1, QString _t2, QString _t3, int _t4, int & _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void FileOBJPlugin::textureFilename(int _t1, QString _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void FileOBJPlugin::textureIndex(QString _t1, int _t2, int & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void FileOBJPlugin::getCurrentTexture(int _t1, QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void FileOBJPlugin::textureName(int _t1, int _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void FileOBJPlugin::getSubTextures(int _t1, QString _t2, QStringList & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void FileOBJPlugin::textureIndexPropertyName(int _t1, QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'TextureControl.hh'
**
** Created: Sat May 18 02:59:27 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-TextureControl/TextureControl.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextureControl.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextureControlPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   34,   34,   34, 0x05,
      35,   65,   34,   34, 0x05,
      83,  110,   34,   34, 0x05,
     112,  133,   34,   34, 0x05,
     148,  161,   34,   34, 0x05,
     170,  205,   34,   34, 0x05,
     219,  273,   34,   34, 0x05,

 // slots: signature, parameters, type, tag, flags
     299,   34,   34,   34, 0x08,
     320,   65,   34,   34, 0x08,
     354,  379,   34,   34, 0x08,
     389,   34,   34,   34, 0x08,
     413,  456,   34,   34, 0x08,
     494,  533,   34,   34, 0x08,
     567,  623,   34,   34, 0x08,
     668,  700,   34,   34, 0x08,
     725,  765,   34,   34, 0x08,
     788,  824,   34,   34, 0x08,
     843,  874,   34,   34, 0x08,
     891,  918,   34,   34, 0x08,
     931,  700,   34,   34, 0x08,
     962, 1006,   34,   34, 0x08,
    1030, 1070,   34,   34, 0x08,
    1090, 1006,   34,   34, 0x08,
    1131, 1070,   34,   34, 0x08,
    1168, 1203,   34,   34, 0x08,
    1227, 1270,   34,   34, 0x08,
    1288, 1322,   34,   34, 0x08,
    1353, 1395,   34,   34, 0x08,
    1429, 1465,   34,   34, 0x08,
    1482, 1527,   34,   34, 0x08,
    1562, 1578,   34,   34, 0x08,
    1582, 1578,   34,   34, 0x08,
    1604, 1628,   34,   34, 0x08,
    1638, 1628,   34,   34, 0x08,
    1656,  874,   34,   34, 0x08,
    1685, 1711,   34,   34, 0x08,
    1719,   34,   34,   34, 0x08,
    1746, 1792,   34,   34, 0x08,
    1818, 1869,   34,   34, 0x08,
    1889, 1916,   34,   34, 0x08,
    1926, 1711,   34,   34, 0x08,
    1959,   34, 1969,   34, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TextureControlPlugin[] = {
    "TextureControlPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0"
    "_identifier,_type\0updateTexture(QString,int)\0"
    ",\0log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "addMenubarAction(QAction*,QString)\0"
    "_action,_type\0"
    "addContextMenuItem(QAction*,DataType,ContextMenuType)\0"
    "_action,_objectType,_type\0"
    "pluginsInitialized()\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "slotDrawModeChanged(int)\0_viewerId\0"
    "slotUpdateAllTextures()\0"
    "slotTextureAdded(QString,QString,uint,int)\0"
    "_textureName,_filename,_dimension,_id\0"
    "slotTextureAdded(QString,QString,uint)\0"
    "_textureName,_filename,_dimension\0"
    "slotMultiTextureAdded(QString,QString,QString,int,int&)\0"
    "_textureGroup,_name,_filename,_id,_textureId\0"
    "slotTextureUpdated(QString,int)\0"
    "_textureName,_identifier\0"
    "slotSetTextureMode(QString,QString,int)\0"
    "_textureName,_mode,_id\0"
    "slotSetTextureMode(QString,QString)\0"
    "_textureName,_mode\0slotSwitchTexture(QString,int)\0"
    "_textureName,_id\0slotSwitchTexture(QString)\0"
    "_textureName\0slotUpdateTexture(QString,int)\0"
    "slotTextureChangeImage(QString,QImage&,int)\0"
    "_textureName,_image,_id\0"
    "slotTextureChangeImage(QString,QImage&)\0"
    "_textureName,_image\0"
    "slotTextureGetImage(QString,QImage&,int)\0"
    "slotTextureGetImage(QString,QImage&)\0"
    "slotTextureIndex(QString,int,int&)\0"
    "_textureName,_id,_index\0"
    "slotTextureIndexPropertyName(int,QString&)\0"
    "_id,_propertyName\0slotTextureName(int,int,QString&)\0"
    "_id,_textureIndex,_textureName\0"
    "slotTextureFilename(int,QString,QString&)\0"
    "_id,_textureName,_textureFilename\0"
    "slotGetCurrentTexture(int,QString&)\0"
    "_id,_textureName\0"
    "slotGetSubTextures(int,QString,QStringList&)\0"
    "_id,_multiTextureName,_subTextures\0"
    "fileOpened(int)\0_id\0addedEmptyObject(int)\0"
    "slotAboutToRestore(int)\0_objectid\0"
    "slotRestored(int)\0doSwitchTexture(QString,int)\0"
    "slotTextureMenu(QAction*)\0_action\0"
    "slotSetTextureProperties()\0"
    "applyDialogSettings(TextureData*,QString,int)\0"
    "_texData,_textureName,_id\0"
    "getCoordinates1D(QString,int,std::vector<double>&)\0"
    "_textureName,_id,_x\0slotUpdateContextMenu(int)\0"
    "_objectId\0slotTextureContextMenu(QAction*)\0"
    "version()\0QString\0"
};

void TextureControlPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TextureControlPlugin *_t = static_cast<TextureControlPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->updateTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->addMenubarAction((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< ContextMenuType(*)>(_a[3]))); break;
        case 7: _t->pluginsInitialized(); break;
        case 8: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 9: _t->slotDrawModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->slotUpdateAllTextures(); break;
        case 11: _t->slotTextureAdded((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 12: _t->slotTextureAdded((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 13: _t->slotMultiTextureAdded((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 14: _t->slotTextureUpdated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->slotSetTextureMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->slotSetTextureMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: _t->slotSwitchTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->slotSwitchTexture((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->slotUpdateTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 20: _t->slotTextureChangeImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 21: _t->slotTextureChangeImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 22: _t->slotTextureGetImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 23: _t->slotTextureGetImage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 24: _t->slotTextureIndex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 25: _t->slotTextureIndexPropertyName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: _t->slotTextureName((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 27: _t->slotTextureFilename((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 28: _t->slotGetCurrentTexture((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 29: _t->slotGetSubTextures((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 30: _t->fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->addedEmptyObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->slotAboutToRestore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->slotRestored((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->doSwitchTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->slotTextureMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 36: _t->slotSetTextureProperties(); break;
        case 37: _t->applyDialogSettings((*reinterpret_cast< TextureData*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 38: _t->getCoordinates1D((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::vector<double>(*)>(_a[3]))); break;
        case 39: _t->slotUpdateContextMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->slotTextureContextMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 41: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TextureControlPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TextureControlPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TextureControlPlugin,
      qt_meta_data_TextureControlPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TextureControlPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TextureControlPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TextureControlPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextureControlPlugin))
        return static_cast<void*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "TextureInterface"))
        return static_cast< TextureInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TextureInterface/1.0"))
        return static_cast< TextureInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< TextureControlPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< TextureControlPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int TextureControlPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void TextureControlPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TextureControlPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TextureControlPlugin::updateTexture(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TextureControlPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TextureControlPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TextureControlPlugin::addMenubarAction(QAction * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TextureControlPlugin::addContextMenuItem(QAction * _t1, DataType _t2, ContextMenuType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

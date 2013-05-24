/****************************************************************************
** Meta object code from reading C++ file 'MeanCurvature.hh'
**
** Created: Sat May 18 02:56:30 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-MeanCurvature/MeanCurvature.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeanCurvature.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MeanCurvaturePlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   53,   86,   86, 0x05,
      87,  116,   86,   86, 0x05,
     118,  150,   86,   86, 0x05,
     169,  229,   86,   86, 0x05,

 // slots: signature, parameters, type, tag, flags
     282,  313,   86,   86, 0x08,
     338,   86,   86,   86, 0x08,
     359,   86,   86,   86, 0x08,
     376,  402,  412,   86, 0x0a,
     417,   86,  427,   86, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MeanCurvaturePlugin[] = {
    "MeanCurvaturePlugin\0"
    "addTexture(QString,QString,uint)\0"
    "_textureName,_filename,dimension\0\0"
    "updatedTextures(QString,int)\0,\0"
    "setTextureMode(QString,QString)\0"
    "_textureName,_mode\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "slotUpdateTexture(QString,int)\0"
    "_textureName,_identifier\0pluginsInitialized()\0"
    "noguiSupported()\0computeMeanCurvature(int)\0"
    "_objectId\0bool\0version()\0QString\0"
};

void MeanCurvaturePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MeanCurvaturePlugin *_t = static_cast<MeanCurvaturePlugin *>(_o);
        switch (_id) {
        case 0: _t->addTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 1: _t->updatedTextures((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setTextureMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 4: _t->slotUpdateTexture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->pluginsInitialized(); break;
        case 6: _t->noguiSupported(); break;
        case 7: { bool _r = _t->computeMeanCurvature((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MeanCurvaturePlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MeanCurvaturePlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MeanCurvaturePlugin,
      qt_meta_data_MeanCurvaturePlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MeanCurvaturePlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MeanCurvaturePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MeanCurvaturePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MeanCurvaturePlugin))
        return static_cast<void*>(const_cast< MeanCurvaturePlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< MeanCurvaturePlugin*>(this));
    if (!strcmp(_clname, "TextureInterface"))
        return static_cast< TextureInterface*>(const_cast< MeanCurvaturePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< MeanCurvaturePlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.TextureInterface/1.0"))
        return static_cast< TextureInterface*>(const_cast< MeanCurvaturePlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int MeanCurvaturePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MeanCurvaturePlugin::addTexture(QString _t1, QString _t2, uint _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MeanCurvaturePlugin::updatedTextures(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MeanCurvaturePlugin::setTextureMode(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MeanCurvaturePlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

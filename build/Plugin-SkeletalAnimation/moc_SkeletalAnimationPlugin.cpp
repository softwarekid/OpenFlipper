/****************************************************************************
** Meta object code from reading C++ file 'SkeletalAnimationPlugin.hh'
**
** Created: Sat May 18 02:58:41 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-SkeletalAnimation/SkeletalAnimationPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SkeletalAnimationPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SkeletalAnimationPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   37,   37,   37, 0x05,
      38,   59,   37,   37, 0x05,
      74,   87,   37,   37, 0x05,
      96,  126,   37,   37, 0x05,
     136,  166,   37,   37, 0x05,
     176,  204,   37,   37, 0x05,
     224,  262,   37,   37, 0x05,
     296,  332,   37,   37, 0x05,

 // slots: signature, parameters, type, tag, flags
     352,   37,   37,   37, 0x0a,
     369,  166,   37,   37, 0x0a,
     403,  435,   37,   37, 0x0a,
     439,  435,   37,   37, 0x0a,
     455,  435,   37,   37, 0x0a,
     477,  435,   37,   37, 0x0a,
     496,   37,  516,   37, 0x0a,
     520,  540,  558,   37, 0x0a,
     563,  540,  558,   37, 0x0a,
     583,  599,  558,   37, 0x0a,
     610,  624,   37,   37, 0x0a,
     632,   37,  516,   37, 0x0a,
     643,  658,   37,   37, 0x0a,
     663,   37,   37,   37, 0x0a,
     679,   37,   37,   37, 0x0a,
     696,   37,   37,   37, 0x0a,
     712,   37,   37,   37, 0x0a,
     724,   37,   37,   37, 0x0a,
     736,   37,   37,   37, 0x0a,
     750,   37,   37,   37, 0x0a,
     761,  787,   37,   37, 0x0a,
     803,  829,   37,   37, 0x0a,
     839,   37,   37,   37, 0x0a,
     866,   37,   37,   37, 0x08,
     884,   37,   37,   37, 0x08,
     903,   37,   37,   37, 0x08,
     924,   37,   37,   37, 0x08,
     931,   37,   37,   37, 0x08,
     948,   37,   37,   37, 0x08,
     965,  988,   37,   37, 0x08,
     995,   37,   37,   37, 0x08,
    1026,   37,   37,   37, 0x08,
    1048, 1075,   37,   37, 0x08,
    1082,   37,   37,   37, 0x08,
    1101,   37,   37,   37, 0x08,
    1123,   37,   37,   37, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SkeletalAnimationPlugin[] = {
    "SkeletalAnimationPlugin\0updateView()\0"
    "\0log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "addEmptyObject(DataType,int&)\0_type,_id\0"
    "updatedObject(int,UpdateType)\0_id,_type\0"
    "pluginExists(QString,bool&)\0"
    "_pluginName,_exists\0"
    "functionExists(QString,QString,bool&)\0"
    "_pluginName,_functionName,_exists\0"
    "addToolbox(QString,QWidget*,QIcon*)\0"
    "_name,_widget,_icon\0slotAllCleared()\0"
    "slotObjectUpdated(int,UpdateType)\0"
    "slotObjectSelectionChanged(int)\0_id\0"
    "fileOpened(int)\0addedEmptyObject(int)\0"
    "objectDeleted(int)\0getNumberOfFrames()\0"
    "int\0attachSkin(int,int)\0skeletonId,skinId\0"
    "bool\0detachSkin(int,int)\0clearSkins(int)\0"
    "skeletonId\0setFrame(int)\0_iFrame\0"
    "getFrame()\0changeFPS(int)\0_fps\0"
    "playAnimation()\0pauseAnimation()\0"
    "stopAnimation()\0nextFrame()\0prevFrame()\0"
    "updateSkins()\0UpdateUI()\0"
    "setComboBoxPosition(uint)\0_animationIndex\0"
    "checkObjectSelection(int)\0_objectId\0"
    "slotAnimationNameChanged()\0setDescriptions()\0"
    "initializePlugin()\0pluginsInitialized()\0"
    "exit()\0slotAttachSkin()\0slotClearSkins()\0"
    "slotMethodChanged(int)\0_index\0"
    "slotAnimationIndexChanged(int)\0"
    "slotFrameChanged(int)\0slotSkipFramesChanged(int)\0"
    "_state\0slotAddAnimation()\0"
    "slotDeleteAnimation()\0animate()\0"
};

void SkeletalAnimationPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SkeletalAnimationPlugin *_t = static_cast<SkeletalAnimationPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 5: _t->pluginExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->functionExists((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->addToolbox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])),(*reinterpret_cast< QIcon*(*)>(_a[3]))); break;
        case 8: _t->slotAllCleared(); break;
        case 9: _t->slotObjectUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 10: _t->slotObjectSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->fileOpened((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->addedEmptyObject((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: { int _r = _t->getNumberOfFrames();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->attachSkin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = _t->detachSkin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: { bool _r = _t->clearSkins((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 18: _t->setFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: { int _r = _t->getFrame();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 20: _t->changeFPS((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->playAnimation(); break;
        case 22: _t->pauseAnimation(); break;
        case 23: _t->stopAnimation(); break;
        case 24: _t->nextFrame(); break;
        case 25: _t->prevFrame(); break;
        case 26: _t->updateSkins(); break;
        case 27: _t->UpdateUI(); break;
        case 28: _t->setComboBoxPosition((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 29: _t->checkObjectSelection((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 30: _t->slotAnimationNameChanged(); break;
        case 31: _t->setDescriptions(); break;
        case 32: _t->initializePlugin(); break;
        case 33: _t->pluginsInitialized(); break;
        case 34: _t->exit(); break;
        case 35: _t->slotAttachSkin(); break;
        case 36: _t->slotClearSkins(); break;
        case 37: _t->slotMethodChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->slotAnimationIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->slotFrameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->slotSkipFramesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 41: _t->slotAddAnimation(); break;
        case 42: _t->slotDeleteAnimation(); break;
        case 43: _t->animate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SkeletalAnimationPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SkeletalAnimationPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SkeletalAnimationPlugin,
      qt_meta_data_SkeletalAnimationPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SkeletalAnimationPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SkeletalAnimationPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SkeletalAnimationPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SkeletalAnimationPlugin))
        return static_cast<void*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "ToolboxInterface"))
        return static_cast< ToolboxInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "RPCInterface"))
        return static_cast< RPCInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolboxInterface/1.1"))
        return static_cast< ToolboxInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.RPCInterface/1.0"))
        return static_cast< RPCInterface*>(const_cast< SkeletalAnimationPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int SkeletalAnimationPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void SkeletalAnimationPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SkeletalAnimationPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SkeletalAnimationPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SkeletalAnimationPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SkeletalAnimationPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SkeletalAnimationPlugin::pluginExists(QString _t1, bool & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SkeletalAnimationPlugin::functionExists(QString _t1, QString _t2, bool & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SkeletalAnimationPlugin::addToolbox(QString _t1, QWidget * _t2, QIcon * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE

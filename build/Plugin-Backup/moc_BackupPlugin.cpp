/****************************************************************************
** Meta object code from reading C++ file 'BackupPlugin.hh'
**
** Created: Sat May 18 02:52:38 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-Backup/BackupPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackupPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BackupPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   26,   26,   26, 0x05,
      27,   57,   26,   26, 0x05,
      75,   96,   26,   26, 0x05,
     111,  124,   26,   26, 0x05,
     133,  170,   26,   26, 0x05,
     190,  200,   26,   26, 0x05,
     210,   26,   26,   26, 0x05,
     217,  200,   26,   26, 0x05,
     227,   26,   26,   26, 0x05,
     234,  200,   26,   26, 0x05,
     254,  200,   26,   26, 0x05,
     268,  307,   26,   26, 0x05,
     323,  345,   26,   26, 0x05,
     354,  385,   26,   26, 0x05,
     400,  452,   26,   26, 0x05,
     491,  538,   26,   26, 0x25,
     567,  621,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
     647,   26,   26,   26, 0x08,
     668,   26,   26,   26, 0x08,
     685,  710,   26,   26, 0x08,
     717,  200,   26,   26, 0x08,
     736,  777,   26,   26, 0x08,
     799,  829,   26,   26, 0x28,
     845,  902,   26,   26, 0x08,
     926,  200,   26,   26, 0x08,
     940,  200,   26,   26, 0x08,
     954,   26,   26,   26, 0x08,
     965,   26,   26,   26, 0x08,
     976, 1003,   26,   26, 0x08,
    1013,   26,   26,   26, 0x08,
    1029,   26,   26,   26, 0x08,
    1056,   26,   26,   26, 0x08,
    1073,   26,   26,   26, 0x08,
    1090,   26, 1100,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BackupPlugin[] = {
    "BackupPlugin\0updateView()\0\0"
    "updatedObject(int,UpdateType)\0"
    "_identifier,_type\0log(Logtype,QString)\0"
    "_type,_message\0log(QString)\0_message\0"
    "getMenubarMenu(QString,QMenu*&,bool)\0"
    "_name,_menu,_create\0undo(int)\0_objectid\0"
    "undo()\0redo(int)\0redo()\0aboutToRestore(int)\0"
    "restored(int)\0generateBackup(int,QString,UpdateType)\0"
    "_id,_name,_type\0addToolbar(QToolBar*)\0"
    "_toolbar\0getToolBar(QString,QToolBar*&)\0"
    "_name,_toolbar\0"
    "registerKey(int,Qt::KeyboardModifiers,QString,bool)\0"
    "_key,_modifiers,_description,_multiUse\0"
    "registerKey(int,Qt::KeyboardModifiers,QString)\0"
    "_key,_modifiers,_description\0"
    "addContextMenuItem(QAction*,DataType,ContextMenuType)\0"
    "_action,_objectType,_type\0"
    "pluginsInitialized()\0slotAllCleared()\0"
    "slotKeyEvent(QKeyEvent*)\0_event\0"
    "objectDeleted(int)\0"
    "slotCreateBackup(int,QString,UpdateType)\0"
    "_objectid,_name,_type\0"
    "slotCreateBackup(int,QString)\0"
    "_objectid,_name\0"
    "slotCreateBackup(IdList,QString,std::vector<UpdateType>)\0"
    "_objectids,_name,_types\0slotUndo(int)\0"
    "slotRedo(int)\0slotUndo()\0slotRedo()\0"
    "slotUpdateContextMenu(int)\0_objectId\0"
    "updateButtons()\0slotEnableDisableBackups()\0"
    "slotObjectUndo()\0slotObjectRedo()\0"
    "version()\0QString\0"
};

void BackupPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BackupPlugin *_t = static_cast<BackupPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->getMenubarMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMenu*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->undo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->undo(); break;
        case 7: _t->redo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->redo(); break;
        case 9: _t->aboutToRestore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->restored((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->generateBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 12: _t->addToolbar((*reinterpret_cast< QToolBar*(*)>(_a[1]))); break;
        case 13: _t->getToolBar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QToolBar*(*)>(_a[2]))); break;
        case 14: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 15: _t->registerKey((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 16: _t->addContextMenuItem((*reinterpret_cast< QAction*(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2])),(*reinterpret_cast< ContextMenuType(*)>(_a[3]))); break;
        case 17: _t->pluginsInitialized(); break;
        case 18: _t->slotAllCleared(); break;
        case 19: _t->slotKeyEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 20: _t->objectDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->slotCreateBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< UpdateType(*)>(_a[3]))); break;
        case 22: _t->slotCreateBackup((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 23: _t->slotCreateBackup((*reinterpret_cast< IdList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< std::vector<UpdateType>(*)>(_a[3]))); break;
        case 24: _t->slotUndo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->slotRedo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->slotUndo(); break;
        case 27: _t->slotRedo(); break;
        case 28: _t->slotUpdateContextMenu((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->updateButtons(); break;
        case 30: _t->slotEnableDisableBackups(); break;
        case 31: _t->slotObjectUndo(); break;
        case 32: _t->slotObjectRedo(); break;
        case 33: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BackupPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BackupPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BackupPlugin,
      qt_meta_data_BackupPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BackupPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BackupPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BackupPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BackupPlugin))
        return static_cast<void*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "KeyInterface"))
        return static_cast< KeyInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "BackupInterface"))
        return static_cast< BackupInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "ToolbarInterface"))
        return static_cast< ToolbarInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "ContextMenuInterface"))
        return static_cast< ContextMenuInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.KeyInterface/1.1"))
        return static_cast< KeyInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "GUI.BackupInterface/1.1"))
        return static_cast< BackupInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ToolbarInterface/1.1"))
        return static_cast< ToolbarInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< BackupPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.ContextMenuInterface/1.0"))
        return static_cast< ContextMenuInterface*>(const_cast< BackupPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int BackupPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    }
    return _id;
}

// SIGNAL 0
void BackupPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void BackupPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BackupPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BackupPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BackupPlugin::getMenubarMenu(QString _t1, QMenu * & _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BackupPlugin::undo(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BackupPlugin::undo()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void BackupPlugin::redo(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void BackupPlugin::redo()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void BackupPlugin::aboutToRestore(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void BackupPlugin::restored(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void BackupPlugin::generateBackup(int _t1, QString _t2, UpdateType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void BackupPlugin::addToolbar(QToolBar * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void BackupPlugin::getToolBar(QString _t1, QToolBar * & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void BackupPlugin::registerKey(int _t1, Qt::KeyboardModifiers _t2, QString _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 16
void BackupPlugin::addContextMenuItem(QAction * _t1, DataType _t2, ContextMenuType _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'SkeletonObjectInfoPlugin.hh'
**
** Created: Sat May 18 02:55:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-InfoSkeleton/SkeletonObjectInfoPlugin.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SkeletonObjectInfoPlugin.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InfoSkeletonObjectPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   85,  138,  138, 0x05,
     139,  160,  138,  138, 0x05,
     175,  188,  138,  138, 0x05,
     197,  228,  138,  138, 0x05,

 // slots: signature, parameters, type, tag, flags
     236,  138,  138,  138, 0x08,
     255,  138,  138,  138, 0x08,
     276,  138,  138,  138, 0x08,
     293,  335,  138,  138, 0x08,
     355,  138,  376,  138, 0x08,
     385,  401,  413,  138, 0x0a,
     417,  401,  413,  138, 0x0a,
     434,  401,  413,  138, 0x0a,
     449,  401,  469,  138, 0x0a,
     476,  401,  469,  138, 0x0a,
     496,  401,  469,  138, 0x0a,
     517,  537,  558,  138, 0x0a,
     565,  401,  558,  138, 0x0a,
     584,  401,  558,  138, 0x0a,
     603,  401,  558,  138, 0x0a,
     623,  138,  633,  138, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_InfoSkeletonObjectPlugin[] = {
    "InfoSkeletonObjectPlugin\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "\0log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "addWidgetToStatusbar(QWidget*)\0_widget\0"
    "initializePlugin()\0pluginsInitialized()\0"
    "noguiSupported()\0"
    "slotInformationRequested(QPoint,DataType)\0"
    "_clickedPoint,_type\0supportedDataTypes()\0"
    "DataType\0jointCount(int)\0_skeletonID\0"
    "int\0branchCount(int)\0leafCount(int)\0"
    "boundingBoxMin(int)\0Vector\0"
    "boundingBoxMax(int)\0boundingBoxSize(int)\0"
    "boneLength(int,int)\0_skeletonID,_jointID\0"
    "double\0minBoneLength(int)\0maxBoneLength(int)\0"
    "meanBoneLength(int)\0version()\0QString\0"
};

void InfoSkeletonObjectPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InfoSkeletonObjectPlugin *_t = static_cast<InfoSkeletonObjectPlugin *>(_o);
        switch (_id) {
        case 0: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 1: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addWidgetToStatusbar((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 4: _t->initializePlugin(); break;
        case 5: _t->pluginsInitialized(); break;
        case 6: _t->noguiSupported(); break;
        case 7: _t->slotInformationRequested((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< DataType(*)>(_a[2]))); break;
        case 8: { DataType _r = _t->supportedDataTypes();
            if (_a[0]) *reinterpret_cast< DataType*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->jointCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->branchCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->leafCount((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { Vector _r = _t->boundingBoxMin((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 13: { Vector _r = _t->boundingBoxMax((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 14: { Vector _r = _t->boundingBoxSize((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vector*>(_a[0]) = _r; }  break;
        case 15: { double _r = _t->boneLength((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 16: { double _r = _t->minBoneLength((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 17: { double _r = _t->maxBoneLength((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 18: { double _r = _t->meanBoneLength((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 19: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData InfoSkeletonObjectPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InfoSkeletonObjectPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InfoSkeletonObjectPlugin,
      qt_meta_data_InfoSkeletonObjectPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InfoSkeletonObjectPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InfoSkeletonObjectPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InfoSkeletonObjectPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoSkeletonObjectPlugin))
        return static_cast<void*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "InformationInterface"))
        return static_cast< InformationInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "StatusbarInterface"))
        return static_cast< StatusbarInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.InformationInterface/1.0"))
        return static_cast< InformationInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.StatusbarInterface/1.0"))
        return static_cast< StatusbarInterface*>(const_cast< InfoSkeletonObjectPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int InfoSkeletonObjectPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void InfoSkeletonObjectPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InfoSkeletonObjectPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InfoSkeletonObjectPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InfoSkeletonObjectPlugin::addWidgetToStatusbar(QWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

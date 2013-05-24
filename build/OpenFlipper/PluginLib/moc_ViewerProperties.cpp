/****************************************************************************
** Meta object code from reading C++ file 'ViewerProperties.hh'
**
** Created: Sat May 18 02:51:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/common/ViewerProperties.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewerProperties.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Viewer__ViewerProperties[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   35,   35,   35, 0x05,
      36,   57,   35,   35, 0x05,
      67,   93,   35,   35, 0x05,
      99,   93,   35,   35, 0x05,
     124,  159,   35,   35, 0x05,
     163,  159,   35,   35, 0x05,

 // slots: signature, parameters, type, tag, flags
     197,  227,   35,   35, 0x0a,
     234,  260,   35,   35, 0x0a,
     266,  287,   35,   35, 0x0a,
     296,   35,  315,   35, 0x0a,
     323,   35,  315,   35, 0x0a,
     338,   35,  356,   35, 0x0a,
     360,   35,  378,   35, 0x0a,
     385,   35,  378,   35, 0x0a,
     408,  432,   35,   35, 0x0a,
     440,  432,   35,   35, 0x0a,
     469,   35,  482,   35, 0x0a,
     487,   35,   35,   35, 0x0a,
     498,   35,   35,   35, 0x0a,
     508,   35,  526,   35, 0x0a,
     537,   35,  558,   35, 0x0a,
     563,   35,  582,   35, 0x0a,
     589,  617,   35,   35, 0x0a,
     624,  617,   35,   35, 0x0a,
     646,  617,   35,   35, 0x0a,
     670,   35,   35,   35, 0x0a,
     683,   35,   35,   35, 0x0a,
     698,   35,  482,   35, 0x0a,
     713,   35,  482,   35, 0x0a,
     731,  753,   35,   35, 0x0a,
     760,  753,   35,   35, 0x0a,
     783,   35,  482,   35, 0x0a,
     802,  753,   35,   35, 0x0a,
     822,   35,  482,   35, 0x0a,
     838,  753,   35,   35, 0x0a,
     855,   35,  482,   35, 0x0a,
     868,  753,   35,   35, 0x0a,
     884,   35,  482,   35, 0x0a,
     896,  928,   35,   35, 0x0a,
     936,   35,  951,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Viewer__ViewerProperties[] = {
    "Viewer::ViewerProperties\0updated()\0\0"
    "drawModeChanged(int)\0_viewerId\0"
    "getPickMode(std::string&)\0_mode\0"
    "setPickMode(std::string)\0"
    "getActionMode(Viewer::ActionMode&)\0"
    "_am\0setActionMode(Viewer::ActionMode)\0"
    "snapshotBaseFileName(QString)\0_fname\0"
    "snapshotFileType(QString)\0_type\0"
    "snapshotCounter(int)\0_counter\0"
    "snapshotFileType()\0QString\0snapshotName()\0"
    "snapshotCounter()\0int\0wheelZoomFactor()\0"
    "double\0wheelZoomFactorShift()\0"
    "wheelZoomFactor(double)\0_factor\0"
    "wheelZoomFactorShift(double)\0isCCWFront()\0"
    "bool\0ccwFront()\0cwFront()\0backgroundColor()\0"
    "ACG::Vec4f\0backgroundColorRgb()\0QRgb\0"
    "backgroundQColor()\0QColor\0"
    "backgroundColor(ACG::Vec4f)\0_color\0"
    "backgroundColor(QRgb)\0backgroundColor(QColor)\0"
    "lockUpdate()\0unLockUpdate()\0updateLocked()\0"
    "backFaceCulling()\0backFaceCulling(bool)\0"
    "_state\0twoSidedLighting(bool)\0"
    "twoSidedLighting()\0multisampling(bool)\0"
    "multisampling()\0mipmapping(bool)\0"
    "mipmapping()\0animation(bool)\0animation()\0"
    "objectMarker(ViewObjectMarker*)\0_marker\0"
    "objectMarker()\0ViewObjectMarker*\0"
};

void Viewer::ViewerProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewerProperties *_t = static_cast<ViewerProperties *>(_o);
        switch (_id) {
        case 0: _t->updated(); break;
        case 1: _t->drawModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->getPickMode((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->setPickMode((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 4: _t->getActionMode((*reinterpret_cast< Viewer::ActionMode(*)>(_a[1]))); break;
        case 5: _t->setActionMode((*reinterpret_cast< const Viewer::ActionMode(*)>(_a[1]))); break;
        case 6: _t->snapshotBaseFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->snapshotFileType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->snapshotCounter((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: { QString _r = _t->snapshotFileType();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->snapshotName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->snapshotCounter();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { double _r = _t->wheelZoomFactor();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 13: { double _r = _t->wheelZoomFactorShift();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 14: _t->wheelZoomFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->wheelZoomFactorShift((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: { bool _r = _t->isCCWFront();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: _t->ccwFront(); break;
        case 18: _t->cwFront(); break;
        case 19: { ACG::Vec4f _r = _t->backgroundColor();
            if (_a[0]) *reinterpret_cast< ACG::Vec4f*>(_a[0]) = _r; }  break;
        case 20: { QRgb _r = _t->backgroundColorRgb();
            if (_a[0]) *reinterpret_cast< QRgb*>(_a[0]) = _r; }  break;
        case 21: { QColor _r = _t->backgroundQColor();
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        case 22: _t->backgroundColor((*reinterpret_cast< ACG::Vec4f(*)>(_a[1]))); break;
        case 23: _t->backgroundColor((*reinterpret_cast< QRgb(*)>(_a[1]))); break;
        case 24: _t->backgroundColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 25: _t->lockUpdate(); break;
        case 26: _t->unLockUpdate(); break;
        case 27: { bool _r = _t->updateLocked();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 28: { bool _r = _t->backFaceCulling();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: _t->backFaceCulling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->twoSidedLighting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: { bool _r = _t->twoSidedLighting();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 32: _t->multisampling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: { bool _r = _t->multisampling();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 34: _t->mipmapping((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: { bool _r = _t->mipmapping();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 36: _t->animation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: { bool _r = _t->animation();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 38: _t->objectMarker((*reinterpret_cast< ViewObjectMarker*(*)>(_a[1]))); break;
        case 39: { ViewObjectMarker* _r = _t->objectMarker();
            if (_a[0]) *reinterpret_cast< ViewObjectMarker**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Viewer::ViewerProperties::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Viewer::ViewerProperties::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Viewer__ViewerProperties,
      qt_meta_data_Viewer__ViewerProperties, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Viewer::ViewerProperties::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Viewer::ViewerProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Viewer::ViewerProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Viewer__ViewerProperties))
        return static_cast<void*>(const_cast< ViewerProperties*>(this));
    return QObject::qt_metacast(_clname);
}

int Viewer::ViewerProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    }
    return _id;
}

// SIGNAL 0
void Viewer::ViewerProperties::updated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Viewer::ViewerProperties::drawModeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Viewer::ViewerProperties::getPickMode(std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Viewer::ViewerProperties::setPickMode(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Viewer::ViewerProperties::getActionMode(Viewer::ActionMode & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Viewer::ViewerProperties::setActionMode(const Viewer::ActionMode _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE

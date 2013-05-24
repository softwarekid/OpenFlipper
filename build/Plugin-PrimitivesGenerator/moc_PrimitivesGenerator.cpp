/****************************************************************************
** Meta object code from reading C++ file 'PrimitivesGenerator.hh'
**
** Created: Sat May 18 02:57:23 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-PrimitivesGenerator/PrimitivesGenerator.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PrimitivesGenerator.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PrimitivesGeneratorPlugin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   39,   39,   39, 0x05,
      40,   70,   39,   39, 0x05,
      80,  140,   39,   39, 0x05,
     193,  214,   39,   39, 0x05,
     229,  242,   39,   39, 0x05,
     251,  288,   39,   39, 0x05,
     308,  338,   39,   39, 0x05,

 // slots: signature, parameters, type, tag, flags
     348,   39,   39,   39, 0x08,
     367,   39,   39,   39, 0x08,
     388,   39,   39,   39, 0x08,
     405,   39,  415,   39, 0x0a,
     423,  486,  531,   39, 0x0a,
     535,  593,  531,   39, 0x2a,
     630,  683,  531,   39, 0x2a,
     715,  761,  531,   39, 0x2a,
     785,  824,  531,   39, 0x2a,
     840,  872,  531,   39, 0x2a,
     882,   39,  531,   39, 0x2a,
     908,  933,  531,   39, 0x0a,
     951,  872,  531,   39, 0x2a,
     969,   39,  531,   39, 0x2a,
     981, 1011,  531,   39, 0x0a,
    1029,  872,  531,   39, 0x2a,
    1052,   39,  531,   39, 0x2a,
    1069, 1011,  531,   39, 0x0a,
    1095,  872,  531,   39, 0x2a,
    1114,   39,  531,   39, 0x2a,
    1127, 1011,  531,   39, 0x0a,
    1162,  872,  531,   39, 0x2a,
    1190,   39,  531,   39, 0x2a,
    1212, 1011,  531,   39, 0x0a,
    1242,  872,  531,   39, 0x2a,
    1265,   39,  531,   39, 0x2a,
    1282, 1011,  531,   39, 0x0a,
    1311,  872,  531,   39, 0x2a,
    1333,   39,  531,   39, 0x2a,
    1349, 1011,  531,   39, 0x0a,
    1380,  872,  531,   39, 0x2a,
    1404,   39,  531,   39, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_PrimitivesGeneratorPlugin[] = {
    "PrimitivesGeneratorPlugin\0updateView()\0"
    "\0updatedObject(int,UpdateType)\0_id,_type\0"
    "setSlotDescription(QString,QString,QStringList,QStringList)\0"
    "_slotName,_slotDescription,_parameters,_descriptions\0"
    "log(Logtype,QString)\0_type,_message\0"
    "log(QString)\0_message\0"
    "getMenubarMenu(QString,QMenu*&,bool)\0"
    "_name,_menu,_create\0addEmptyObject(DataType,int&)\0"
    "_type,_id\0initializePlugin()\0"
    "pluginsInitialized()\0noguiSupported()\0"
    "version()\0QString\0"
    "addTriangulatedCylinder(Vector,Vector,double,double,bool,bool)\0"
    "_position,_axis,_radius,_height,_top,_bottom\0"
    "int\0addTriangulatedCylinder(Vector,Vector,double,double,bool)\0"
    "_position,_axis,_radius,_height,_top\0"
    "addTriangulatedCylinder(Vector,Vector,double,double)\0"
    "_position,_axis,_radius,_height\0"
    "addTriangulatedCylinder(Vector,Vector,double)\0"
    "_position,_axis,_radius\0"
    "addTriangulatedCylinder(Vector,Vector)\0"
    "_position,_axis\0addTriangulatedCylinder(Vector)\0"
    "_position\0addTriangulatedCylinder()\0"
    "addSphere(Vector,double)\0_position,_radius\0"
    "addSphere(Vector)\0addSphere()\0"
    "addTetrahedron(Vector,double)\0"
    "_position,_length\0addTetrahedron(Vector)\0"
    "addTetrahedron()\0addPyramid(Vector,double)\0"
    "addPyramid(Vector)\0addPyramid()\0"
    "addTriangulatedCube(Vector,double)\0"
    "addTriangulatedCube(Vector)\0"
    "addTriangulatedCube()\0"
    "addIcosahedron(Vector,double)\0"
    "addIcosahedron(Vector)\0addIcosahedron()\0"
    "addOctahedron(Vector,double)\0"
    "addOctahedron(Vector)\0addOctahedron()\0"
    "addDodecahedron(Vector,double)\0"
    "addDodecahedron(Vector)\0addDodecahedron()\0"
};

void PrimitivesGeneratorPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PrimitivesGeneratorPlugin *_t = static_cast<PrimitivesGeneratorPlugin *>(_o);
        switch (_id) {
        case 0: _t->updateView(); break;
        case 1: _t->updatedObject((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const UpdateType(*)>(_a[2]))); break;
        case 2: _t->setSlotDescription((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 3: _t->log((*reinterpret_cast< Logtype(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->getMenubarMenu((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QMenu*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->addEmptyObject((*reinterpret_cast< DataType(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->initializePlugin(); break;
        case 8: _t->pluginsInitialized(); break;
        case 9: _t->noguiSupported(); break;
        case 10: { QString _r = _t->version();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->addTriangulatedCylinder((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const Vector(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const bool(*)>(_a[5])),(*reinterpret_cast< const bool(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->addTriangulatedCylinder((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const Vector(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->addTriangulatedCylinder((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const Vector(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->addTriangulatedCylinder((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const Vector(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->addTriangulatedCylinder((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const Vector(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->addTriangulatedCylinder((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: { int _r = _t->addTriangulatedCylinder();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: { int _r = _t->addSphere((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 19: { int _r = _t->addSphere((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 20: { int _r = _t->addSphere();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 21: { int _r = _t->addTetrahedron((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 22: { int _r = _t->addTetrahedron((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 23: { int _r = _t->addTetrahedron();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 24: { int _r = _t->addPyramid((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 25: { int _r = _t->addPyramid((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 26: { int _r = _t->addPyramid();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 27: { int _r = _t->addTriangulatedCube((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 28: { int _r = _t->addTriangulatedCube((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: { int _r = _t->addTriangulatedCube();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 30: { int _r = _t->addIcosahedron((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 31: { int _r = _t->addIcosahedron((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 32: { int _r = _t->addIcosahedron();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 33: { int _r = _t->addOctahedron((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 34: { int _r = _t->addOctahedron((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 35: { int _r = _t->addOctahedron();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 36: { int _r = _t->addDodecahedron((*reinterpret_cast< const Vector(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 37: { int _r = _t->addDodecahedron((*reinterpret_cast< const Vector(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 38: { int _r = _t->addDodecahedron();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PrimitivesGeneratorPlugin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PrimitivesGeneratorPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PrimitivesGeneratorPlugin,
      qt_meta_data_PrimitivesGeneratorPlugin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PrimitivesGeneratorPlugin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PrimitivesGeneratorPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PrimitivesGeneratorPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrimitivesGeneratorPlugin))
        return static_cast<void*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "BaseInterface"))
        return static_cast< BaseInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "LoggingInterface"))
        return static_cast< LoggingInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "MenuInterface"))
        return static_cast< MenuInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "LoadSaveInterface"))
        return static_cast< LoadSaveInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.BaseInterface/1.0"))
        return static_cast< BaseInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoggingInterface/1.0"))
        return static_cast< LoggingInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.MenuInterface/1.0"))
        return static_cast< MenuInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    if (!strcmp(_clname, "OpenFlipper.LoadSaveInterface/1.1"))
        return static_cast< LoadSaveInterface*>(const_cast< PrimitivesGeneratorPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int PrimitivesGeneratorPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void PrimitivesGeneratorPlugin::updateView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PrimitivesGeneratorPlugin::updatedObject(int _t1, const UpdateType & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PrimitivesGeneratorPlugin::setSlotDescription(QString _t1, QString _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PrimitivesGeneratorPlugin::log(Logtype _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PrimitivesGeneratorPlugin::log(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PrimitivesGeneratorPlugin::getMenubarMenu(QString _t1, QMenu * & _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PrimitivesGeneratorPlugin::addEmptyObject(DataType _t1, int & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE

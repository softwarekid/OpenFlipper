/****************************************************************************
** Meta object code from reading C++ file 'graphicsScene.hh'
**
** Created: Sat May 18 02:59:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/scene/graphicsScene.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsScene.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__GraphicsScene[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   36,   36,   36, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   36,   36,   36, 0x0a,
      53,   70,   36,   36, 0x0a,
      77,   36,   36,   36, 0x2a,
      90,   36,   36,   36, 0x08,
     110,  131,   36,   36, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VSI__GraphicsScene[] = {
    "VSI::GraphicsScene\0contentChanged()\0"
    "\0contentChange()\0clearScene(bool)\0"
    "_start\0clearScene()\0updateConnections()\0"
    "sceneResized(QRectF)\0_rect\0"
};

void VSI::GraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GraphicsScene *_t = static_cast<GraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->contentChanged(); break;
        case 1: _t->contentChange(); break;
        case 2: _t->clearScene((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->clearScene(); break;
        case 4: _t->updateConnections(); break;
        case 5: _t->sceneResized((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VSI::GraphicsScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::GraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_VSI__GraphicsScene,
      qt_meta_data_VSI__GraphicsScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::GraphicsScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::GraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::GraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__GraphicsScene))
        return static_cast<void*>(const_cast< GraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int VSI::GraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void VSI::GraphicsScene::contentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE

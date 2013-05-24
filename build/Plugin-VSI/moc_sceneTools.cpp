/****************************************************************************
** Meta object code from reading C++ file 'sceneTools.hh'
**
** Created: Sat May 18 02:59:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/scene/sceneTools.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sceneTools.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__SceneTools[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   41,   47,   47, 0x08,
      48,   47,   47,   47, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VSI__SceneTools[] = {
    "VSI::SceneTools\0sceneRectChanged(QRectF)\0"
    "_rect\0\0updateArrows()\0"
};

void VSI::SceneTools::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SceneTools *_t = static_cast<SceneTools *>(_o);
        switch (_id) {
        case 0: _t->sceneRectChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 1: _t->updateArrows(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VSI::SceneTools::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::SceneTools::staticMetaObject = {
    { &QGraphicsWidget::staticMetaObject, qt_meta_stringdata_VSI__SceneTools,
      qt_meta_data_VSI__SceneTools, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::SceneTools::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::SceneTools::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::SceneTools::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__SceneTools))
        return static_cast<void*>(const_cast< SceneTools*>(this));
    return QGraphicsWidget::qt_metacast(_clname);
}

int VSI::SceneTools::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

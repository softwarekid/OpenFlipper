/****************************************************************************
** Meta object code from reading C++ file 'QtTranslationManipulatorNode.hh'
**
** Created: Sat May 18 02:49:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtScenegraph/QtTranslationManipulatorNode.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtTranslationManipulatorNode.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__SceneGraph__QtTranslationManipulatorNode[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      46,  107,  120,  120, 0x05,
     121,  175,  120,  120, 0x05,
     190,  237,  120,  120, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ACG__SceneGraph__QtTranslationManipulatorNode[] = {
    "ACG::SceneGraph::QtTranslationManipulatorNode\0"
    "manipulatorMoved(QtTranslationManipulatorNode*,QMouseEvent*)\0"
    "_node,_event\0\0"
    "visibilityChanged(QtTranslationManipulatorNode*,bool)\0"
    "_node,_visible\0"
    "positionChanged(QtTranslationManipulatorNode*)\0"
    "_node\0"
};

void ACG::SceneGraph::QtTranslationManipulatorNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtTranslationManipulatorNode *_t = static_cast<QtTranslationManipulatorNode *>(_o);
        switch (_id) {
        case 0: _t->manipulatorMoved((*reinterpret_cast< QtTranslationManipulatorNode*(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 1: _t->visibilityChanged((*reinterpret_cast< QtTranslationManipulatorNode*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->positionChanged((*reinterpret_cast< QtTranslationManipulatorNode*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::SceneGraph::QtTranslationManipulatorNode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::SceneGraph::QtTranslationManipulatorNode::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ACG__SceneGraph__QtTranslationManipulatorNode,
      qt_meta_data_ACG__SceneGraph__QtTranslationManipulatorNode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::SceneGraph::QtTranslationManipulatorNode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::SceneGraph::QtTranslationManipulatorNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::SceneGraph::QtTranslationManipulatorNode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__SceneGraph__QtTranslationManipulatorNode))
        return static_cast<void*>(const_cast< QtTranslationManipulatorNode*>(this));
    if (!strcmp(_clname, "TranslationManipulatorNode"))
        return static_cast< TranslationManipulatorNode*>(const_cast< QtTranslationManipulatorNode*>(this));
    return QObject::qt_metacast(_clname);
}

int ACG::SceneGraph::QtTranslationManipulatorNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ACG::SceneGraph::QtTranslationManipulatorNode::manipulatorMoved(QtTranslationManipulatorNode * _t1, QMouseEvent * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ACG::SceneGraph::QtTranslationManipulatorNode::visibilityChanged(QtTranslationManipulatorNode * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ACG::SceneGraph::QtTranslationManipulatorNode::positionChanged(QtTranslationManipulatorNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

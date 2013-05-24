/****************************************************************************
** Meta object code from reading C++ file 'QtSceneGraphWidget.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtSceneGraphWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtSceneGraphWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtSceneGraphWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   81,   87,   87, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,  123,   87,   87, 0x0a,
     133,  171,   87,   87, 0x08,
     182,  228,   87,   87, 0x08,
     234,   81,   87,   87, 0x08,
     278,  301,   87,   87, 0x08,
     309,  301,   87,   87, 0x08,
     334,   87,   87,   87, 0x08,
     353,   87,   87,   87, 0x08,
     371,   87,   87,   87, 0x08,
     388,   87,   87,   87, 0x08,
     409,   87,   87,   87, 0x08,
     435,   87,   87,   87, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtSceneGraphWidget[] = {
    "ACG::QtWidgets::QtSceneGraphWidget\0"
    "signalNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "_node\0\0update(ACG::SceneGraph::BaseNode*)\0"
    "_rootNode\0slotItemPressed(QTreeWidgetItem*,int)\0"
    "_item,_col\0slotItemExpandedOrCollapsed(QTreeWidgetItem*)\0"
    "_item\0slotNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "slotModeMenu(QAction*)\0_action\0"
    "slotStatusMenu(QAction*)\0slotEditMaterial()\0"
    "slotEditTexture()\0slotEditShader()\0"
    "slotEditClipPlanes()\0slotEditCoordinateFrame()\0"
    "expandAll()\0"
};

void ACG::QtWidgets::QtSceneGraphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtSceneGraphWidget *_t = static_cast<QtSceneGraphWidget *>(_o);
        switch (_id) {
        case 0: _t->signalNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 1: _t->update((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 2: _t->slotItemPressed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slotItemExpandedOrCollapsed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->slotNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 5: _t->slotModeMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->slotStatusMenu((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->slotEditMaterial(); break;
        case 8: _t->slotEditTexture(); break;
        case 9: _t->slotEditShader(); break;
        case 10: _t->slotEditClipPlanes(); break;
        case 11: _t->slotEditCoordinateFrame(); break;
        case 12: _t->expandAll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtSceneGraphWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtSceneGraphWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtSceneGraphWidget,
      qt_meta_data_ACG__QtWidgets__QtSceneGraphWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtSceneGraphWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtSceneGraphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtSceneGraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtSceneGraphWidget))
        return static_cast<void*>(const_cast< QtSceneGraphWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int ACG::QtWidgets::QtSceneGraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void ACG::QtWidgets::QtSceneGraphWidget::signalNodeChanged(ACG::SceneGraph::BaseNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_ACG__QtWidgets__QtSceneGraphDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   81,   87,   87, 0x05,

 // slots: signature, parameters, type, tag, flags
      88,  123,   87,   87, 0x0a,
     133,   81,   87,   87, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtSceneGraphDialog[] = {
    "ACG::QtWidgets::QtSceneGraphDialog\0"
    "signalNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "_node\0\0update(ACG::SceneGraph::BaseNode*)\0"
    "_rootNode\0slotNodeChanged(ACG::SceneGraph::BaseNode*)\0"
};

void ACG::QtWidgets::QtSceneGraphDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtSceneGraphDialog *_t = static_cast<QtSceneGraphDialog *>(_o);
        switch (_id) {
        case 0: _t->signalNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 1: _t->update((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 2: _t->slotNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtSceneGraphDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtSceneGraphDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtSceneGraphDialog,
      qt_meta_data_ACG__QtWidgets__QtSceneGraphDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtSceneGraphDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtSceneGraphDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtSceneGraphDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtSceneGraphDialog))
        return static_cast<void*>(const_cast< QtSceneGraphDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ACG::QtWidgets::QtSceneGraphDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void ACG::QtWidgets::QtSceneGraphDialog::signalNodeChanged(ACG::SceneGraph::BaseNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

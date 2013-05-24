/****************************************************************************
** Meta object code from reading C++ file 'simpleViewer.hh'
**
** Created: Sat May 18 02:51:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/glWidget/simpleViewer.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simpleViewer.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimpleViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   47,   51,   51, 0x08,
      52,   47,   51,   51, 0x08,
      87,  113,   51,   51, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimpleViewer[] = {
    "SimpleViewer\0setActionMode(Viewer::ActionMode)\0"
    "_am\0\0getActionMode(Viewer::ActionMode&)\0"
    "getPickMode(std::string&)\0_name\0"
};

void SimpleViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimpleViewer *_t = static_cast<SimpleViewer *>(_o);
        switch (_id) {
        case 0: _t->setActionMode((*reinterpret_cast< const Viewer::ActionMode(*)>(_a[1]))); break;
        case 1: _t->getActionMode((*reinterpret_cast< Viewer::ActionMode(*)>(_a[1]))); break;
        case 2: _t->getPickMode((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SimpleViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimpleViewer::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_SimpleViewer,
      qt_meta_data_SimpleViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimpleViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimpleViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimpleViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleViewer))
        return static_cast<void*>(const_cast< SimpleViewer*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int SimpleViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

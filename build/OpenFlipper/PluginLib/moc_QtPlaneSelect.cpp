/****************************************************************************
** Meta object code from reading C++ file 'QtPlaneSelect.hh'
**
** Created: Sat May 18 02:51:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ObjectTypes/Plane/QtPlaneSelect.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtPlaneSelect.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtPlaneSelect[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   33,   33,   33, 0x05,
      34,   33,   33,   33, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   81,   33,   33, 0x0a,
      88,   81,   33,   33, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QtPlaneSelect[] = {
    "QtPlaneSelect\0signalTriggerCut()\0\0"
    "updateViewProxy()\0slotMouseEvent(QMouseEvent*)\0"
    "_event\0slotKeyReleaseEvent(QKeyEvent*)\0"
};

void QtPlaneSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtPlaneSelect *_t = static_cast<QtPlaneSelect *>(_o);
        switch (_id) {
        case 0: _t->signalTriggerCut(); break;
        case 1: _t->updateViewProxy(); break;
        case 2: _t->slotMouseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->slotKeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtPlaneSelect::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtPlaneSelect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtPlaneSelect,
      qt_meta_data_QtPlaneSelect, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtPlaneSelect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtPlaneSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtPlaneSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtPlaneSelect))
        return static_cast<void*>(const_cast< QtPlaneSelect*>(this));
    return QObject::qt_metacast(_clname);
}

int QtPlaneSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QtPlaneSelect::signalTriggerCut()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QtPlaneSelect::updateViewProxy()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
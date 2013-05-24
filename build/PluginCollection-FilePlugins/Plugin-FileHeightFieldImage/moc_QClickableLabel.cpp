/****************************************************************************
** Meta object code from reading C++ file 'QClickableLabel.hh'
**
** Created: Sat May 18 03:00:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluginCollection-FilePlugins/Plugin-FileHeightFieldImage/QClickableLabel.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QClickableLabel.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QClickableLabel[] = {

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
      16,   46,   49,   49, 0x05,
      50,   46,   49,   49, 0x05,
      79,   46,   49,   49, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QClickableLabel[] = {
    "QClickableLabel\0mouseButtonPressEvent(QPoint)\0"
    "_p\0\0mouseButtonMoveEvent(QPoint)\0"
    "mouseButtonReleaseEvent(QPoint)\0"
};

void QClickableLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QClickableLabel *_t = static_cast<QClickableLabel *>(_o);
        switch (_id) {
        case 0: _t->mouseButtonPressEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->mouseButtonMoveEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->mouseButtonReleaseEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QClickableLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QClickableLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QClickableLabel,
      qt_meta_data_QClickableLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QClickableLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QClickableLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QClickableLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QClickableLabel))
        return static_cast<void*>(const_cast< QClickableLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int QClickableLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void QClickableLabel::mouseButtonPressEvent(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QClickableLabel::mouseButtonMoveEvent(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QClickableLabel::mouseButtonReleaseEvent(QPoint _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

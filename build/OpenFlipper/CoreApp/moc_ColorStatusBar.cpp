/****************************************************************************
** Meta object code from reading C++ file 'ColorStatusBar.hh'
**
** Created: Sat May 18 02:52:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/coreWidget/ColorStatusBar.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorStatusBar.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ColorStatusBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   40,   56,   56, 0x0a,
      57,   78,   56,   56, 0x2a,
      86,  118,   56,   56, 0x0a,
     141,  169,   56,   56, 0x2a,
     184,   78,   56,   56, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ColorStatusBar[] = {
    "ColorStatusBar\0showMessage(QString,int)\0"
    "message,timeout\0\0showMessage(QString)\0"
    "message\0showMessage(QString,QColor,int)\0"
    "message,_color,timeout\0"
    "showMessage(QString,QColor)\0message,_color\0"
    "slotMessageChanged(QString)\0"
};

void ColorStatusBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ColorStatusBar *_t = static_cast<ColorStatusBar *>(_o);
        switch (_id) {
        case 0: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->showMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 4: _t->slotMessageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ColorStatusBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ColorStatusBar::staticMetaObject = {
    { &QStatusBar::staticMetaObject, qt_meta_stringdata_ColorStatusBar,
      qt_meta_data_ColorStatusBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ColorStatusBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ColorStatusBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ColorStatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ColorStatusBar))
        return static_cast<void*>(const_cast< ColorStatusBar*>(this));
    return QStatusBar::qt_metacast(_clname);
}

int ColorStatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

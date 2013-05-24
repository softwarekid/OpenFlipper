/****************************************************************************
** Meta object code from reading C++ file 'VideoCaptureDialog.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/videoCaptureDialog/VideoCaptureDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoCaptureDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VideoCaptureDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   55,   86,   86, 0x05,
      87,  110,   86,   86, 0x05,
     125,  110,   86,   86, 0x05,

 // slots: signature, parameters, type, tag, flags
     152,   86,   86,   86, 0x08,
     176,   86,   86,   86, 0x08,
     187,   86,   86,   86, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_VideoCaptureDialog[] = {
    "VideoCaptureDialog\0"
    "startVideoCapture(QString,int,bool)\0"
    "_baseName,_fps,_captureViewers\0\0"
    "resizeViewers(int,int)\0_width,_height\0"
    "resizeApplication(int,int)\0"
    "slotStartVideoCapture()\0findFile()\0"
    "slotChangeResolution()\0"
};

void VideoCaptureDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VideoCaptureDialog *_t = static_cast<VideoCaptureDialog *>(_o);
        switch (_id) {
        case 0: _t->startVideoCapture((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->resizeViewers((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->resizeApplication((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slotStartVideoCapture(); break;
        case 4: _t->findFile(); break;
        case 5: _t->slotChangeResolution(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VideoCaptureDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VideoCaptureDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VideoCaptureDialog,
      qt_meta_data_VideoCaptureDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VideoCaptureDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VideoCaptureDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VideoCaptureDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VideoCaptureDialog))
        return static_cast<void*>(const_cast< VideoCaptureDialog*>(this));
    if (!strcmp(_clname, "Ui::VideoCaptureDialog"))
        return static_cast< Ui::VideoCaptureDialog*>(const_cast< VideoCaptureDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VideoCaptureDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void VideoCaptureDialog::startVideoCapture(QString _t1, int _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VideoCaptureDialog::resizeViewers(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VideoCaptureDialog::resizeApplication(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

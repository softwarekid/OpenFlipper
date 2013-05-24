/****************************************************************************
** Meta object code from reading C++ file 'OpenFlipperThread.hh'
**
** Created: Sat May 18 02:51:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/threads/OpenFlipperThread.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenFlipperThread.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenFlipperThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   37,   51,   51, 0x05,
      52,   70,   51,   51, 0x05,
      77,   51,   51,   51, 0x25,
      88,   70,   51,   51, 0x05,
     106,   51,   51,   51, 0x05,

 // slots: signature, parameters, type, tag, flags
     132,   70,   51,   51, 0x0a,
     152,   51,   51,   51, 0x0a,
     170,   51,   51,   51, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OpenFlipperThread[] = {
    "OpenFlipperThread\0state(QString,int)\0"
    "_jobId,_state\0\0function(QString)\0"
    "_jobId\0function()\0finished(QString)\0"
    "startProcessingInternal()\0slotCancel(QString)\0"
    "startProcessing()\0slotJobFinished()\0"
};

void OpenFlipperThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenFlipperThread *_t = static_cast<OpenFlipperThread *>(_o);
        switch (_id) {
        case 0: _t->state((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->function((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->function(); break;
        case 3: _t->finished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->startProcessingInternal(); break;
        case 5: _t->slotCancel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->startProcessing(); break;
        case 7: _t->slotJobFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OpenFlipperThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenFlipperThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_OpenFlipperThread,
      qt_meta_data_OpenFlipperThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenFlipperThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenFlipperThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenFlipperThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenFlipperThread))
        return static_cast<void*>(const_cast< OpenFlipperThread*>(this));
    return QThread::qt_metacast(_clname);
}

int OpenFlipperThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void OpenFlipperThread::state(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OpenFlipperThread::function(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void OpenFlipperThread::finished(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void OpenFlipperThread::startProcessingInternal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
static const uint qt_meta_data_OpenFlipperJob[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   32,   39,   39, 0x05,
      40,   39,   39,   39, 0x25,
      50,   39,   39,   39, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   39,   39,   39, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OpenFlipperJob[] = {
    "OpenFlipperJob\0process(QString)\0_jobId\0"
    "\0process()\0finished()\0startJobProcessing()\0"
};

void OpenFlipperJob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenFlipperJob *_t = static_cast<OpenFlipperJob *>(_o);
        switch (_id) {
        case 0: _t->process((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->process(); break;
        case 2: _t->finished(); break;
        case 3: _t->startJobProcessing(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OpenFlipperJob::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenFlipperJob::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OpenFlipperJob,
      qt_meta_data_OpenFlipperJob, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenFlipperJob::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenFlipperJob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenFlipperJob::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenFlipperJob))
        return static_cast<void*>(const_cast< OpenFlipperJob*>(this));
    return QObject::qt_metacast(_clname);
}

int OpenFlipperJob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void OpenFlipperJob::process(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void OpenFlipperJob::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

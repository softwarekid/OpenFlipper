/****************************************************************************
** Meta object code from reading C++ file 'processManagerWidget.hh'
**
** Created: Sat May 18 02:52:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/processManagerWidget/processManagerWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processManagerWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JobCancelButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_JobCancelButton[] = {
    "JobCancelButton\0"
};

void JobCancelButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData JobCancelButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject JobCancelButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_JobCancelButton,
      qt_meta_data_JobCancelButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JobCancelButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JobCancelButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JobCancelButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JobCancelButton))
        return static_cast<void*>(const_cast< JobCancelButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int JobCancelButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ProcessManagerWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   49,   56,   56, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   56,   56,   56, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProcessManagerWidget[] = {
    "ProcessManagerWidget\0cancelJobRequested(QString)\0"
    "_jobId\0\0cancelButtonPressed()\0"
};

void ProcessManagerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProcessManagerWidget *_t = static_cast<ProcessManagerWidget *>(_o);
        switch (_id) {
        case 0: _t->cancelJobRequested((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->cancelButtonPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ProcessManagerWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProcessManagerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ProcessManagerWidget,
      qt_meta_data_ProcessManagerWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProcessManagerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProcessManagerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProcessManagerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessManagerWidget))
        return static_cast<void*>(const_cast< ProcessManagerWidget*>(this));
    if (!strcmp(_clname, "Ui::ProcessManagerWidget"))
        return static_cast< Ui::ProcessManagerWidget*>(const_cast< ProcessManagerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ProcessManagerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ProcessManagerWidget::cancelJobRequested(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

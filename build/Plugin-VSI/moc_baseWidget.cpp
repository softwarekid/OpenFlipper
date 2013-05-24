/****************************************************************************
** Meta object code from reading C++ file 'baseWidget.hh'
**
** Created: Sat May 18 02:59:50 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-VSI/baseWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VSI__BaseWidget[] = {

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
      16,   44,   50,   50, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   50,   50,   50, 0x0a,
      65,   50,   50,   50, 0x0a,
      80,   91,  100,   50, 0x0a,
     105,   50,  100,   50, 0x2a,
     112,   50,  100,   50, 0x0a,
     121,   50,   50,   50, 0x0a,
     128,   50,   50,   50, 0x0a,
     138,   50,   50,   50, 0x0a,
     155,  181,   50,   50, 0x0a,
     188,   50,   50,   50, 0x0a,
     199,  181,   50,   50, 0x0a,
     224,  181,   50,   50, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VSI__BaseWidget[] = {
    "VSI::BaseWidget\0codeToScriptEditor(QString)\0"
    "_code\0\0executeCode()\0codeToScript()\0"
    "save(bool)\0_newName\0bool\0save()\0"
    "saveAs()\0load()\0newFile()\0contentChanged()\0"
    "pushScene(GraphicsScene*)\0_scene\0"
    "popScene()\0addScene(GraphicsScene*)\0"
    "removeScene(GraphicsScene*)\0"
};

void VSI::BaseWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BaseWidget *_t = static_cast<BaseWidget *>(_o);
        switch (_id) {
        case 0: _t->codeToScriptEditor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->executeCode(); break;
        case 2: _t->codeToScript(); break;
        case 3: { bool _r = _t->save((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->load(); break;
        case 7: _t->newFile(); break;
        case 8: _t->contentChanged(); break;
        case 9: _t->pushScene((*reinterpret_cast< GraphicsScene*(*)>(_a[1]))); break;
        case 10: _t->popScene(); break;
        case 11: _t->addScene((*reinterpret_cast< GraphicsScene*(*)>(_a[1]))); break;
        case 12: _t->removeScene((*reinterpret_cast< GraphicsScene*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VSI::BaseWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VSI::BaseWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VSI__BaseWidget,
      qt_meta_data_VSI__BaseWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VSI::BaseWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VSI::BaseWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VSI::BaseWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VSI__BaseWidget))
        return static_cast<void*>(const_cast< BaseWidget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int VSI::BaseWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void VSI::BaseWidget::codeToScriptEditor(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

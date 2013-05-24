/****************************************************************************
** Meta object code from reading C++ file 'QtSlideWindow.hh'
**
** Created: Sat May 18 02:51:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/glWidget/QtSlideWindow.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtSlideWindow.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtSlideWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   30,   30,   30, 0x08,
      31,   30,   30,   30, 0x08,
      46,   30,   30,   30, 0x08,
      64,   30,   30,   30, 0x08,
      74,   30,   30,   30, 0x08,
      86,   30,   30,   30, 0x08,
     106,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QtSlideWindow[] = {
    "QtSlideWindow\0detachPressed()\0\0"
    "dialogClosed()\0autohidePressed()\0"
    "slideUp()\0slideDown()\0animationFinished()\0"
    "startSlideDownAnimation()\0"
};

void QtSlideWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtSlideWindow *_t = static_cast<QtSlideWindow *>(_o);
        switch (_id) {
        case 0: _t->detachPressed(); break;
        case 1: _t->dialogClosed(); break;
        case 2: _t->autohidePressed(); break;
        case 3: _t->slideUp(); break;
        case 4: _t->slideDown(); break;
        case 5: _t->animationFinished(); break;
        case 6: _t->startSlideDownAnimation(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QtSlideWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtSlideWindow::staticMetaObject = {
    { &QGraphicsProxyWidget::staticMetaObject, qt_meta_stringdata_QtSlideWindow,
      qt_meta_data_QtSlideWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtSlideWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtSlideWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtSlideWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtSlideWindow))
        return static_cast<void*>(const_cast< QtSlideWindow*>(this));
    return QGraphicsProxyWidget::qt_metacast(_clname);
}

int QtSlideWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsProxyWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

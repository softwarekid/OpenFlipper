/****************************************************************************
** Meta object code from reading C++ file 'helpWidget.hh'
**
** Created: Sat May 18 02:52:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/helpWidget/helpWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helpWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HelpWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   25,   25,   25, 0x08,
      26,   25,   25,   25, 0x08,
      35,   25,   25,   25, 0x08,
      47,   25,   25,   25, 0x08,
      56,   25,   25,   25, 0x08,
      75,   95,   25,   25, 0x08,
     100,   95,   25,   25, 0x08,
     119,   95,   25,   25, 0x08,
     139,  156,   25,   25, 0x08,
     162,  175,   25,   25, 0x08,
     179,  211,   25,   25, 0x08,
     217,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_HelpWidget[] = {
    "HelpWidget\0startSearch()\0\0goBack()\0"
    "goForward()\0goHome()\0showSearchWidget()\0"
    "linkActivated(QUrl)\0_url\0activateLink(QUrl)\0"
    "showFoundSite(QUrl)\0showResults(int)\0"
    "_hits\0update(QUrl)\0url\0"
    "openFoundSite(QListWidgetItem*)\0_item\0"
    "updateButtons()\0"
};

void HelpWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HelpWidget *_t = static_cast<HelpWidget *>(_o);
        switch (_id) {
        case 0: _t->startSearch(); break;
        case 1: _t->goBack(); break;
        case 2: _t->goForward(); break;
        case 3: _t->goHome(); break;
        case 4: _t->showSearchWidget(); break;
        case 5: _t->linkActivated((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 6: _t->activateLink((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 7: _t->showFoundSite((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 8: _t->showResults((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->update((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 10: _t->openFoundSite((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->updateButtons(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HelpWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HelpWidget::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HelpWidget,
      qt_meta_data_HelpWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HelpWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HelpWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HelpWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HelpWidget))
        return static_cast<void*>(const_cast< HelpWidget*>(this));
    if (!strcmp(_clname, "Ui::HelpWidget"))
        return static_cast< Ui::HelpWidget*>(const_cast< HelpWidget*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HelpWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

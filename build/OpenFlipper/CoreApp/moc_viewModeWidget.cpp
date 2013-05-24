/****************************************************************************
** Meta object code from reading C++ file 'viewModeWidget.hh'
**
** Created: Sat May 18 02:52:52 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/viewModeWidget/viewModeWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewModeWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_viewModeWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   71,  117,  117, 0x05,
     118,  177,  117,  117, 0x05,
     231,  251,  117,  117, 0x05,

 // slots: signature, parameters, type, tag, flags
     257,  282,  117,  117, 0x08,
     288,  317,  117,  117, 0x08,
     321,  117,  117,  117, 0x08,
     338,  117,  117,  117, 0x08,
     353,  117,  117,  117, 0x08,
     367,  395,  117,  117, 0x08,
     400,  117,  117,  117, 0x08,
     414,  117,  117,  117, 0x08,
     434,  395,  117,  117, 0x08,
     469,  395,  117,  117, 0x08,
     509,  395,  117,  117, 0x08,
     544,  395,  117,  117, 0x08,
     584,  395,  117,  117, 0x08,
     623,  395,  117,  117, 0x08,
     667,  117,  117,  117, 0x08,
     691,  117,  117,  117, 0x08,
     714,  117,  117,  117, 0x08,
     738,  117,  117,  117, 0x08,
     761,  117,  117,  117, 0x08,
     781,  117,  117,  117, 0x08,
     803,  117,  117,  117, 0x08,
     831,  117,  117,  117, 0x08,
     858,  117,  117,  117, 0x08,
     882,  117,  117,  117, 0x08,
     908,  117,  117,  117, 0x08,
     925,  117,  117,  117, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_viewModeWidget[] = {
    "viewModeWidget\0"
    "changeView(QString,QStringList,QStringList,QStringList)\0"
    "_mode,_toolboxWidgets,_toolbars,_contextmenus\0"
    "\0saveMode(QString,bool,QStringList,QStringList,QStringList)\0"
    "_name,_custom,_toolboxWidgets,_toolbars,_contextmenus\0"
    "removeMode(QString)\0_name\0"
    "slotModeChanged(QString)\0_mode\0"
    "slotModeClicked(QModelIndex)\0_id\0"
    "slotRemoveMode()\0slotCopyMode()\0"
    "slotAddMode()\0slotModeContextMenu(QPoint)\0"
    "_pos\0slotSetIcon()\0slotSetAllWidgets()\0"
    "slotUsedToolbarContextMenu(QPoint)\0"
    "slotAvailableToolbarContextMenu(QPoint)\0"
    "slotUsedToolboxContextMenu(QPoint)\0"
    "slotAvailableToolboxContextMenu(QPoint)\0"
    "slotUsedContextMenuContextMenu(QPoint)\0"
    "slotAvailableContextMenuContextMenu(QPoint)\0"
    "slotRightArrowToolbar()\0slotLeftArrowToolbar()\0"
    "slotRightArrowToolbox()\0slotLeftArrowToolbox()\0"
    "slotMoveToolboxUp()\0slotMoveToolboxDown()\0"
    "slotRightArrowContextMenu()\0"
    "slotLeftArrowContextMenu()\0"
    "slotMoveContextMenuUp()\0"
    "slotMoveContextMenuDown()\0slotChangeView()\0"
    "slotSaveMode()\0"
};

void viewModeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        viewModeWidget *_t = static_cast<viewModeWidget *>(_o);
        switch (_id) {
        case 0: _t->changeView((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        case 1: _t->saveMode((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4])),(*reinterpret_cast< QStringList(*)>(_a[5]))); break;
        case 2: _t->removeMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotModeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->slotModeClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->slotRemoveMode(); break;
        case 6: _t->slotCopyMode(); break;
        case 7: _t->slotAddMode(); break;
        case 8: _t->slotModeContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 9: _t->slotSetIcon(); break;
        case 10: _t->slotSetAllWidgets(); break;
        case 11: _t->slotUsedToolbarContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->slotAvailableToolbarContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->slotUsedToolboxContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->slotAvailableToolboxContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: _t->slotUsedContextMenuContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 16: _t->slotAvailableContextMenuContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 17: _t->slotRightArrowToolbar(); break;
        case 18: _t->slotLeftArrowToolbar(); break;
        case 19: _t->slotRightArrowToolbox(); break;
        case 20: _t->slotLeftArrowToolbox(); break;
        case 21: _t->slotMoveToolboxUp(); break;
        case 22: _t->slotMoveToolboxDown(); break;
        case 23: _t->slotRightArrowContextMenu(); break;
        case 24: _t->slotLeftArrowContextMenu(); break;
        case 25: _t->slotMoveContextMenuUp(); break;
        case 26: _t->slotMoveContextMenuDown(); break;
        case 27: _t->slotChangeView(); break;
        case 28: _t->slotSaveMode(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData viewModeWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject viewModeWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_viewModeWidget,
      qt_meta_data_viewModeWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &viewModeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *viewModeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *viewModeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_viewModeWidget))
        return static_cast<void*>(const_cast< viewModeWidget*>(this));
    if (!strcmp(_clname, "Ui::viewMode"))
        return static_cast< Ui::viewMode*>(const_cast< viewModeWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int viewModeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void viewModeWidget::changeView(QString _t1, QStringList _t2, QStringList _t3, QStringList _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void viewModeWidget::saveMode(QString _t1, bool _t2, QStringList _t3, QStringList _t4, QStringList _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void viewModeWidget::removeMode(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

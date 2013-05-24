/****************************************************************************
** Meta object code from reading C++ file 'optionsWidget.hh'
**
** Created: Sat May 18 02:52:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../OpenFlipper/widgets/optionsWidget/optionsWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionsWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OptionsWidget[] = {

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
      14,   29,   29,   29, 0x05,
      30,   29,   29,   29, 0x05,
      44,   98,   29,   29, 0x05,

 // slots: signature, parameters, type, tag, flags
     136,   29,   29,   29, 0x08,
     145,   29,   29,   29, 0x08,
     157,   29,   29,   29, 0x08,
     170,   29,   29,   29, 0x08,
     189,   29,   29,   29, 0x08,
     206,   29,   29,   29, 0x08,
     227,   29,   29,   29, 0x08,
     245,  299,   29,   29, 0x08,
     316,  359,   29,   29, 0x08,
     369,   29,   29,   29, 0x08,
     386,  417,   29,   29, 0x08,
     429,   29,   29,   29, 0x08,
     449,  475,   29,   29, 0x08,
     480,  520,   29,   29, 0x08,
     526,  553,   29,   29, 0x08,
     560,   29,   29,   29, 0x08,
     582,  613,   29,   29, 0x08,
     623,   29,   29,   29, 0x28,
     651,   29,   29,   29, 0x08,
     671,   29,   29,   29, 0x08,
     686,  716,   29,   29, 0x08,
     732,  772,   29,   29, 0x08,
     787,  819,   29,   29, 0x08,
     840,   29,   29,   29, 0x08,
     857,   29,   29,   29, 0x08,
     875,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OptionsWidget[] = {
    "OptionsWidget\0applyOptions()\0\0"
    "saveOptions()\0"
    "addKeyMapping(int,Qt::KeyboardModifiers,QObject*,int)\0"
    "_key,_modifiers,_plugin,_keyBindingID\0"
    "slotOk()\0slotApply()\0slotCancel()\0"
    "slotCheckUpdates()\0slotGetUpdates()\0"
    "getBackgroundColor()\0getDefaultColor()\0"
    "keyTreeItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)\0"
    "current,previous\0"
    "keyTreeDoubleClicked(QTreeWidgetItem*,int)\0"
    "_item,col\0updateShortcut()\0"
    "slotShowPluginOptions(QString)\0"
    "_pluginName\0restoreKeyPresets()\0"
    "updateViewerSettings(int)\0_row\0"
    "viewerSettingsChanged(QListWidgetItem*)\0"
    "_item\0viewerSettingsChanged(int)\0"
    "_index\0switchStackedWidget()\0"
    "slotPreviewStereoSettings(int)\0_tmpParam\0"
    "slotPreviewStereoSettings()\0"
    "slotClearSettings()\0slotClearINI()\0"
    "httpRequestFinished(int,bool)\0"
    "requestId,error\0readResponseHeader(QHttpResponseHeader)\0"
    "responseHeader\0updateDataReadProgress(int,int)\0"
    "bytesRead,totalBytes\0cancelDownload()\0"
    "updateComponent()\0slotTranslationIndexChanged(int)\0"
};

void OptionsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OptionsWidget *_t = static_cast<OptionsWidget *>(_o);
        switch (_id) {
        case 0: _t->applyOptions(); break;
        case 1: _t->saveOptions(); break;
        case 2: _t->addKeyMapping((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::KeyboardModifiers(*)>(_a[2])),(*reinterpret_cast< QObject*(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->slotOk(); break;
        case 4: _t->slotApply(); break;
        case 5: _t->slotCancel(); break;
        case 6: _t->slotCheckUpdates(); break;
        case 7: _t->slotGetUpdates(); break;
        case 8: _t->getBackgroundColor(); break;
        case 9: _t->getDefaultColor(); break;
        case 10: _t->keyTreeItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 11: _t->keyTreeDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->updateShortcut(); break;
        case 13: _t->slotShowPluginOptions((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->restoreKeyPresets(); break;
        case 15: _t->updateViewerSettings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->viewerSettingsChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 17: _t->viewerSettingsChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->switchStackedWidget(); break;
        case 19: _t->slotPreviewStereoSettings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->slotPreviewStereoSettings(); break;
        case 21: _t->slotClearSettings(); break;
        case 22: _t->slotClearINI(); break;
        case 23: _t->httpRequestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: _t->readResponseHeader((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 25: _t->updateDataReadProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->cancelDownload(); break;
        case 27: _t->updateComponent(); break;
        case 28: _t->slotTranslationIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OptionsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OptionsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OptionsWidget,
      qt_meta_data_OptionsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OptionsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OptionsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OptionsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsWidget))
        return static_cast<void*>(const_cast< OptionsWidget*>(this));
    if (!strcmp(_clname, "Ui::OptionsWidget"))
        return static_cast< Ui::OptionsWidget*>(const_cast< OptionsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OptionsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void OptionsWidget::applyOptions()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void OptionsWidget::saveOptions()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void OptionsWidget::addKeyMapping(int _t1, Qt::KeyboardModifiers _t2, QObject * _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'textureProperties.hh'
**
** Created: Sat May 18 02:59:27 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Plugin-TextureControl/textureProperties.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textureProperties.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_texturePropertiesWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   66,   92,   92, 0x05,
      93,  144,   92,   92, 0x05,

 // slots: signature, parameters, type, tag, flags
     164,  207,   92,   92, 0x08,
     221,  207,   92,   92, 0x08,
     258,  297,   92,   92, 0x08,
     305,  335,   92,   92, 0x08,
     342,   92,   92,   92, 0x28,
     366,   92,   92,   92, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_texturePropertiesWidget[] = {
    "texturePropertiesWidget\0"
    "applyProperties(TextureData*,QString,int)\0"
    "_texData,_textureName,_id\0\0"
    "getCoordinates1D(QString,int,std::vector<double>&)\0"
    "_textureName,_id,_x\0"
    "textureAboutToChange(QTreeWidgetItem*,int)\0"
    "_item,_column\0textureChanged(QTreeWidgetItem*,int)\0"
    "slotButtonBoxClicked(QAbstractButton*)\0"
    "_button\0slotPropertiesChanged(double)\0"
    "_value\0slotPropertiesChanged()\0"
    "slotChangeImage()\0"
};

void texturePropertiesWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        texturePropertiesWidget *_t = static_cast<texturePropertiesWidget *>(_o);
        switch (_id) {
        case 0: _t->applyProperties((*reinterpret_cast< TextureData*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->getCoordinates1D((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< std::vector<double>(*)>(_a[3]))); break;
        case 2: _t->textureAboutToChange((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->textureChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->slotButtonBoxClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 5: _t->slotPropertiesChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slotPropertiesChanged(); break;
        case 7: _t->slotChangeImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData texturePropertiesWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject texturePropertiesWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_texturePropertiesWidget,
      qt_meta_data_texturePropertiesWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &texturePropertiesWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *texturePropertiesWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *texturePropertiesWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_texturePropertiesWidget))
        return static_cast<void*>(const_cast< texturePropertiesWidget*>(this));
    if (!strcmp(_clname, "Ui::Dialog"))
        return static_cast< Ui::Dialog*>(const_cast< texturePropertiesWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int texturePropertiesWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void texturePropertiesWidget::applyProperties(TextureData * _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void texturePropertiesWidget::getCoordinates1D(QString _t1, int _t2, std::vector<double> & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

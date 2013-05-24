/****************************************************************************
** Meta object code from reading C++ file 'QtMaterialDialog.hh'
**
** Created: Sat May 18 02:49:51 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ACG/QtWidgets/QtMaterialDialog.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtMaterialDialog.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ACG__QtWidgets__QtMaterialDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   79,   85,   85, 0x05,

 // slots: signature, parameters, type, tag, flags
      86,  110,   85,   85, 0x08,
     120,  110,   85,   85, 0x08,
     147,  110,   85,   85, 0x08,
     174,  110,   85,   85, 0x08,
     202,  110,   85,   85, 0x08,
     229,  246,   85,   85, 0x08,
     251,  246,   85,   85, 0x08,
     272,  246,   85,   85, 0x08,
     293,  317,   85,   85, 0x08,
     320,  317,   85,   85, 0x08,
     343,  317,   85,   85, 0x08,
     371,  317,   85,   85, 0x08,
     393,  246,   85,   85, 0x08,
     415,  317,   85,   85, 0x08,
     436,  466,   85,   85, 0x08,
     472,  466,   85,   85, 0x08,
     502,  317,   85,   85, 0x08,
     528,  317,   85,   85, 0x08,
     554,  573,   85,   85, 0x08,
     580,   85,   85,   85, 0x08,
     597,  617,   85,   85, 0x08,
     619,  638,  644,   85, 0x08,
     652,   85,   85,   85, 0x08,
     667,   85,   85,   85, 0x08,
     681,   85,   85,   85, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ACG__QtWidgets__QtMaterialDialog[] = {
    "ACG::QtWidgets::QtMaterialDialog\0"
    "signalNodeChanged(ACG::SceneGraph::BaseNode*)\0"
    "_node\0\0changeBaseColor(QColor)\0_newColor\0"
    "changeAmbientColor(QColor)\0"
    "changeDiffuseColor(QColor)\0"
    "changeSpecularColor(QColor)\0"
    "changeOverlayColor(QColor)\0changeShine(int)\0"
    "_new\0changePointSize(int)\0"
    "changeLineWidth(int)\0changeRoundPoints(bool)\0"
    "_b\0changeLineSmooth(bool)\0"
    "changeBackfaceCulling(bool)\0"
    "changeAlphaTest(bool)\0changeAlphaValue(int)\0"
    "changeBlending(bool)\0changeBlendingParam1(QString)\0"
    "_name\0changeBlendingParam2(QString)\0"
    "changeColorMaterial(bool)\0"
    "changeMultiSampling(bool)\0changeActive(bool)\0"
    "toggle\0enableProperty()\0enableProperty(int)\0"
    "i\0paramToStr(GLenum)\0param\0QString\0"
    "applyChanges()\0undoChanges()\0reject()\0"
};

void ACG::QtWidgets::QtMaterialDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtMaterialDialog *_t = static_cast<QtMaterialDialog *>(_o);
        switch (_id) {
        case 0: _t->signalNodeChanged((*reinterpret_cast< ACG::SceneGraph::BaseNode*(*)>(_a[1]))); break;
        case 1: _t->changeBaseColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->changeAmbientColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->changeDiffuseColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->changeSpecularColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 5: _t->changeOverlayColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 6: _t->changeShine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->changePointSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->changeLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->changeRoundPoints((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->changeLineSmooth((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->changeBackfaceCulling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->changeAlphaTest((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->changeAlphaValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->changeBlending((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->changeBlendingParam1((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->changeBlendingParam2((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->changeColorMaterial((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->changeMultiSampling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->changeActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->enableProperty(); break;
        case 21: _t->enableProperty((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: { QString _r = _t->paramToStr((*reinterpret_cast< GLenum(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: _t->applyChanges(); break;
        case 24: _t->undoChanges(); break;
        case 25: _t->reject(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ACG::QtWidgets::QtMaterialDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ACG::QtWidgets::QtMaterialDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ACG__QtWidgets__QtMaterialDialog,
      qt_meta_data_ACG__QtWidgets__QtMaterialDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ACG::QtWidgets::QtMaterialDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ACG::QtWidgets::QtMaterialDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ACG::QtWidgets::QtMaterialDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ACG__QtWidgets__QtMaterialDialog))
        return static_cast<void*>(const_cast< QtMaterialDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ACG::QtWidgets::QtMaterialDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void ACG::QtWidgets::QtMaterialDialog::signalNodeChanged(ACG::SceneGraph::BaseNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

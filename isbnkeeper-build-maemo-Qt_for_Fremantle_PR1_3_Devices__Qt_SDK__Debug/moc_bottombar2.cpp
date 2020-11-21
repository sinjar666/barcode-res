/****************************************************************************
** Meta object code from reading C++ file 'bottombar2.h'
**
** Created: Fri Feb 24 21:15:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/BookList/bottombar2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottombar2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BottomBar2[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,
      53,   45,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      70,   11,   11,   11, 0x0a,
      86,   11,   11,   11, 0x0a,
     102,   45,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BottomBar2[] = {
    "BottomBar2\0\0activateCamera()\0"
    "requestDelete()\0checked\0sendToggle(bool)\0"
    "cameraPressed()\0deletePressed()\0"
    "markToggled(bool)\0"
};

const QMetaObject BottomBar2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BottomBar2,
      qt_meta_data_BottomBar2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BottomBar2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BottomBar2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BottomBar2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BottomBar2))
        return static_cast<void*>(const_cast< BottomBar2*>(this));
    return QWidget::qt_metacast(_clname);
}

int BottomBar2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activateCamera(); break;
        case 1: requestDelete(); break;
        case 2: sendToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: cameraPressed(); break;
        case 4: deletePressed(); break;
        case 5: markToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BottomBar2::activateCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void BottomBar2::requestDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void BottomBar2::sendToggle(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

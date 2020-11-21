/****************************************************************************
** Meta object code from reading C++ file 'filterdialog.h'
**
** Created: Fri Feb 24 21:15:37 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/Homescreen/filterdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filterdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FilterDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x0a,
      38,   14,   13,   13, 0x0a,
      57,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FilterDialog[] = {
    "FilterDialog\0\0state\0titleChecked(int)\0"
    "authorChecked(int)\0pubChecked(int)\0"
};

const QMetaObject FilterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FilterDialog,
      qt_meta_data_FilterDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FilterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FilterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FilterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FilterDialog))
        return static_cast<void*>(const_cast< FilterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int FilterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: titleChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: authorChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: pubChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

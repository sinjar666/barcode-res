/****************************************************************************
** Meta object code from reading C++ file 'isbn.h'
**
** Created: Fri Feb 24 21:15:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/xml/isbn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'isbn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Isbn[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,
      18,    5,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,    5,    5,    5, 0x0a,
      47,   43,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Isbn[] = {
    "Isbn\0\0img_error()\0load_complete()\0"
    "result()\0rep\0reply(QNetworkReply*)\0"
};

const QMetaObject Isbn::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Isbn,
      qt_meta_data_Isbn, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Isbn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Isbn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Isbn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Isbn))
        return static_cast<void*>(const_cast< Isbn*>(this));
    return QObject::qt_metacast(_clname);
}

int Isbn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: img_error(); break;
        case 1: load_complete(); break;
        case 2: result(); break;
        case 3: reply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Isbn::img_error()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Isbn::load_complete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE

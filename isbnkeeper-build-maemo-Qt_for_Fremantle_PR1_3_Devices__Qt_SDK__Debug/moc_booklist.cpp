/****************************************************************************
** Meta object code from reading C++ file 'booklist.h'
**
** Created: Fri Feb 24 21:15:48 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/BookList/booklist.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'booklist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Booklist[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,    9,    9,    9, 0x0a,
      53,    9,    9,    9, 0x0a,
      76,   69,    9,    9, 0x0a,
      99,   94,    9,    9, 0x0a,
     123,   94,    9,    9, 0x0a,
     150,    9,    9,    9, 0x0a,
     169,  164,    9,    9, 0x0a,
     188,    9,    9,    9, 0x0a,
     205,    9,    9,    9, 0x0a,
     223,    9,    9,    9, 0x0a,
     246,    9,    9,    9, 0x0a,
     266,    9,    9,    9, 0x0a,
     288,    9,    9,    9, 0x0a,
     311,  307,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Booklist[] = {
    "Booklist\0\0path\0startCamera(QString)\0"
    "activateCamera()\0deletepressed()\0"
    "status\0markpressed(bool)\0name\0"
    "double_clicked(QString)\0"
    "selected_item(QStringList)\0list_update()\0"
    "isbn\0fetchInfo(QString)\0setImageFailed()\0"
    "setImageFailed2()\0displayInfoAfterLoad()\0"
    "cancelDisplayInfo()\0displayInfoFromFile()\0"
    "cancelFetchImage()\0act\0"
    "displaydescription(QAction*)\0"
};

const QMetaObject Booklist::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Booklist,
      qt_meta_data_Booklist, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Booklist::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Booklist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Booklist::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Booklist))
        return static_cast<void*>(const_cast< Booklist*>(this));
    return QWidget::qt_metacast(_clname);
}

int Booklist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startCamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: activateCamera(); break;
        case 2: deletepressed(); break;
        case 3: markpressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: double_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: selected_item((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: list_update(); break;
        case 7: fetchInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: setImageFailed(); break;
        case 9: setImageFailed2(); break;
        case 10: displayInfoAfterLoad(); break;
        case 11: cancelDisplayInfo(); break;
        case 12: displayInfoFromFile(); break;
        case 13: cancelFetchImage(); break;
        case 14: displaydescription((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Booklist::startCamera(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
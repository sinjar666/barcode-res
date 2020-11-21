/****************************************************************************
** Meta object code from reading C++ file 'homescreen.h'
**
** Created: Fri Mar 2 20:53:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/Homescreen/homescreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HomeScreen[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      38,   12,   11,   11, 0x05,
      73,   63,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   11,   11,   11, 0x0a,
     131,  123,   11,   11, 0x0a,
     166,  157,   11,   11, 0x0a,
     205,  198,   11,   11, 0x0a,
     229,  225,   11,   11, 0x0a,
     252,   11,   11,   11, 0x0a,
     274,  268,   11,   11, 0x0a,
     292,   11,   11,   11, 0x0a,
     305,   11,   11,   11, 0x0a,
     324,  319,   11,   11, 0x0a,
     343,   11,   11,   11, 0x0a,
     366,   11,   11,   11, 0x0a,
     386,   11,   11,   11, 0x0a,
     403,   11,   11,   11, 0x0a,
     421,   11,   11,   11, 0x0a,
     443,   11,   11,   11, 0x0a,
     469,  462,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HomeScreen[] = {
    "HomeScreen\0\0path\0startCamera(QString)\0"
    "requestOpenFile(QString)\0path,isbn\0"
    "requestShowBook(QString,QString)\0"
    "activateCamera()\0checked\0"
    "toggleSelectionMode(bool)\0newFiles\0"
    "changeSelectedList(QStringList)\0status\0"
    "setSearchMode(bool)\0key\0performSearch(QString)\0"
    "performDelete()\0fname\0openFile(QString)\0"
    "openOthers()\0sendRefresh()\0isbn\0"
    "fetchInfo(QString)\0displayInfoAfterLoad()\0"
    "cancelDisplayInfo()\0setImageFailed()\0"
    "setImageFailed2()\0displayInfoFromFile()\0"
    "cancelFetchImage()\0action\0"
    "menuTriggered(QAction*)\0"
};

const QMetaObject HomeScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HomeScreen,
      qt_meta_data_HomeScreen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HomeScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HomeScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HomeScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HomeScreen))
        return static_cast<void*>(const_cast< HomeScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int HomeScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startCamera((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: requestOpenFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: requestShowBook((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: activateCamera(); break;
        case 4: toggleSelectionMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: changeSelectedList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: setSearchMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: performSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: performDelete(); break;
        case 9: openFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: openOthers(); break;
        case 11: sendRefresh(); break;
        case 12: fetchInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: displayInfoAfterLoad(); break;
        case 14: cancelDisplayInfo(); break;
        case 15: setImageFailed(); break;
        case 16: setImageFailed2(); break;
        case 17: displayInfoFromFile(); break;
        case 18: cancelFetchImage(); break;
        case 19: menuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void HomeScreen::startCamera(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HomeScreen::requestOpenFile(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HomeScreen::requestShowBook(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

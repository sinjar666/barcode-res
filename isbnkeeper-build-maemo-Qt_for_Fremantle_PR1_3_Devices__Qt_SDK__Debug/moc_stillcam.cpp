/****************************************************************************
** Meta object code from reading C++ file 'stillcam.h'
**
** Created: Fri Feb 24 21:15:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/stillcam.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stillcam.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StillCam[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      21,    9,    9,    9, 0x05,
      39,   34,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,    9,    9,    9, 0x08,
      89,   69,    9,    9, 0x0a,
     127,   69,    9,    9, 0x0a,
     161,   69,    9,    9, 0x0a,
     198,  194,    9,    9, 0x0a,
     238,  232,    9,    9, 0x0a,
     269,  263,    9,    9, 0x0a,
     299,    9,    9,    9, 0x0a,
     315,    9,    9,    9, 0x0a,
     343,  330,    9,    9, 0x0a,
     383,  330,    9,    9, 0x0a,
     440,  421,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StillCam[] = {
    "StillCam\0\0pictDone()\0imageSaved()\0"
    "isbn\0gotISBN(QString)\0getPicture()\0"
    "num_updates,updates\0"
    "shutter_released(int,QList<Property>)\0"
    "focus_locked(int,QList<Property>)\0"
    "cam_shutter(int,QList<Property>)\0msg\0"
    "displayStateChanged(QDBusMessage)\0"
    "state\0setDisplayState(QString)\0error\0"
    "displayStateError(QDBusError)\0"
    "doBarcodeRead()\0checkBarcode()\0"
    "manager,data\0startCapture(GDigicamManager*,gpointer)\0"
    "endCapture(GDigicamManager*,gpointer)\0"
    "manager,fname,data\0"
    "captureDone(GDigicamManager*,GString*,gpointer)\0"
};

const QMetaObject StillCam::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StillCam,
      qt_meta_data_StillCam, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StillCam::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StillCam::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StillCam::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StillCam))
        return static_cast<void*>(const_cast< StillCam*>(this));
    return QWidget::qt_metacast(_clname);
}

int StillCam::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pictDone(); break;
        case 1: imageSaved(); break;
        case 2: gotISBN((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: getPicture(); break;
        case 4: shutter_released((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<Property>(*)>(_a[2]))); break;
        case 5: focus_locked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<Property>(*)>(_a[2]))); break;
        case 6: cam_shutter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<Property>(*)>(_a[2]))); break;
        case 7: displayStateChanged((*reinterpret_cast< const QDBusMessage(*)>(_a[1]))); break;
        case 8: setDisplayState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: displayStateError((*reinterpret_cast< const QDBusError(*)>(_a[1]))); break;
        case 10: doBarcodeRead(); break;
        case 11: checkBarcode(); break;
        case 12: startCapture((*reinterpret_cast< GDigicamManager*(*)>(_a[1])),(*reinterpret_cast< gpointer(*)>(_a[2]))); break;
        case 13: endCapture((*reinterpret_cast< GDigicamManager*(*)>(_a[1])),(*reinterpret_cast< gpointer(*)>(_a[2]))); break;
        case 14: captureDone((*reinterpret_cast< GDigicamManager*(*)>(_a[1])),(*reinterpret_cast< GString*(*)>(_a[2])),(*reinterpret_cast< gpointer(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void StillCam::pictDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void StillCam::imageSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void StillCam::gotISBN(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'bottombar.h'
**
** Created: Fri Mar 2 20:53:25 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../isbnkeeper/Homescreen/bottombar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bottombar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BottomBar[] = {

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
      11,   10,   10,   10, 0x05,
      28,   10,   10,   10, 0x05,
      44,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   10,   10,   10, 0x0a,
      77,   10,   10,   10, 0x0a,
      97,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BottomBar[] = {
    "BottomBar\0\0activateCamera()\0requestDelete()\0"
    "requestRefresh()\0cameraPressed()\0"
    "showNewFileDialog()\0deletePressed()\0"
};

const QMetaObject BottomBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BottomBar,
      qt_meta_data_BottomBar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BottomBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BottomBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BottomBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BottomBar))
        return static_cast<void*>(const_cast< BottomBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int BottomBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activateCamera(); break;
        case 1: requestDelete(); break;
        case 2: requestRefresh(); break;
        case 3: cameraPressed(); break;
        case 4: showNewFileDialog(); break;
        case 5: deletePressed(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BottomBar::activateCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void BottomBar::requestDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void BottomBar::requestRefresh()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

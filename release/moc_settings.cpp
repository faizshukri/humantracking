/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created: Mon Dec 26 00:14:30 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../settings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Settings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x09,
      28,    9,    9,    9, 0x09,
      43,    9,    9,    9, 0x09,
      56,    9,    9,    9, 0x09,
      71,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Settings[] = {
    "Settings\0\0saveSetting(bool)\0resetDefault()\0"
    "browseSnap()\0browseExport()\0"
    "browseExtractPoint()\0"
};

const QMetaObject Settings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Settings,
      qt_meta_data_Settings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Settings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Settings))
        return static_cast<void*>(const_cast< Settings*>(this));
    return QDialog::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: saveSetting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: resetDefault(); break;
        case 2: browseSnap(); break;
        case 3: browseExport(); break;
        case 4: browseExtractPoint(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

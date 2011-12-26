/****************************************************************************
** Meta object code from reading C++ file 'processthread.h'
**
** Created: Mon Dec 26 04:31:56 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_processThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      35,   33,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_processThread[] = {
    "processThread\0\0currentFrame(int)\0,\0"
    "currentFrame(int,Mat)\0setValueJ(int)\0"
};

const QMetaObject processThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_processThread,
      qt_meta_data_processThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &processThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *processThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *processThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_processThread))
        return static_cast<void*>(const_cast< processThread*>(this));
    return QThread::qt_metacast(_clname);
}

int processThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: currentFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 2: setValueJ((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void processThread::currentFrame(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void processThread::currentFrame(int _t1, Mat _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

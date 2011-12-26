/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Dec 26 04:31:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      42,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   11,   11,   11, 0x09,
      74,   11,   11,   11, 0x09,
      98,   11,   11,   11, 0x09,
     115,   11,   11,   11, 0x09,
     133,   11,   11,   11, 0x09,
     148,   11,   11,   11, 0x09,
     167,   11,   11,   11, 0x09,
     184,   11,   11,   11, 0x09,
     205,   11,   11,   11, 0x09,
     227,   11,   11,   11, 0x09,
     244,   11,   11,   11, 0x09,
     260,   11,   11,   11, 0x09,
     276,  271,   11,   11, 0x09,
     299,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0,\0displayCurProgress(int,int)\0"
    "setCurPos(int)\0toggleFlip(bool)\0"
    "toggleDetectHuman(bool)\0toggleEdge(bool)\0"
    "togglePlayPause()\0setThresh(int)\0"
    "setThresh(QString)\0setTimeline(int)\0"
    "toggleCaptureFrame()\0toggleCaptureFrames()\0"
    "toggleSurf(bool)\0toggleHog(bool)\0"
    "loadFile()\0,img\0displayResult(int,Mat)\0"
    "initEffectAndGui()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayCurProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: setCurPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: toggleFlip((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: toggleDetectHuman((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: toggleEdge((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: togglePlayPause(); break;
        case 6: setThresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setThresh((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: setTimeline((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: toggleCaptureFrame(); break;
        case 10: toggleCaptureFrames(); break;
        case 11: toggleSurf((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: toggleHog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: loadFile(); break;
        case 14: displayResult((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Mat(*)>(_a[2]))); break;
        case 15: initEffectAndGui(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::displayCurProgress(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::setCurPos(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

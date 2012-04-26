/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created: Wed Apr 25 23:30:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Game[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    6,    5,    5, 0x05,
      35,   29,    5,    5, 0x05,
      57,   52,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,    5,    5,    5, 0x0a,
      85,    5,    5,    5, 0x0a,
      97,    5,    5,    5, 0x0a,
     108,    5,    5,    5, 0x0a,
     120,    5,    5,    5, 0x0a,
     137,    5,    5,    5, 0x0a,
     150,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Game[] = {
    "Game\0\0score\0scoreChange(int)\0level\0"
    "levelChange(int)\0life\0lifeChange(int)\0"
    "startGame()\0pauseGame()\0stopGame()\0"
    "resetGame()\0nextLevelReset()\0levelReset()\0"
    "victoryGame()\0"
};

const QMetaObject Game::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Game,
      qt_meta_data_Game, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Game::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Game))
        return static_cast<void*>(const_cast< Game*>(this));
    return QWidget::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scoreChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: levelChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: lifeChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: startGame(); break;
        case 4: pauseGame(); break;
        case 5: stopGame(); break;
        case 6: resetGame(); break;
        case 7: nextLevelReset(); break;
        case 8: levelReset(); break;
        case 9: victoryGame(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Game::scoreChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Game::levelChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Game::lifeChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

#ifndef MONSTERBULL_H
#define MONSTERBULL_H

#include "monster.h"

#include <QImage>
#include <QRect>

class Bull: public Monster
{

  public:
    Bull();
    virtual ~Bull();

  public:
    void resetState();
    virtual void moveBottom(int);
    virtual void moveTop(int);
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual void autoMove();
    void setAppeared(bool);
    bool hasAppeared();
    void setDead(bool);
    bool isDead();
    void setXDir(int);
    void setYDir(int);
    void setMoving(bool);
    bool isMoving();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  protected:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool dead;
    bool appear;
    bool moving;
    QImage image;
    QRect rect;

};

#endif

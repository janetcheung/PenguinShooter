#ifndef MONSTERBOSS_H
#define MONSTERBOSS_H

#include <QImage>
#include <QRect>
#include "monster.h"

class Boss: public Monster
{
  public : 
	Boss();
	virtual ~Boss();
    
  public : 
    void resetState();
    virtual void moveBottom(int);
    virtual void moveTop(int);
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual void autoMove();
    void compare(int, int);
    void setAppeared(bool);
    bool hasAppeared();
    bool isDead();
    void setShooting(bool);
    bool isShooting();
    void setDead(bool);
    void setXDir(int);
    void setYDir(int);
    void setMoving(bool);
    void setLife(int);
    int getLife();
    bool isMoving();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  protected:
    int angle;
    int speed;
    bool shooting;
    int life;
    int xdir;
    int ydir;
    bool dead;
    bool appear;
    bool moving;
    QImage image;
    QRect rect;
};

#endif

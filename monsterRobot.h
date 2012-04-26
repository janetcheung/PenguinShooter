#ifndef MONSTERROBOT_H
#define MONSTERROBOT_H

#include <QImage>
#include <QRect>
#include "monster.h"

class Robot: public Monster
{
  public : 
	Robot();
	virtual ~Robot();
    
  public : 
    void resetState();
    virtual void moveBottom(int);
    virtual void moveTop(int);
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual void autoMove();
    bool isShooting();
    void setDead(bool);
    bool isDead();
    void setShooting(bool);
    void setDirection(char);
    char getDirection();
    void setXDir(int);
    void setYDir(int);
    void setMoving(bool);
    void setAppeared(bool);
    bool hasAppeared();
    bool isMoving();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  protected:
    int angle;
    int speed;
    bool dead;
    bool shooting;
    char direction;
    int xdir;
    int ydir;
    bool appear;
    bool moving;
    QImage image;
    QRect rect;
};

#endif

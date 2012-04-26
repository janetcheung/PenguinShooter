#ifndef MONSTERSKELETON_H
#define MONSTERSKELETON_H

#include <QImage>
#include <QRect>
#include "monster.h"

class Skeleton: public Monster
{
  public : 
	Skeleton();
	virtual ~Skeleton();
    
  public : 
    void resetState();
    virtual void moveBottom(int);
    virtual void moveTop(int);
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual void autoMove();

	void compare(int,int);
	bool hasAppeared();
    void setDead(bool);
    bool isDead();
	void setAppeared(bool);
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

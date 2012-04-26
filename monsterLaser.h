#ifndef MONSTERLASER_H
#define MONSTERLASER_H

#include <QImage>
#include <QRect>
#include "monster.h"
#include "bubbleBeam.h"

class Laser: public Monster
{
  public : 
	Laser();
	virtual ~Laser();
    
  public : 
    void resetState();
    virtual void moveBottom(int);
    virtual void moveTop(int);
    virtual void moveLeft(int);
    virtual void moveRight(int);
    virtual void autoMove();
    bool hasAppeared();
    void setDead(bool);
    void setXDir(int);
    void setYDir(int);
    void setMoving(bool);
    void setShooting(bool);
    void shootBeam();
    void setBeam(int);
    Beam* getBeam();
    bool emptyBeam();
    void compare(int,int);
    bool isShooting();
    bool isMoving();
    void setAppeared(bool);
    
    bool isDead();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  protected:
    int angle;
    Beam *beam;
    int speed;
    bool shooting;
    int xdir;
    int ydir;
    bool dead;
    bool appear;
    bool moving;
    QImage image;
    QRect rect;
};

#endif

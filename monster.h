#ifndef MONSTER_H
#define MONSTER_H

#include <QImage>
#include <QRect>

class Monster
{

  public:
    Monster();
    virtual ~Monster();

  public:
    void resetState();
    virtual void moveBottom(int) = 0;
    virtual void moveTop(int) = 0;
    virtual void moveLeft(int) = 0;
    virtual void moveRight(int) = 0;
    virtual void autoMove() = 0;
    void setAppeared(bool);
    bool hasAppeared();
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
    bool appear;
    bool moving;
    QImage image;
    QRect rect;

};

#endif

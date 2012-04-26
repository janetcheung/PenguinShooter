#ifndef PLAYER_H
#define PLAYER_H

#include <QImage>
#include <QRect>
#include <QWidget>
#include "bubble.h"

class Player
{

  public:
    Player();
    ~Player();

  public:
    void resetState();
    void moveLeft(int);
    void moveRight(int);
    void moveUp(int);
    void moveDown(int);
    void shootBubble(Bubble *);
    char getDirection();
    bool isShooting();
    void setShooting(bool);
    void setLife(int);
    int getLife();
    void shoot();
    void setSpeed(int);
    int getSpeed();
    int getXDir();
    int getYDir();
    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    char direction;
    bool shooting;
    int speed;
    int xdir;
    int ydir;
    int life;

};

#endif

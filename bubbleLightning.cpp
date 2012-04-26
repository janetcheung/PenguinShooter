#include "bubbleLightning.h"
#include <iostream>

Lightning::Lightning() : Bubble()
{

  xdirR = 1;
  xdirL = -1;
  ydir = -1;
  image.load("Lightning.png"); 

  rect = image.rect();
  resetState();

}

Lightning::~Lightning() {
  //std::cout << ("Lightning deleted\n");
}

void Lightning::startPosition(int px, int py)
{
	rect.moveTo(px, py);
}

void Lightning::setSpeed(int s)
{
	speed = s;
}

int Lightning::getSpeed()
{
	return speed;
}

void Lightning::autoMove()
{
  rect.translate(xdirL, ydir);

  if (rect.left() == 0) {
    xdirL = speed;
    disappeared = true;
    moving = false;
  }

  if (rect.right() == 500) {
    xdirR = 0-speed;
    disappeared = true;
    moving = false;
  }

  if (rect.top() == 0) {
    ydir = speed;
  }
if (rect.bottom() == 600)
{	ydir = 0-speed;
}
}

void Lightning::autoMoveLeft()
{ 
  //xdir = -1;
  xdirL = 0-speed;
  ydir = 0;
  rect.translate(xdirL,ydir);
  if (rect.left() == 0 && moving == true) {
    disappeared = true;
    moving = false;
  }
}

void Lightning::autoMoveRight()
{
  //xdir = 1;
  xdirR = speed;
  ydir = 0;
  rect.translate(xdirR, ydir);
  if (rect.right() == 500 && moving == true) {
    disappeared = true;
    moving = false;
  }
}


void Lightning::resetState() 
{
  rect.moveTo(466, 566); 
  disappeared = true;
  moving = false;
  speed = 2;
}

void Lightning::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Lightning::moveTop(int top)
{
  rect.moveTop(top);
}

void Lightning::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Lightning::moveRight(int right)
{
  rect.moveRight(right);
}

void Lightning::setXDirL(int x)
{
  xdirL = x;
}

void Lightning::setXDirR(int x)
{
  xdirR = x;
}

void Lightning::setYDir(int y)
{
  ydir = y;
}

void Lightning::setDirection(char d)
{
  direction = d;
}

char Lightning::getDirection()
{
  return direction;
}

void Lightning::setDisappeared(bool d)
{
  disappeared = d;
}

bool Lightning::hasDisappeared()
{
  return disappeared;
}

void Lightning::setMoving(bool m)
{
  moving = m;
}

bool Lightning::isMoving()
{
  return moving;
}

int Lightning::getXDirL()
{
  return xdirL;
}

int Lightning::getXDirR()
{
  return xdirR;
}

int Lightning::getYDir()
{
  return ydir;
}

QRect Lightning::getRect()
{
  return rect;
}

QImage & Lightning::getImage()
{
  return image;
}

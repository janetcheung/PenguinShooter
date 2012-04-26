#include "bubble.h"
#include <iostream>

Bubble::Bubble()
{

  xdirR = 1;
  xdirL = -1;
  ydir = -1;
  image.load("bubble.png"); 

  rect = image.rect();
  resetState();

}

Bubble::~Bubble() {
  ////std::cout << ("Bubble deleted\n");
}

void Bubble::startPosition(int px, int py)
{
	rect.moveTo(px, py);
}

void Bubble::setSpeed(int s)
{
	speed = s;
}

int Bubble::getSpeed()
{
	return speed;
}

void Bubble::autoMove()
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

void Bubble::autoMoveLeft()
{ 
  //xdir = -1;
  xdirL = (0-speed);
  ydir = 0;
  rect.translate(xdirL,ydir);
  if (rect.left() == 0 && moving == true) {
    disappeared = true;
    moving = false;
  }
}

void Bubble::autoMoveRight()
{
  //xdir = 1;
  xdirR = (speed);
  ydir = 0;
  rect.translate(xdirR, ydir);
  if (rect.right() == 500 && moving == true) {
    disappeared = true;
    moving = false;
  }
}


void Bubble::resetState() 
{
  rect.moveTo(466, 566); 
  disappeared = true;
  moving = false;
  speed = 3;
}

void Bubble::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Bubble::moveTop(int top)
{
  rect.moveTop(top);
}

void Bubble::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Bubble::moveRight(int right)
{
  rect.moveRight(right);
}

void Bubble::setXDirL(int x)
{
  xdirL = x;
}

void Bubble::setXDirR(int x)
{
  xdirR = x;
}

void Bubble::setYDir(int y)
{
  ydir = y;
}

void Bubble::setDirection(char d)
{
  direction = d;
}

char Bubble::getDirection()
{
  return direction;
}

void Bubble::setDisappeared(bool d)
{
  disappeared = d;
}

bool Bubble::hasDisappeared()
{
  return disappeared;
}

void Bubble::setMoving(bool m)
{
  moving = m;
}

bool Bubble::isMoving()
{
  return moving;
}

int Bubble::getXDirL()
{
  return xdirL;
}

int Bubble::getXDirR()
{
  return xdirR;
}

int Bubble::getYDir()
{
  return ydir;
}

QRect Bubble::getRect()
{
  return rect;
}

QImage & Bubble::getImage()
{
  return image;
}

#include "bubbleBeam.h"
#include <iostream>

Beam::Beam()
{

  xdirR = speed;
  xdirL = -speed;
  ydir = 0;
  image.load("robotBullet.png"); 

  rect = image.rect();
  resetState();

}

Beam::~Beam() {
  //std::cout << ("Beam deleted\n");
}

void Beam::startPosition(int px, int py)
{
	rect.moveTo(px, py);
}

void Beam::setSpeed(int s)
{
	speed = s;
}

int Beam::getSpeed()
{
	return speed;
}

void Beam::autoMove()
{
  rect.translate(xdirL, ydir);

  if (rect.left() == 0) {
    xdirL = 3;
    disappeared = true;
    moving = false;
  }

  if (rect.right() == 500) {
    xdirR = -speed;
    disappeared = true;
    moving = false;
  }

  if (rect.top() == 0) {
    ydir = 0;
  }
if (rect.bottom() == 600)
	{	ydir = 0;
	}
}

void Beam::autoMoveLeft()
{ 
  //xdir = -1;
  xdirL = -speed;
  xdirR = 0;
  ydir = 0;
  rect.translate(xdirL,ydir);
  if (rect.left() <= 0 && moving == true) {
    resetState();
  }
}

void Beam::autoMoveRight()
{
  //xdir = 1;
  xdirR = speed;
  xdirL = 0;
  ydir = 0;
  rect.translate(xdirR, ydir);
  if (rect.right() >= 500 && moving == true) {
    resetState();
  }
}

void Beam::autoMoveDown()
{
	xdirR = 0;
	xdirL = 0;
	ydir = speed;
	rect.translate(xdirR, ydir);
	if (rect.bottom() == 600 && moving == true)
		resetState();
}

void Beam::resetState() 
{
  rect.moveTo(466, 566); 
  disappeared = true;
  moving = false;
  speed = 3;
}

void Beam::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Beam::moveTop(int top)
{
  rect.moveTop(top);
}

void Beam::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Beam::moveRight(int right)
{
  rect.moveRight(right);
}

void Beam::setXDirL(int x)
{
  xdirL = x;
}

void Beam::setXDirR(int x)
{
  xdirR = x;
}

void Beam::setYDir(int y)
{
  ydir = y;
}

void Beam::setDirection(char d)
{
  direction = d;
}

char Beam::getDirection()
{
  return direction;
}

void Beam::setDisappeared(bool d)
{
  disappeared = d;
}

bool Beam::hasDisappeared()
{
  return disappeared;
}

void Beam::setMoving(bool m)
{
  moving = m;
}

bool Beam::isMoving()
{
  return moving;
}

int Beam::getXDirL()
{
  return xdirL;
}

int Beam::getXDirR()
{
  return xdirR;
}

int Beam::getYDir()
{
  return ydir;
}

QRect Beam::getRect()
{
  return rect;
}

QImage & Beam::getImage()
{
  return image;
}

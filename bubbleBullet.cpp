#include "bubbleBullet.h"
#include <iostream>

Bullet::Bullet()
{

  xdirR = speed;
  xdirL = -speed;
  ydir = 0;
  image.load("CapturedMonster.jpg"); 

  rect = image.rect();
  resetState();

}

Bullet::~Bullet() {
  //std::cout << ("Bullet deleted\n");
}

void Bullet::startPosition(int px, int py)
{
	rect.moveTo(px, py);
}

void Bullet::setSpeed(int s)
{
	speed = s;
}

int Bullet::getSpeed()
{
	return speed;
}

void Bullet::autoMove()
{
  rect.translate(xdirL, ydir);

  if (rect.left() == 0) {
    xdirL = 4;
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

void Bullet::compare(int X, int Y)
{
	if (rect.left() > X)
		xdirR = -2;
	else if (rect.left() == X)
		xdirR = 0;
	else 
		xdirR = 2;
	//if (rect.right() >= X)
	//	xdirR = -1;
	if (rect.top() < Y)
		ydir = 2;
	else if (rect.top() == Y)
		ydir = 0;
	else
		ydir = -2;
	//if (rect.bottom() >= Y)
		//ydir = -1;
	rect.translate(xdirR,ydir);
}

void Bullet::autoMoveLeft()
{ 
  //xdir = -1;
  xdirL = -speed;
  ydir = 0;
  rect.translate(xdirL,ydir);
  if (rect.left() <= 0 && moving == true) {
    resetState();
  }
}

void Bullet::autoMoveRight()
{
  //xdir = 1;
  xdirR = speed;
  ydir = 0;
  rect.translate(xdirR, ydir);
  if (rect.right() >= 500 && moving == true) {
    resetState();
  }
}

void Bullet::autoMoveDown()
{
	xdirR = 0;
	xdirL = 0;
	ydir = speed;
	rect.translate(xdirR, ydir);
	if (rect.bottom() == 600 && moving == true)
		resetState();
}

void Bullet::resetState() 
{
  rect.moveTo(466, 566); 
  disappeared = true;
  moving = false;
  speed = 2;
}

void Bullet::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Bullet::moveTop(int top)
{
  rect.moveTop(top);
}

void Bullet::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Bullet::moveRight(int right)
{
  rect.moveRight(right);
}

void Bullet::setXDirL(int x)
{
  xdirL = x;
}

void Bullet::setXDirR(int x)
{
  xdirR = x;
}

void Bullet::setYDir(int y)
{
  ydir = y;
}

void Bullet::setDirection(char d)
{
  direction = d;
}

char Bullet::getDirection()
{
  return direction;
}

void Bullet::setDisappeared(bool d)
{
  disappeared = d;
}

bool Bullet::hasDisappeared()
{
  return disappeared;
}

void Bullet::setMoving(bool m)
{
  moving = m;
}

bool Bullet::isMoving()
{
  return moving;
}

int Bullet::getXDirL()
{
  return xdirL;
}

int Bullet::getXDirR()
{
  return xdirR;
}

int Bullet::getYDir()
{
  return ydir;
}

QRect Bullet::getRect()
{
  return rect;
}

QImage & Bullet::getImage()
{
  return image;
}

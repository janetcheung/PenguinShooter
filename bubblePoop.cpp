
#include "bubblePoop.h"
#include <iostream>

Poop::Poop()
{

  xdirR = speed;
  xdirL = -speed;
  ydir = 0;
  image.load("Poop.png"); 

  rect = image.rect();
  resetState();

}

Poop::~Poop() {
  //std::cout << ("Poopdeleted\n");
}

void Poop::startPosition(int px, int py)
{
	rect.moveTo(px, py);
}

void Poop::setSpeed(int s)
{
	speed = s;
}

int Poop::getSpeed()
{
	return speed;
}

void Poop::autoMove()
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

void Poop::autoMoveLeft()
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

void Poop::autoMoveRight()
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

void Poop::autoMoveDown()
{
	xdirR = 0;
	xdirL = 0;
	ydir = speed;
	rect.translate(xdirR, ydir);
	if (rect.bottom() >= 600 && moving == true)
		resetState();
}

void Poop::resetState() 
{
  rect.moveTo(466, 566); 
  disappeared = true;
  moving = false;
  speed = 4;
}

void Poop::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Poop::moveTop(int top)
{
  rect.moveTop(top);
}

void Poop::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Poop::moveRight(int right)
{
  rect.moveRight(right);
}

void Poop::setXDirL(int x)
{
  xdirL = x;
}

void Poop::setXDirR(int x)
{
  xdirR = x;
}

void Poop::setYDir(int y)
{
  ydir = y;
}

void Poop::setDirection(char d)
{
  direction = d;
}

char Poop::getDirection()
{
  return direction;
}

void Poop::setDisappeared(bool d)
{
  disappeared = d;
}

bool Poop::hasDisappeared()
{
  return disappeared;
}

void Poop::setMoving(bool m)
{
  moving = m;
}

bool Poop::isMoving()
{
  return moving;
}

int Poop::getXDirL()
{
  return xdirL;
}

int Poop::getXDirR()
{
  return xdirR;
}

int Poop::getYDir()
{
  return ydir;
}

QRect Poop::getRect()
{
  return rect;
}

QImage & Poop::getImage()
{
  return image;
}

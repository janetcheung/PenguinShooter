
#include "monsterSkeleton.h"
#include "monster.h"
#include <iostream>

Skeleton::Skeleton(): Monster() 
{

  xdir = 1;
  ydir = -1;

  image.load("GhostMonster.png"); //friend's drawing

  rect = image.rect();
  resetState();

}

 Skeleton::~Skeleton() {
  //std::cout << ("Skeleton deleted\n");
}

void Skeleton::setAppeared(bool a)
{
	appear = a;
}

bool Skeleton::hasAppeared()
{
	return appear;
}
void Skeleton::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 4) {
    xdir = 2;
  }

  if (rect.right() >= 494) {
    xdir = -2;
  }

  if (rect.top() <= 2) {
    ydir = 2;
  }
if (rect.bottom() >= 600)
  {	ydir = -2;
  }
}
bool Skeleton::isDead()
{
	return dead;
}

void Skeleton::setDead(bool d)
{
	dead = d;
}
void Skeleton::resetState() 
{
  rect.moveTo(rand()% 400, rand() % 400);
  moving = true;
  appear = false;
  dead = false;
}
void Skeleton::compare(int X, int Y)
{
	if (rect.left() > X)
		xdir = -1;
	else if (rect.left() == X)
		xdir = 0;
	else 
		xdir = 1;
	if (rect.top() < Y)
		ydir = 1;
	else if (rect.top() == Y)
		ydir = 0;
	else
		ydir = -1;
	rect.translate(xdir,ydir);
}
void Skeleton::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Skeleton::moveTop(int top)
{
  rect.moveTop(top);
}

void Skeleton::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Skeleton::moveRight(int right)
{
  rect.moveRight(right);
}

void Skeleton::setXDir(int x)
{
  xdir = x;
}

void Skeleton::setYDir(int y)
{
  ydir = y;
}

int Skeleton::getXDir()
{
  return xdir;
}

int Skeleton::getYDir()
{
  return ydir;
}


void Skeleton::setMoving(bool m)
{
  moving = m;
}

bool Skeleton::isMoving()
{
  return moving;
}

QRect Skeleton::getRect()
{
  return rect;
}

QImage & Skeleton::getImage()
{
  return image;
}


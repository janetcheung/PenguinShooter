#include "monsterBoss.h"
#include "monster.h"
#include <iostream>

Boss::Boss(): Monster() 
{

  xdir = 1;
  ydir = 0;

  image.load("BossMonster.png");

  rect = image.rect();
  resetState();

}

 Boss::~Boss() {
  //std::cout << ("Boss deleted\n");
}


void Boss::autoMove()
{ 
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = 1;
  }

  if (rect.right() >= 500) {
    xdir = -1;
  }

  if (rect.top() <= 0) {
    ydir = 0;
  }
if (rect.bottom() >= 600)
  {	ydir = 0;
  }
}

void Boss::compare(int X, int Y)
{
	if (rect.left() <= X)
		xdir = 2;
	if (rect.right() >= X)
		xdir = -2;
	if (rect.top() <= Y)
		ydir = 2;
	if (rect.bottom() >= Y)
		ydir = -2;
	rect.translate(xdir,ydir);
}

bool Boss::isDead()
{
	return dead;
}

void Boss::setDead(bool d)
{
	dead = d;
}
void Boss::resetState() 
{
  rect.moveTo(200, 200);
  moving = true;
  appear = false;
  dead = false;
  life = 50;
}

void Boss::setAppeared(bool a)
{
	appear = a;
}

bool Boss::hasAppeared()
{
	return appear;
}
void Boss::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Boss::moveTop(int top)
{
  rect.moveTop(top);
}

void Boss::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Boss::moveRight(int right)
{
  rect.moveRight(right);
}

void Boss::setXDir(int x)
{
  xdir = x;
}

void Boss::setYDir(int y)
{
  ydir = y;
}

int Boss::getXDir()
{
  return xdir;
}

int Boss::getYDir()
{
  return ydir;
}

void Boss::setMoving(bool m)
{
  moving = m;
}

bool Boss::isMoving()
{
  return moving;
}
int Boss::getLife()
{
	return life;
}
void Boss::setLife(int l)
{
	life = l;
}

void Boss::setShooting(bool s)
{
	shooting = s;
}

bool Boss::isShooting()
{
	return shooting;
}

QRect Boss::getRect()
{
  return rect;
}

QImage & Boss::getImage()
{
  return image;
}


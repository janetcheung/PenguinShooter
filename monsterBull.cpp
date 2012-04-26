
#include "monsterBull.h"
#include "monster.h"
#include <iostream>

Bull::Bull(): Monster() 
{

  xdir = 1;//rand() % 10;
  ydir = -1;//0-(rand()% 10);

  image.load("BullMonster.png"); //friend's drawing

  rect = image.rect();
  resetState();

}

 Bull::~Bull() {
  //std::cout << ("Bull deleted\n");
}


void Bull::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() == 0) {
    xdir = 1;
  }

  if (rect.right() == 500) {
    xdir = -1;
  }

  if (rect.top() == 0) {
    ydir = 1;
  }
if (rect.bottom() == 600)
  {	ydir = -1;
  }
}

void Bull::setAppeared(bool a)
{
	appear = a;
}

bool Bull::hasAppeared()
{
	return appear;
}
void Bull::resetState() 
{
  //xdir = rand() % 400;
  //ydir = rand() % 400;
  rect.moveTo((rand()% 400), (rand()%400));
  //rect.moveTo(xdir,ydir);
  moving = true;
  appear = false;
  dead = false;
}

bool Bull::isDead()
{
	return dead;
}

void Bull::setDead(bool d)
{
	dead = d;
}

void Bull::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Bull::moveTop(int top)
{
  rect.moveTop(top);
}

void Bull::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Bull::moveRight(int right)
{
  rect.moveRight(right);
}

void Bull::setXDir(int x)
{
  xdir = x;
}

void Bull::setYDir(int y)
{
  ydir = y;
}

int Bull::getXDir()
{
  return xdir;
}

int Bull::getYDir()
{
  return ydir;
}


void Bull::setMoving(bool m)
{
  moving = m;
}

bool Bull::isMoving()
{
  return moving;
}

QRect Bull::getRect()
{
  return rect;
}

QImage & Bull::getImage()
{
  return image;
}


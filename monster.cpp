#include "monster.h"
#include <iostream>

Monster::Monster()
{

  xdir = 1;
  ydir = -1;

  image.load("redMonster.png");

  rect = image.rect();
  resetState();

}

Monster::~Monster() {
 //std::cout << ("Monster deleted\n");
}

void Monster::resetState() 
{
  rect.moveTo(230, 355);
  moving = true;
}

void Monster::setXDir(int x)
{
  xdir = x;
}

void Monster::setYDir(int y)
{
  ydir = y;
}

int Monster::getXDir()
{
  return xdir;
}

int Monster::getYDir()
{
  return ydir;
}
void Monster::setAppeared(bool a)
{
	appear = a;
}

bool Monster::hasAppeared()
{
	return appear;
}

void Monster::setMoving(bool m)
{
  moving = m;
}

bool Monster::isMoving()
{
  return moving;
}

QRect Monster::getRect()
{
  return rect;
}

QImage & Monster::getImage()
{
  return image;
}

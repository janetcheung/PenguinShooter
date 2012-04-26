#include "monsterLaser.h"
#include "monster.h"
#include <iostream>

Laser::Laser(): Monster() 
{

  xdir = 1;
  ydir = -1;

  image.load("UFOMonster.png");

  rect = image.rect();
  beam = new Beam();
  resetState();

}

 Laser::~Laser() {
  //std::cout << ("Laser deleted\n");
}


void Laser::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = 1;
  }

  if (rect.right() >= 500) {
    xdir = -1;
  }

  if (rect.top() <= 0) {
    ydir = 1;
  }
if (rect.bottom() >= 600)
  {	ydir = -1;
  }
}
void Laser::compare(int X, int Y)
{

	if (rect.left() > X)
		xdir = -1;
	else if (rect.left() == X)
		xdir = 0;
	else 
		xdir = 1;
	if (rect.top() < Y)
		ydir = 0;
	else if (rect.top() == Y)
		ydir = 0;
	else
		ydir = 0;
	rect.translate(xdir,ydir);

}
Beam* Laser::getBeam()
{	
	return beam;
}
void Laser::resetState() 
{
  rect.moveTo(rand() % 450, 20);
  moving = true;
  appear = false;
  dead = false;
}

bool Laser::isDead()
{
	return dead;
}

void Laser::setDead(bool d)
{
	dead = d;
}
void Laser::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Laser::moveTop(int top)
{
  rect.moveTop(top);
}

void Laser::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Laser::moveRight(int right)
{
  rect.moveRight(right);
}

void Laser::setXDir(int x)
{
  xdir = x;
}

void Laser::setYDir(int y)
{
  ydir = y;
}

int Laser::getXDir()
{
  return xdir;
}

int Laser::getYDir()
{
  return ydir;
}

void Laser::setAppeared(bool a)
{
	appear = a;
}

bool Laser::hasAppeared()
{
	return appear;
}
void Laser::setMoving(bool m)
{
  moving = m;
}

void Laser::setShooting(bool s)
{
	shooting = s;
}

void Laser::shootBeam()
{
	beam->autoMoveDown();
	beam->setMoving(true);
}

bool Laser::isShooting()
{
	return shooting;
}

bool Laser::isMoving()
{
  return moving;
}

QRect Laser::getRect()
{
  return rect;
}

QImage & Laser::getImage()
{
  return image;
}


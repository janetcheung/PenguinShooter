#include "monsterRobot.h"
#include "monster.h"
#include <iostream>

Robot::Robot(): Monster() 
{

  xdir = 1;
  ydir = 0;

  image.load("RobotMonster.png"); //friend's drawing

  rect = image.rect();
  resetState();

}

 Robot::~Robot() {
  //std::cout << ("Robot deleted\n");
}


void Robot::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = 1;
    setDirection('r');
  }

  if (rect.right() >= 500) {
    xdir = -1;
    setDirection('l');
  }

  if (rect.top() <= 0) {
    ydir = 0;
  }
if (rect.bottom() >= 600)
  {	ydir = 0;
  }
}

bool Robot::isShooting()
{
  return shooting;
}

void Robot::setShooting(bool shoot)
{
  shooting = shoot;
}

char Robot::getDirection()
{
	return direction;
}

void Robot::setDirection(char d)
{
	direction = d;
}
bool Robot::isDead()
{
	return dead;
}

void Robot::setDead(bool d)
{
	dead = d;
}
void Robot::resetState() 
{
  rect.moveTo(0, 505);
  direction = 'r';
  moving = true;
  shooting = true;
  appear = false;
  dead = false;
}

void Robot::setAppeared(bool a)
{
	appear = a;
}

bool Robot::hasAppeared()
{
	return appear;
}
void Robot::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Robot::moveTop(int top)
{
  rect.moveTop(top);
}

void Robot::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Robot::moveRight(int right)
{
  rect.moveRight(right);
}

void Robot::setXDir(int x)
{
  xdir = x;
}

void Robot::setYDir(int y)
{
  ydir = y;
}

int Robot::getXDir()
{
  return xdir;
}

int Robot::getYDir()
{
  return ydir;
}

void Robot::setMoving(bool m)
{
  moving = m;
}

bool Robot::isMoving()
{
  return moving;
}

QRect Robot::getRect()
{
  return rect;
}

QImage & Robot::getImage()
{
  return image;
}


#include "player.h"
#include <iostream>

Player::Player()
{
  image.load("PlayerLeft.png");
  rect = image.rect();
  resetState();
}

Player::~Player()
{
 //std::cout << ("Player deleted\n");
}

void Player::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
  direction = 'l';
}
 
void Player::moveRight(int right)
{
  if (rect.right() <= 498)
    rect.moveTo(right, rect.top());
  direction = 'r';
}

void Player::moveUp(int up)
{
	if (rect.top() >=2)
		rect.moveTo(rect.left(), up);
}

void Player::moveDown(int down)
{
	if (rect.bottom() <=598)
		rect.moveTo(rect.left(), down);
	
}

void Player::shootBubble(Bubble *bubble)
{	
	if (direction == 'l')
		bubble->autoMoveLeft();
	else if (direction == 'r')
		bubble->autoMoveRight();
}

void Player::resetState()
{
  rect.moveTo(466, 566);
  direction = 'l';
  shooting = false;
  speed = 5;
}

bool Player::isShooting()
{
  return shooting;
}

void Player::setShooting(bool shoot)
{
  shooting = shoot;
}

char Player::getDirection()
{
  return direction;
}
QRect Player::getRect()
{
  return rect;
}

QImage & Player::getImage()
{
  return image;
}

int Player::getSpeed()
{
	return speed;
}

void Player::setSpeed(int s)
{
	speed = s;
}

int Player::getXDir()
{
  if (direction == 'r')
    {return rect.right();}
  else if (direction == 'l')
    {return rect.left();}
}

int Player::getYDir()
{
  return rect.top();
}

int Player::getLife()
{
  return life;
}

void Player::setLife(int l)
{
  life = l;
}

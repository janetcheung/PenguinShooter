#include "powerupSkates.h"
#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

powerupSkates::powerupSkates(): Powerup()
{
	x = rand() % 450;
	y = rand() % 550;
	image.load("Skates.png");
	rect = image.rect();
	resetState();
}

powerupSkates::~powerupSkates()
{
  	//std::cout << ("powerupSkates deleted\n");
}

void powerupSkates::appear()
{
	x = rand() % 450;
	y = rand() % 550;
	rect.moveTo(x,y);
}

void powerupSkates::setActive(bool a) //is or is not active
{
  active = a;
}

bool powerupSkates::isActive()
{
	return active;
}

void powerupSkates::resetState()
{
	rect.moveTo(x,y);
	active = false;
	appeared = false;
	count = 0;
}

void powerupSkates::setX(int X)
{
	x = X;
}

void powerupSkates::setY(int Y)
{
	y = Y;
}
void powerupSkates::setAppeared(bool a)
{
	appeared = a;
}

bool powerupSkates::hasAppeared()
{
	return appeared;
}
QRect powerupSkates::getRect()
{
	return rect;
}

QImage & powerupSkates::getImage()
{
	return image;
}

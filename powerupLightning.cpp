#include "powerupLightning.h"
#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

powerupLightning::powerupLightning(): Powerup()
{
	x = rand() % 450;
	y = rand() % 550;
	image.load("Lightning.png");
	rect = image.rect();
	resetState();
}

powerupLightning::~powerupLightning()
{
  	//std::cout << ("powerupLightning deleted\n");
}

void powerupLightning::appear()
{
	x = rand() % 450;
	y = rand() % 550;
	rect.moveTo(x,y);
}

void powerupLightning::setActive(bool a) //is or is not active
{
  active = a;
}

bool powerupLightning::isActive()
{
	return active;
}

/*void powerupLightning::useAbility()
{
	rect.moveTo(x,y);
}*/
void powerupLightning::resetState()
{
	rect.moveTo(x,y);
	active = false;
	appeared = false;
	count = 0;
}

void powerupLightning::setX(int X)
{
	x = X;
}

void powerupLightning::setY(int Y)
{
	y = Y;
}
void powerupLightning::setAppeared(bool a)
{
	appeared = a;
}

bool powerupLightning::hasAppeared()
{
	return appeared;
}
QRect powerupLightning::getRect()
{
	return rect;
}

QImage & powerupLightning::getImage()
{
	return image;
}

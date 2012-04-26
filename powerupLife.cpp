#include "powerupLife.h"
#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

Life::Life() : Powerup()
{
	x = rand() % 450;
	y = rand() % 550;
	image.load("Life.png");
	rect = image.rect();
	resetState();
}

Life::~Life()
{
  	//std::cout << ("Life deleted\n");
}

void Life::appear()
{
	x = rand() % 450;
	y = rand() % 550;
	rect.moveTo(x,y);
}

void Life::setActive(bool a)
{
	active = a;
}

bool Life::isActive()
{
	return active;
}	

void Life::resetState()
{
	rect.moveTo(x,y);
	active = false;
	appeared = false;
	count = 0;
}

void Life::setX(int X)
{
	x = X;
}
void Life::setAppeared(bool a)
{
	appeared = a;
}

bool Life::hasAppeared()
{
	return appeared;
}
void Life::setY(int Y)
{
	y = Y;
}

QRect Life::getRect()
{
	return rect;
}

QImage & Life::getImage()
{
	return image;
}

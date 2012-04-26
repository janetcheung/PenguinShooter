#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

Powerup::Powerup()
{
	x = 1;
	y = 1;
	image.load("Candy.png");
	rect = image.rect();
	resetState();
}

Powerup::~Powerup()
{
  	//std::cout << ("Powerup deleted\n");
}

void Powerup::resetState()
{
	rect.moveTo(1,1);
}

void Powerup::setX(int X)
{
	x = X;
}

void Powerup::setY(int Y)
{
	y = Y;
}

void Powerup::setAppeared(bool a)
{
	appeared = a;
}

bool Powerup::hasAppeared()
{
	return appeared;
}
QRect Powerup::getRect()
{
	return rect;
}

QImage & Powerup::getImage()
{
	return image;
}

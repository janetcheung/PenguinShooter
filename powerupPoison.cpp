#include "powerupPoison.h"
#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

Poison::Poison(): Powerup()
{
	x = rand() % 450;
	y = rand() % 550;
	image.load("Poison.png");
	rect = image.rect();
	resetState();
}

Poison::~Poison()
{
  	//std::cout << ("Poison deleted\n");
}

void Poison::appear()
{
	x = rand() % 450;
	y = rand() % 550;
	rect.moveTo(x,y);
}

void Poison::setAppeared(bool a)
{
	appeared = a;
}

bool Poison::hasAppeared()
{
	return appeared;
}

void Poison::setActive(bool a) //is or is not active
{
  active = a;
}

bool Poison::isActive()
{
	return active;
}

void Poison::resetState()
{
	rect.moveTo(x,y);
	active = false;
	appeared = false;
	count = 0;
}

void Poison::setX(int X)
{
	x = X;
}

void Poison::setY(int Y)
{
	y = Y;
}

QRect Poison::getRect()
{
	return rect;
}

QImage & Poison::getImage()
{
	return image;
}

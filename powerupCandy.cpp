#include "powerupCandy.h"
#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

Candy::Candy() : Powerup()
{
	x = rand() % 450;
	y = rand() % 550;
	image.load("bubbleGun.png");
	rect = image.rect();
	resetState();
}

Candy::~Candy()
{
  	////std::cout << ("Candy deleted\n");
}

void Candy::appear()
{
	x = (rand() % 450);
	y = (rand() % 550);
	rect.moveTo(x,y);
}
void Candy::setAppeared(bool a)
{
	appeared = a;
}

bool Candy::hasAppeared()
{
	return appeared;
}
void Candy::setActive(bool a)
{
	active = a;
}

bool Candy::isActive()
{
	return active;
}	

void Candy::resetState()
{
	rect.moveTo(x,y);
	active = false;
	appeared = false;
	count = 0;
}

void Candy::setX(int X)
{
	x = X;
}

void Candy::setY(int Y)
{
	y = Y;
}

QRect Candy::getRect()
{
	return rect;
}

QImage & Candy::getImage()
{
	return image;
}

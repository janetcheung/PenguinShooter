#include "powerupDiamonds.h"
#include "powerup.h"
#include <iostream>
#include <QRect>
#include <QImage>

Diamond::Diamond() : Powerup()
{
	x = rand() % 450;
	y = rand() % 550;
	image.load("Gem.png");
	rect = image.rect();
	resetState();
}

Diamond::~Diamond()
{
  	//std::cout << ("Diamond deleted\n");
}

void Diamond::appear()
{
	x = (rand() % 450);
	y = (rand() % 550);
	rect.moveTo(x,y);
}
void Diamond::setAppeared(bool a)
{
	appeared = a;
}

bool Diamond::hasAppeared()
{
	return appeared;
}
void Diamond::setActive(bool a)
{
	active = a;
}

bool Diamond::isActive()
{
	return active;
}	

void Diamond::resetState()
{
	rect.moveTo(x,y);
	active = false;
	appeared = false;
	count = 0;
}

void Diamond::setX(int X)
{
	x = X;
}

void Diamond::setY(int Y)
{
	y = Y;
}

QRect Diamond::getRect()
{
	return rect;
}

QImage & Diamond::getImage()
{
	return image;
}

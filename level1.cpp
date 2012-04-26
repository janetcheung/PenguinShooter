#include "level1.h"

level1::level1()
{
	image.load("level1.jpg");
	
	rect = image.rect();
}

level1::~level1()
{
	//empty
}

QRect level1::getRect()
{
  return rect;
}

QImage & level1::getImage()
{
  return image;
}

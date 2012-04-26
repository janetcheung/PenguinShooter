#include "level4.h"

level4::level4()
{
	image.load("level4.jpg");
	
	rect = image.rect();
}

level4::~level4()
{
	//empty
}

QRect level4::getRect()
{
  return rect;
}

QImage & level4::getImage()
{
  return image;
}

#include "level2.h"

level2::level2()
{
	image.load("level2.jpg");
	
	rect = image.rect();
}

level2::~level2()
{
	//empty
}

QRect level2::getRect()
{
  return rect;
}

QImage & level2::getImage()
{
  return image;
}

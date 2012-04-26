#include "level3.h"

level3::level3()
{
	image.load("level3.jpg");
	
	rect = image.rect();
}

level3::~level3()
{
	//empty
}

QRect level3::getRect()
{
  return rect;
}

QImage & level3::getImage()
{
  return image;
}

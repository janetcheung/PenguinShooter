#ifndef LEVEL1_H
#define LEVEL1_H

#include <QImage>
#include <QRect>

class level1
{
	public :
		level1();
		~level1();
		
		QRect getRect();
    	QImage & getImage();
		
	private :
    	QImage image;
    	QRect rect;
};

#endif


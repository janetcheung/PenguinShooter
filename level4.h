#ifndef LEVEL4_H
#define LEVEL4_H

#include <QImage>
#include <QRect>

class level4
{
	public :
		level4();
		~level4();
		
		QRect getRect();
    	QImage & getImage();
		
	private :
    	QImage image;
    	QRect rect;
};

#endif


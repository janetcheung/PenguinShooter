#ifndef LEVEL2_H
#define LEVEL2_H

#include <QImage>
#include <QRect>

class level2
{
	public :
		level2();
		~level2();
		
		QRect getRect();
    	QImage & getImage();
		
	private :
    	QImage image;
    	QRect rect;
};

#endif


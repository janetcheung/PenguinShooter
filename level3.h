#ifndef LEVEL3_H
#define LEVEL3_H

#include <QImage>
#include <QRect>

class level3
{
	public :
		level3();
		~level3();
		
		QRect getRect();
    	QImage & getImage();
		
	private :
    	QImage image;
    	QRect rect;
};

#endif


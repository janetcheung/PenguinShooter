#ifndef POWERUPLIFE_H
#define POWERUPLIFE_H
#include "powerup.h"
#include <cstdlib>
#include <QRect>
#include <QImage>

class Life: public Powerup
{
	public: 
		Life();
		virtual ~Life();

   	public : 
    	void resetState();
   		virtual void appear();
   		void setX(int);
    	void setY(int);
    	void setActive(bool);
   		bool isActive();
   		void setAppeared(bool);
   		bool hasAppeared();
   		int count;
   		QRect getRect();
    	QImage & getImage();
    
    private :
    	int x;
    	int y;
    	bool active;
	   	bool appeared;
       	QImage image;
    	QRect rect;	
};

#endif

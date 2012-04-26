#ifndef POWERUPPOISON_H
#define POWERUPPOISON_H
#include "powerup.h"
#include <cstdlib>
#include <QRect>
#include <QImage>

class Poison: public Powerup
{
	public: 
		Poison();
		virtual ~Poison();

   	public : 
    	void resetState();
   		virtual void appear();
   		bool isActive();
   		void setActive(bool);
   		void setX(int);
    	void setY(int);
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

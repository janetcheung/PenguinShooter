#ifndef POWERUPSKATES_H
#define POWERUPSKATES_H
#include "powerup.h"
#include <cstdlib>
#include <QRect>
#include <QImage>

class powerupSkates: public Powerup
{
	public: 
		powerupSkates();
		virtual ~powerupSkates();

   	public : 
    	void resetState();
   		virtual void appear();
   		bool isActive();
   		void setActive(bool);
   		//virtual void useAbility();
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

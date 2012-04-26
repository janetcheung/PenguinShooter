#ifndef POWERUPCANDY_H
#define POWERUPCANDY_H
//#include "bubble.h"
#include "powerup.h"
#include <cstdlib>
#include <QRect>
#include <QImage>

class Candy: public Powerup
{
	public: 
		Candy();
		virtual ~Candy();

   	public : 
    	void resetState();
    	virtual void appear();
   		//virtual void useAbility();
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
    	//Bubble *bubble[20];
       	QImage image;
    	QRect rect;	
};

#endif

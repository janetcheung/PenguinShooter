#ifndef POWERUP_H
#define POWERUP_H

#include <QImage>
#include <QRect>

class Powerup
{
   	public :
		Powerup();
		virtual ~Powerup();

   	public : 
    	void resetState();
   		virtual void appear() = 0;
   		//virtual void useAbility() = 0;
   		void setAppeared(bool);
   		bool hasAppeared();
   		void setActive(bool);
   		bool isActive();
   		void setX(int);
    	void setY(int);
    	int count;
   		QRect getRect();
    	QImage & getImage();
    
    protected :
    	int x;
    	int y;
    	bool active;
    	bool appeared;
       	QImage image;
    	QRect rect;	
};

#endif
    
    

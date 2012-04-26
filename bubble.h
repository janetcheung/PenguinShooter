#ifndef BUBBLE_H
#define BUBBLE_H

#include <QImage>
#include <QRect>


class Bubble
{

	public: 
		Bubble();
		~Bubble();

	public:
		void startPosition(int, int);
		void resetState();
		void moveLeft(int);
		void moveRight(int);
		void moveTop(int);
		void moveBottom(int);
		void autoMove();
		void autoMoveRight();
		void autoMoveLeft();
		void setXDirL(int);
		void setXDirR(int);
    	void setYDir(int);
    	void setSpeed(int);
    	int getSpeed();
		void setDirection(char);
		char getDirection();
    	int getXDirL();
    	int getXDirR();
    	int getYDir();
		bool isMoving();
		void setMoving(bool);
		bool hasDisappeared();
		void setDisappeared(bool);
    	QRect getRect();
    	QImage & getImage();

  	private:
    		int speed;
    		int xdirL;
    		int ydir;
    		int xdirR;
    		int initX;
    		int initY;
			char direction;
    		bool moving;
			bool disappeared;
    		QImage image;
    		QRect rect;


};

#endif

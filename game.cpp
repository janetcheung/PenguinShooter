#include "game.h"
#include <QPainter>
#include <QGraphicsTextItem>
#include <QApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>


Game::Game(QWidget *parent)
    : QWidget(parent)
{
	setFocusPolicy(Qt::StrongFocus);
	
  life = 3;
  score = 0;
  level = 1;
  x = 0;
  y = 0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
	//setPalette(QPalette(QColor(255,255,255,255)));
	//setAutoFillBackground(true);
//create player, monsters, and bubbles
  player = new Player();
  Level1 = new level1();
  Level2 = new level2();
  Level3 = new level3();
  Level4 = new level4();
  for (int i = 0; i < 5; i++)
  	{
  	monster[i] = new Bull();
  	skeleton[i] = new Skeleton();
  	}
  robot = new Robot();
  UFO = new Laser();
  UFOBeam = new Beam();
  poop = new Poop();
  boss = new Boss();
  poison = new Poison();
  diamond = new Diamond();
  extraLife = new Life();
    skates = new powerupSkates();
  
  for (int i = 0; i < 50; i++)
	{
	bubble[i] = new Bubble();
	lightning[i] = new Lightning();
	bullet = new Bullet();
	}
	beam = new Beam();
  candy = new Candy();
  lightningPowerUp = new powerupLightning();

}

Game::~Game() {
 delete player;
 delete Level1;
 delete Level2;
 delete Level3;
 delete Level4;
 for (int i = 0; i < 5; i++)
 	{
 	delete monster[i];
 	delete skeleton[i];
 	}
 delete robot;
 delete boss;
 delete UFO;
 delete skates;
 delete poop;
 delete UFOBeam;
 for (int i = 0; i < 50; i++)
	{
	delete bubble[i];
	delete lightning[i];
	delete bullet;
	} 
delete beam;
 delete candy;
 delete lightningPowerUp;
 delete diamond;
 delete extraLife;
}

void Game::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  
  	if (gameOver)
	{
		QFont font("Verdana", 20, QFont::DemiBold);
		QFontMetrics fm(font);
		int textWidth = fm.width("Game Over");
		
		painter.setFont(font);
		int h = 500;
		int w = 600;
		
		painter.drawText((w/2)-textWidth/2,h/2, "Game Over");
	}
	else if (gameVictory)
	{
		QFont font("Verdana", 20, QFont::DemiBold);
		QFontMetrics fm(font);
		int textWidth = fm.width("Victory!");
		
		painter.setFont(font);
		int h = 500;
		int w = 600;
		
		painter.drawText((w/2)-textWidth/2, h/2, "Victory!");
	}
	else if (gameWon)
	{
		QFont font("Verdana", 20, QFont::DemiBold);
		QFontMetrics fm(font);
		int textWidth = fm.width("Next Level");
		
		painter.setFont(font);
		int h = 500;
		int w = 600;
		
		painter.drawText((w/2)-textWidth/2, h/2, "Next Level");
	}
	else
	{
  //LEVEL 1
  if (level == 1)
  	{	
  		painter.drawImage(Level1->getRect(),Level1->getImage());
  		for (int i = 0; i < 5; i++)
  		{
  		monster[i]->setAppeared(true);
  		skeleton[i]->setAppeared(false);
  		}
  		bullet->setDisappeared(true);
  		robot->setAppeared(true);
  		UFO->setAppeared(false);
  		UFO->setMoving(false);
  		UFOBeam->setDisappeared(true);
  		UFOBeam->setMoving(false);
  		poop->setDisappeared(true);
  		poop->setMoving(false);
  		boss->setAppeared(false);
  		boss->setMoving(false);
  		
  	}
  //LEVEL 2
  if (level == 2)
  	{ 	painter.drawImage(Level2->getRect(), Level2->getImage());
  		for (int i = 0; i < 5; i++)
  		{
  		monster[i]->setAppeared(true);
  		}
  		bullet->setDisappeared(true);
  		robot->setAppeared(true);
  		for (int i = 0; i < 2; i++)
  			skeleton[i]->setAppeared(true);
  		for (int i = 2; i < 5; i++)
  			skeleton[i]->setAppeared(false);
  		UFO->setAppeared(false);
  		UFO->setMoving(false);
  		UFOBeam->setDisappeared(true);
  		UFOBeam->setMoving(false);
  		poop->setDisappeared(true);
  		poop->setMoving(false);
  		boss->setAppeared(false);
  		boss->setMoving(false);
	}
  //LEVEL 3 
  if (level == 3)
  	{   painter.drawImage(Level3->getRect(), Level3->getImage());
  		for (int i = 0; i < 5; i++)
  		{
  		monster[i]->setAppeared(true);
  		skeleton[i]->setAppeared(true);
  		}
  		bullet->setDisappeared(true);
  		boss->setAppeared(false);
  		boss->setMoving(false);
  		robot->setAppeared(true);
  		poop->setDisappeared(true);
  		poop->setMoving(false);
  		UFO->setAppeared(true);
  	}
  //LEVEL 4(BOSS)
  if (level == 4)
  	{	painter.drawImage(Level4->getRect(), Level4->getImage());
  		beam->setDisappeared(true);
  		boss->setAppeared(true);
  		for (int i = 0; i < 5; i++)
  			{
  			monster[i]->setAppeared(true);
  			skeleton[i]->setAppeared(true);
  			}
  		UFO->setAppeared(true);
  	}
    //PLAYER AND BUBBLES
    painter.drawImage(player->getRect(), player->getImage());
    for (int i=0; i < 50; i++)
   {
     if (!bubble[i]->hasDisappeared() && !lightningPowerUp->isActive())
		{
		painter.drawImage(bubble[i]->getRect(), bubble[i]->getImage());		
		}
	 if (!lightning[i]->hasDisappeared() && lightningPowerUp->isActive())
		painter.drawImage(lightning[i]->getRect(), lightning[i]->getImage());
   }
   if (!bullet->hasDisappeared())
		painter.drawImage(bullet->getRect(), bullet->getImage());
   if (!beam->hasDisappeared())
   		painter.drawImage(beam->getRect(), beam->getImage());
   	if (!UFOBeam->hasDisappeared())
		painter.drawImage(UFOBeam->getRect(), UFOBeam->getImage());
	if (!poop->hasDisappeared())
		painter.drawImage(poop->getRect(), poop->getImage());
    //MONSTERS
    for (int i = 0; i < 5; i++)
    {
    	if (monster[i]->hasAppeared() && monster[i]->isMoving())
 		   painter.drawImage(monster[i]->getRect(), monster[i]->getImage());
 		if (skeleton[i]->hasAppeared() && skeleton[i]->isMoving())
    		painter.drawImage(skeleton[i]->getRect(), skeleton[i]->getImage());
	}
   	if (robot->hasAppeared() && robot->isMoving())
   		painter.drawImage(robot->getRect(), robot->getImage());
	if (UFO->hasAppeared() && UFO->isMoving())
		painter.drawImage(UFO->getRect(), UFO->getImage());
	if (boss->hasAppeared() && boss->isMoving())
		painter.drawImage(boss->getRect(), boss->getImage());
	
//POWERUPS
   	if (rand() % 3000 == 0)
			{
   			candy->setAppeared(true);
   			candy->count += 1;
   			}
   	else if (candy->hasAppeared() && candy->count >=1)
   		painter.drawImage(candy->getRect(), candy->getImage());
   		
   	if (rand() % 4000 == 0)
   			{
   			lightningPowerUp->count += 1;
   			lightningPowerUp->setAppeared(true);
   			}
   	else if (lightningPowerUp->hasAppeared() && lightningPowerUp->count >= 1)
   		painter.drawImage(lightningPowerUp->getRect(), lightningPowerUp->getImage());
	if (rand() % 1000 == 0)
   		{
   		skates->count += 1;
   		skates->setAppeared(true);
   		}
   	if (skates->hasAppeared() && skates->count >= 1)
   		painter.drawImage(skates->getRect(), skates->getImage());
   
   	if (rand() % 500 == 0)
   		{
   		poison->count += 1;
   		poison->setAppeared(true);
   		}
   	if (poison->hasAppeared() && poison->count >= 1)
   		painter.drawImage(poison->getRect(), poison->getImage());
   
   	if (rand() % 1000 == 0)
   		{
   		diamond->count += 1;
   		diamond->setAppeared(true);
   		}
   	if (diamond->hasAppeared() && diamond->count >= 1)
   		painter.drawImage(diamond->getRect(), diamond->getImage());

   	if (rand() % 5000 == 0)
	   	{
	   	extraLife->count += 1;
	   	extraLife->setAppeared(true);
		}
	if (extraLife->hasAppeared() && extraLife->count >= 1)
		painter.drawImage(extraLife->getRect(),extraLife->getImage());
  		
  }
}

void Game::timerEvent(QTimerEvent *event)
{	
for (int i = 0; i < 5; i++)
{
	if (monster[i]->isMoving())
  		monster[i]->autoMove();
  
	if (skeleton[i]->isMoving())
	{
  	skeleton[i]->compare(player->getRect().x(), player->getRect().y());
	}
}


if (boss->isMoving())
  {
   boss->autoMove();
     if (bullet->hasDisappeared() && (rand() % 500 == 1))
    		{	
    		boss->setShooting(true);
    		bullet->startPosition(boss->getRect().x(), boss->getRect().y());
    		bullet->setDisappeared(false);
    		bullet->setMoving(true);
    		}
      if (poop->hasDisappeared() == true && (rand() % 100 == 0))
      		{
      			boss->setShooting(true);
      			poop->startPosition(boss->getRect().x(), boss->getRect().y());
      			poop->setDisappeared(false);
      			poop->setMoving(true);
      		}
  }
if (robot->isMoving())
  { 
	robot->autoMove();
	
		if (beam->hasDisappeared() == true && (rand() % 10 == 0))
		{
			robot->setShooting(true);
			beam->startPosition(robot->getRect().x(), robot->getRect().y());
			beam->setDisappeared(false);
			beam->setMoving(true);
		}
  }

if (UFO->isMoving())
  {
  	UFO->compare(player->getRect().x(), player->getRect().y());
  	if (UFOBeam->hasDisappeared() == true && (rand() % 10 == 0))
  		{
  			UFO->setShooting(true);
  			UFOBeam->startPosition(UFO->getRect().x(), UFO->getRect().y());
  			UFOBeam->setDisappeared(false);
  			UFOBeam->setMoving(true);
		}
  }
for (int i = 0; i < 50; i++)
{
  if (!bubble[i]->hasDisappeared()) 
  {
	if (bubble[i]->getDirection() == 'l' && bubble[i]->isMoving())
		bubble[i]->autoMoveLeft();
	else if (bubble[i]->getDirection() == 'r' && bubble[i]->isMoving())
		bubble[i]->autoMoveRight();
  }
  
  if (!lightning[i]->hasDisappeared())
  {
  	if (lightning[i]->getDirection() == 'l' && lightning[i]->isMoving())
  		lightning[i]->autoMoveLeft();
  	else if (lightning[i]->getDirection() == 'r' && lightning[i]->isMoving())
  		lightning[i]->autoMoveRight();
  }
}
  if (!bullet->hasDisappeared() && bullet->isMoving())
  {
  	bullet->compare(player->getRect().x(), player->getRect().y());
  }
  if (!UFOBeam->hasDisappeared() && UFOBeam->isMoving())
  {
  	UFOBeam->autoMoveDown();
  }
  if (!poop->hasDisappeared() && poop->isMoving())
  {
  	poop->autoMoveDown();
  }
  
  if (!beam->hasDisappeared() && beam->isMoving())
  {	
  		beam->autoMoveRight();
  }
  
  
  checkCollision();
  checkField();
  repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{	int x = player->getRect().x();
	int y = player->getRect().y();
	int s = player->getSpeed();
    switch (event->key()) {
    case Qt::Key_R: {
			resetGame();
		    }
			break;
	case Qt::Key_T: {
			levelReset();
			}
			break;
	case Qt::Key_N: {
		    if (gameVictory)
		    	stopGame();
			if (level >=1 && level < 5)
		    	victory();
		    }
		    break;
    case Qt::Key_Left:
       {  
          player->moveLeft(x-s);
        break;
       }
    case Qt::Key_Right:
        { 
           player->moveRight(x+s);
        }
        break;
    case Qt::Key_Up:
        { 
            player->moveUp(y-s);
        }
        break;
    case Qt::Key_Down:
        { 
           player->moveDown(y+s);
        }
        break;
    case Qt::Key_P:
        { 
          pauseGame();
        }
        break;
    case Qt::Key_Return:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    case Qt::Key_Shift:
	{
		
	int temp=0;
	bool check = false;		
		if (!lightningPowerUp->isActive())
		{	
			for (int i = 0; i < 50; i++)  //check if bubbles are available
			{
			if (!check)
			  {	if (bubble[i]->hasDisappeared())
					{
					temp = i;
					check = true;
					}
			  }
			}		
			player->setShooting(true);
			bubble[temp]->setDirection(player->getDirection());
			bubble[temp]->startPosition(player->getRect().x(), player->getRect().y());
			bubble[temp]->setDisappeared(false);
			bubble[temp]->setMoving(true);
		}
		else if (lightningPowerUp->isActive())
		{
			for (int i = 0; i < 50; i++)  //check if bubbles are available
				{
				if (!check)
				  {	if (lightning[i]->hasDisappeared())
						{
						temp = i;
						check = true;
						}
				  }
				}		
				player->setShooting(true);
				lightning[temp]->setDirection(player->getDirection());
				lightning[temp]->startPosition(player->getRect().x(), player->getRect().y());	
			lightning[temp]->setDisappeared(false);
			lightning[temp]->setMoving(true);
		}
	
	}
	break;
    default:
        QWidget::keyPressEvent(event);
    }
}

		
//CHECK IF FIELD IS EMPTY
void Game::checkField()
{ int m = 0;
	if (level == 1)
	{
		for  (int i = 0; i < 5; i++)
		{
			if (!monster[i]->isMoving())
				m++;
		}
		if (!robot->isMoving())
			m++;

		if (m == 6)
	   		victory();
	}
	else if (level == 2 )
	{
		for (int i = 0; i < 5; i++)
		{
			if (!monster[i]->isMoving())
				m++;
		}
		if (!robot->isMoving())
			m++;
		for (int i = 0; i < 2; i++)
		{
			if (!skeleton[i]->isMoving())
				m++;
		}
	
		if (m == 8)
			victory();
	}
	else if (level == 3)
	{
		for (int i = 0; i < 5; i++)
		{
			if (!monster[i]->isMoving())
				m++;
			if (!skeleton[i]->isMoving())
				m++;
		}
		if (!robot->isMoving())
			m++;
		if (!UFO->isMoving())
			m++;
		if (m == 12)
			victory();
	}
	else if (level == 4)
	{
		for (int i = 0; i < 5; i++)
		{
			if (!monster[i]->isMoving())
				m++;
			if (!skeleton[i]->isMoving())
				m++;
		}
		if (!UFO->isMoving())
			m++;
		if (!boss->isMoving())
			m++;
		if (m == 12)
			victoryGame();
	}
	else
	{
		victoryGame();
	}
}
			
void Game::checkCollision()
{//MONSTER INTERSECTS BUBBLE
	for (int i = 0; i < 5; i++)
	{
  	if ((monster[i]->getRect()).intersects(bubble[0]->getRect()) && (monster[i]->isMoving()) && (monster[i]->hasAppeared()) && !bubble[0]->hasDisappeared()) //for first bubble
	{
	if (!monster[i]->isDead()){
		bubble[0]->setMoving(false);
		bubble[0]->setDisappeared(true);
		monster[i]->setMoving(false);
		monster[i]->setAppeared(false);
		monster[i]->setDead(true);
		score += 100;
		emit scoreChange(score);}
	}
	}
  for (int k = 0; k < 5; k++)
  {
  for (int i = 1; i < 50; i++)
  {
  if ((monster[k]->getRect()).intersects(bubble[i]->getRect())&& (monster[k]->isMoving()) && (monster[k]->hasAppeared()) && !bubble[i]->hasDisappeared()) //if monster hit by bubble
	{
	if (!monster[k]->isDead()){	
		//monsterCount--;
		for (int j = 0; j < i; j++) //for all previous bubbles
		{
		  {
		  if (bubble[j]->isMoving()) //if they are still moving
		  	{
		  	bubble[i]->setMoving(false); //current bubble freezes
		  	bubble[i]->setDisappeared(true);
		  	}
		  else if (!bubble[j]->isMoving())
			{
			bubble[i]->setMoving(true); //else if they are frozen, current bubble keeps moving
			}
		  }
		monster[k]->setMoving(false);
		monster[k]->setDead(true);
		score += 150;
		emit scoreChange(score);
		}
	 }
	}	
  }
  }	
//SKELETON INTERSECTS BUBBLE
for (int i = 0; i < 5; i++)
  {
  	if ((skeleton[i]->getRect()).intersects(bubble[0]->getRect()) && (skeleton[i]->isMoving()) && (skeleton[i]->hasAppeared()) && !bubble[0]->hasDisappeared()) //for first bubble
		{

		bubble[0]->setMoving(false);
		bubble[0]->setDisappeared(true);
		skeleton[i]->setMoving(false);
		skeleton[i]->setAppeared(false);
		skeleton[i]->setDead(true);

		score += 150;
		emit scoreChange(score);
		}
  }
  for (int k = 0; k < 5; k++)
  {
  for (int i = 1; i < 50; i++)
  {
  if ((skeleton[k]->getRect()).intersects(bubble[i]->getRect())&& (skeleton[k]->isMoving()) && (skeleton[i]->hasAppeared()) && !bubble[i]->hasDisappeared()) //if monster hit by bubble
	{	
		for (int j = 0; j < i; j++) //for all previous bubbles
		{
		  {
		  if (bubble[j]->isMoving()) //if they are still moving
		  	{
		  	bubble[i]->setMoving(false); //current bubble freezes
		  	bubble[i]->setDisappeared(true);
		  	}
		  else if (!bubble[j]->isMoving())
			{
			bubble[i]->setMoving(true); //else if they are frozen, current bubble keeps moving
			}
		  }
		skeleton[k]->setMoving(false);
		skeleton[k]->setDead(true);
		score += 150;
		emit scoreChange(score);
		}
	}
  }
  }	
//ROBOT INTERSECTS BUBBLE
if ((robot->getRect()).intersects(bubble[0]->getRect()) && (robot->isMoving()) && (robot->hasAppeared()) && !bubble[0]->hasDisappeared()) //for first bubble
	{
	bubble[0]->setMoving(false);
	bubble[0]->setDisappeared(true);
	robot->setMoving(false);
	robot->setAppeared(false);
	robot->setDead(true);
	score += 100;
	emit scoreChange(score);
	}
for (int i = 1; i < 50; i++)
  {
  if ((robot->getRect()).intersects(bubble[i]->getRect())&& (robot->isMoving()) && (robot->hasAppeared()) && !bubble[i]->hasDisappeared()) //if monster hit by bubble
	{	
		for (int j = 0; j < i; j++) //for all previous bubbles
		{
		  {
		  if (bubble[j]->isMoving()) //if they are still moving
		  	{
		  	bubble[i]->setMoving(false); //current bubble freezes
		  	bubble[i]->setDisappeared(true);
		  	}
		  else if (!bubble[j]->isMoving())
			{
			bubble[i]->setMoving(true); //else if they are frozen, current bubble keeps moving
			}
		  }
		robot->setMoving(false);
	  	robot->setDead(true);
	  	score += 100;
	  	emit scoreChange(score);
		}
	}
}

//UFO INTERSECTS BUBBLE
if ((UFO->getRect()).intersects(bubble[0]->getRect()) && (UFO->isMoving()) && (UFO->hasAppeared()) && !bubble[0]->hasDisappeared() && level == 3) //for first bubble
	{	
	bubble[0]->setMoving(false);
	bubble[0]->setDisappeared(true);
	UFO->setMoving(false);
	UFO->setAppeared(false);
	UFO->setDead(true);
	score += 100;
	emit scoreChange(score);
	}
for (int i = 1; i < 50; i++)
  {
  if ((UFO->getRect()).intersects(bubble[i]->getRect())&& (UFO->isMoving()) && (UFO->hasAppeared()) && !bubble[i]->hasDisappeared()) //if monster hit by bubble
	{	
		for (int j = 0; j < i; j++) //for all previous bubbles
		{
		  {
		  if (bubble[j]->isMoving()) //if they are still moving
		  	{
		  	bubble[i]->setMoving(false); //current bubble freezes
		  	bubble[i]->setDisappeared(true);
		  	}
		  else if (!bubble[j]->isMoving())
			{
			bubble[i]->setMoving(true); //else if they are frozen, current bubble keeps moving
			}
		  }
		UFO->setMoving(false);
	  	UFO->setDead(true);
	  	score += 100;
	  	emit scoreChange(score);
		}
	}
}
//BOSS INTERSECTS BUBBLE
if ((boss->getRect()).intersects(bubble[0]->getRect()) && (boss->isMoving()) && (boss->hasAppeared()) && !bubble[0]->hasDisappeared()) //for first bubble
	{
	if ((boss->getLife()) > 0)
		{
		int x = boss->getLife();
		x--;
		boss->setLife(x);
		}
	else if ((boss->getLife()) == 0)
		{	
			bubble[0]->setMoving(false);
			bubble[0]->setDisappeared(true);
			boss->setMoving(false);
			boss->setAppeared(false);
			boss->setDead(true);
			score += 1000;
			emit scoreChange(score);
		}
	}
for (int i = 1; i < 50; i++)
  {
  if ((boss->getRect()).intersects(bubble[i]->getRect())&& (boss->isMoving()) && (boss->hasAppeared()) && !bubble[i]->hasDisappeared()) //if monster hit by bubble
	{	
		for (int j = 0; j < i; j++) //for all previous bubbles
		{
		  {
		  if (bubble[j]->isMoving()) //if they are still moving
		  	{
		  	bubble[i]->setMoving(false); //current bubble freezes
		  	bubble[i]->setDisappeared(true);
		  	}
		  else if (!bubble[j]->isMoving())
			{
			bubble[i]->setMoving(true); //else if they are frozen, current bubble keeps moving
			}
		  }
		boss->setMoving(false);
	  	boss->setDead(true);
		}
	}
}
//MONSTER INTERSECTS LIGHTNING
	for (int i = 0; i < 5; i++)
	{
    if ((monster[i]->getRect()).intersects(lightning[0]->getRect()) && (monster[i]->isMoving()) && (monster[i]->hasAppeared()) && !lightning[0]->hasDisappeared()) //for first lightning
		{
		monster[i]->setMoving(false);
		monster[i]->setDead(true);
		score += 100;
		emit scoreChange(score);
		}
	}
  for (int k = 0; k < 5; k++)
  {
  for (int i = 1; i < 50; i++)
  {
  if ((monster[k]->getRect()).intersects(lightning[i]->getRect())&& (monster[k]->isMoving()) && (monster[k]->hasAppeared())&& !lightning[i]->hasDisappeared()) //if monster hit by lightning
	{	
		for (int j = 0; j < i; j++) //for all previous lightnings
		{
		  {
		  if (!lightning[j]->isMoving())
			{
			lightning[i]->setMoving(true); //else if they are frozen, current lightning keeps moving
			}
		  }
		monster[k]->setMoving(false);
		monster[k]->setDead(true);
		score += 100;
		emit scoreChange(score);
		}
	}	
  }	
  }
  	//SKELETON HITS LIGHTNING
for (int i = 0; i < 5; i++)
	{
    if ((skeleton[i]->getRect()).intersects(lightning[0]->getRect()) && (skeleton[i]->isMoving()) && (skeleton[i]->hasAppeared())&& !lightning[0]->hasDisappeared()) //for first lightning
		{

		skeleton[i]->setMoving(false);
		skeleton[i]->setDead(true);
		score += 250;
		emit scoreChange(score);
		}
	}
  for (int k = 0; k < 5; k++)
  {
  for (int i = 1; i < 50; i++)
  {
  if ((skeleton[k]->getRect()).intersects(lightning[i]->getRect())&& (skeleton[k]->isMoving()) && (skeleton[k]->hasAppeared()) && !lightning[i]->hasDisappeared()) //if monster hit by lightning
	{	
		for (int j = 0; j < i; j++) //for all previous lightnings
		{
		  {
		  if (!lightning[j]->isMoving())
			{
			lightning[i]->setMoving(true); 
			}
		  }
		skeleton[k]->setMoving(false);
		skeleton[k]->setDead(true);
		score += 250;
		emit scoreChange(score);

		}
	}	
  }	
  }
  
//ROBOT HITS LIGHTNING
if ((robot->getRect()).intersects(lightning[0]->getRect()) && (robot->isMoving()) && (robot->hasAppeared())&& !lightning[0]->hasDisappeared()) //for first lightning
		{
		robot->setMoving(false);
		robot->setDead(true);
		score += 200;
		emit scoreChange(score);
		}
for (int i = 1; i < 50; i++)
{
  if ((robot->getRect()).intersects(lightning[i]->getRect())&& (robot->isMoving()) && (robot->hasAppeared())&& !lightning[i]->hasDisappeared()) //if monster hit by lightning
	{	
		for (int j = 0; j < 50; j++) //for all previous lightnings
		{
		  {
		  if (!lightning[j]->isMoving())
			{
			lightning[j]->setMoving(true); //else if they are frozen, current lightning keeps moving
			}
		  }
		robot->setMoving(false);
		robot->setDead(true);
		score += 200;
		emit scoreChange(score);
		}
	}
}

//UFO INTERSECTS LIGHTNING
if ((UFO->getRect()).intersects(lightning[0]->getRect()) && (UFO->isMoving()) && (UFO->hasAppeared())&& !lightning[0]->hasDisappeared()) //for first lightning
		{
		UFO->setMoving(false);
		UFO->setDead(true);
		score += 100;
		emit scoreChange(score);
		}
for (int i = 1; i < 50; i++)
{
  if ((UFO->getRect()).intersects(lightning[i]->getRect())&& (UFO->isMoving()) && (UFO->hasAppeared())&& !lightning[i]->hasDisappeared()) //if monster hit by lightning
	{	
		for (int j = 0; j < 50; j++) //for all previous lightnings
		{
		  {
		  if (!lightning[j]->isMoving())
			{
			lightning[j]->setMoving(true); //else if they are frozen, current lightning keeps moving
			}
		  }
		UFO->setMoving(false);
		UFO->setDead(true);
		score += 100;
		emit scoreChange(score);
		}
	}
}

//BOSS INTERSECTS LIGHTNING
if ((boss->getRect()).intersects(lightning[0]->getRect()) && (boss->isMoving()) && (boss->hasAppeared())&& !lightning[0]->hasDisappeared()) //for first lightning
		{
		boss->setMoving(false);
		boss->setDead(true);
		score += 100;
		emit scoreChange(score);
		}
for (int i = 1; i < 50; i++)
{
  if ((boss->getRect()).intersects(lightning[i]->getRect())&& (boss->isMoving()) && (boss->hasAppeared())&& !lightning[i]->hasDisappeared()) //if monster hit by lightning
	{	
		for (int j = 0; j < 50; j++) //for all previous lightnings
		{
		  {
		  if (!lightning[j]->isMoving())
			{
			lightning[j]->setMoving(true); //else if they are frozen, current lightning keeps moving
			}
		  }
		boss->setMoving(false);
		boss->setDead(true);
		score += 100;
		emit scoreChange(score);
		}
	}
}
  //monster hits player
 for (int i = 0; i < 5; i++)
 {
 if ((player->getLife()) <= 0)
 	stopGame();
 if ((monster[i]->getRect()).intersects(player->getRect()) && monster[i]->isMoving() && (monster[i]->hasAppeared()))
  {
	life--;
	emit lifeChange(life);
	player->resetState();
	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
   }
  
 if ((skeleton[i]->getRect()).intersects(player->getRect()) && skeleton[i]->isMoving() && (skeleton[i]->hasAppeared()))
  {
	life--;
	emit lifeChange(life);
	player->resetState();
	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
  }
 }
 
 if ((robot->getRect()).intersects(player->getRect()) && robot->isMoving() && robot->hasAppeared())
 {
 	life--;
 	emit lifeChange(life);
 	player->resetState();
 	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
	
 } 
 
  if ((boss->getRect()).intersects(player->getRect()) && boss->isMoving() && boss->hasAppeared())
 {
 	life--;
 	emit lifeChange(life);
 	player->resetState();
 	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
	
 } 
 if ((UFO->getRect()).intersects(player->getRect()) && UFO->isMoving() && UFO->hasAppeared())
 {
 	life--;
 	emit lifeChange(life);
 	player->resetState();
 	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
 }
 
 if ((boss->getRect()).intersects(player->getRect()) && boss->isMoving() && boss->hasAppeared())
 {
 	life--;
 	emit lifeChange(life);
 	player->resetState();
 	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
 }

  //monster projectile hits player
	if ((beam->getRect()).intersects(player->getRect()) && beam->isMoving() && (!beam->hasDisappeared()))
 {
	life--;
	emit lifeChange(life);
	player->resetState();
	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
 }
	if ((UFOBeam->getRect()).intersects(player->getRect()) && UFOBeam->isMoving() && (!UFOBeam->hasDisappeared()))
  {
	life--;
 	emit lifeChange(life);
 	UFOBeam->setDisappeared(true);
 	player->resetState();
 	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	 {
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	 }
  }
  	if ((poop->getRect()).intersects(player->getRect()) && poop->isMoving() && (!poop->hasDisappeared()))
  	{
  	  life--;
  	  emit lifeChange(life);
  	  poop->setDisappeared(true);
  	  player->resetState();
  	  candy->setActive(false);
  	  skates->setActive(false);
  	  poison->setActive(false);
  	  lightningPowerUp->setActive(false);
  	  player->setLife(life);
  	  for (int i = 0; i < 50; i++)
  	  {
  	  	bubble[i]->setSpeed(3);
  	  	lightning[i]->setSpeed(3);
  	  }
  	}
  	
	if ((bullet->getRect()).intersects(player->getRect()) && bullet->isMoving() && (!bullet->hasDisappeared()))
 {
	life--;
	emit lifeChange(life);
	bullet->setDisappeared(true);
	player->resetState();
	candy->setActive(false);
	skates->setActive(false);
	poison->setActive(false);
	lightningPowerUp->setActive(false);
	player->setLife(life);
	for (int i = 0; i < 50; i++)
	{
		bubble[i]->setSpeed(3);
		lightning[i]->setSpeed(3);
	}
 }
	
  //player hits power-up
//CANDY POWERUP
if ((player->getRect()).intersects(candy->getRect()) && candy->hasAppeared())
	{ 
	candy->setActive(true);
	candy->setAppeared(false);
	}
	if (candy->isActive())
	{
		for (int i = 0; i < 50; i++)
		{
			bubble[i]->setSpeed(10);
			lightning[i]->setSpeed(10);
		}
	}

//SKATES POWERUP
if ((player->getRect()).intersects(skates->getRect()) && skates->hasAppeared())
	{
	skates->setActive(true);
	skates->setAppeared(false);
	}
	if (skates->isActive())
	{
		player->setSpeed(10);
	}

//POISON POWERUP
if ((player->getRect()).intersects(poison->getRect()) && poison->hasAppeared())
	{
	poison->setActive(true);
	poison->setAppeared(false);
	}
  if (poison->isActive())
	{
		player->setSpeed(3);
	}

//LIGHTNING POWERUP
if ((player->getRect()).intersects(lightningPowerUp->getRect()) && lightningPowerUp->hasAppeared())
	{
	lightningPowerUp->setActive(true);
	lightningPowerUp->setAppeared(false);
	}

//LIFE POWERUP
if ((player->getRect()).intersects(extraLife->getRect()) && extraLife->hasAppeared())
	{
	life++;
	player->setLife(life);
	emit lifeChange(life);
	extraLife->setAppeared(false);
	}
//DIAMOND POWERUP
if ((player->getRect()).intersects(diamond->getRect()) && diamond->hasAppeared())
	{
	score += 500;
	emit scoreChange(score);
	diamond->setAppeared(false);
	}

  
}

void Game::startGame()
{ 
  if (!gameStarted) {
    player->resetState();
    for (int i = 0; i < 5; i++)
	{
	monster[i]->resetState();
	skeleton[i]->resetState();
	}
	for (int i = 0; i < 50; i++)
	{
	bubble[i]->resetState();
	lightning[i]->resetState();
	}
	beam->resetState();
	robot->resetState();
	UFO->resetState();
	UFOBeam->resetState();
	boss->resetState();
	poop->resetState();
	
    gameOver = FALSE; 
    gameWon = FALSE; 
    gameStarted = TRUE;
    gameVictory = FALSE;

    emit scoreChange(score);
    emit levelChange(level);
    emit lifeChange(life);
    timerId = startTimer(10);  
  }
}

void Game::resetGame()
{ stopGame();
  nextLevelReset();
  player->resetState();
  player->setLife(3);
  level = 1;
  life = 3;
  emit lifeChange(life);
  emit levelChange(level);
}

void Game::nextLevelReset()
{
	if (!gameStarted)
	{
	for (int i = 0; i < 5; i++)
		{
		monster[i]->resetState();
		skeleton[i]->resetState();
		}
	for (int i = 0; i < 50; i++)
		{
		beam->resetState();
		}
	robot->resetState();
	UFO->resetState();
	UFOBeam->resetState();
	boss->resetState();
	bullet->resetState();
	poop->resetState();
	}
}

void Game::levelReset()
{
	for (int i = 0; i < 5; i++)
		{
		monster[i]->resetState();
		skeleton[i]->resetState();
		}
	for (int i = 0; i < 50; i++)
		{
		beam->resetState();
		}
	 player->resetState();
  	player->setLife(3);
  	score = 0;
  	life = 3;
  	emit scoreChange(score);
  	emit lifeChange(life);
	robot->resetState();
	UFO->resetState();
	UFOBeam->resetState();
	bullet->resetState();
	boss->resetState();
	poop->resetState();
}

void Game::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId); 
   }
}

void Game::stopGame()
{
  killTimer(timerId);    
  gameOver = TRUE;      
  gameStarted = FALSE;
  gameVictory = FALSE;
  level = 0;
  life = 0;
  score = 0;
}

void Game::victoryGame()
{
	killTimer(timerId);
	gameWon= TRUE;
	gameStarted = FALSE;
	gameVictory = TRUE;
	level = 0;
	emit levelChange(level);
}

void Game::victory()
{
  killTimer(timerId);
  gameWon = TRUE;  
  gameStarted = FALSE;
  gameVictory = FALSE;
  level++;
  emit levelChange(level);
}


#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "monster.h"
#include "monsterBull.h"
#include "monsterSkeleton.h"
#include "monsterRobot.h"
#include "monsterLaser.h"
#include "bubble.h"
#include "bubbleBeam.h"
#include "bubblePoop.h"
#include "bubbleBullet.h"
#include "powerup.h"
#include "powerupCandy.h"
#include "powerupSkates.h"
#include "powerupPoison.h"
#include "powerupLightning.h"
#include "bubbleLightning.h"
#include "powerupDiamonds.h"
#include "powerupLife.h"
#include "monsterBoss.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include <QImage>
#include <QRect>
#include <QWidget>
#include <QKeyEvent>
#include <QtGui>
#include <QFrame>
#include <QGraphicsTextItem>

class Game : public QWidget
{
  Q_OBJECT

  public:
    Game(QWidget *parent = 0);
    ~Game();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    
    void victory();
    void checkCollision();
    void checkField();
    Player *player;
    Bull *monster[5];
    Skeleton *skeleton[5];
    Robot *robot;
    Bubble *bubble[50];
    Beam *beam;
    Laser *UFO;
    Beam *UFOBeam;
    Bullet *bullet;
    Boss *boss;
    Poop *poop;
    Lightning *lightning[50];
    Candy *candy;
    powerupSkates *skates;
    Poison *poison;
    Diamond *diamond;
    Life *extraLife;
    powerupLightning *lightningPowerUp;
    level1 *Level1;
    level2 *Level2;
    level3 *Level3;
    level4 *Level4;
    
  public slots:
    void startGame();
    void pauseGame();
    void stopGame();
    void resetGame();
    void nextLevelReset();
    void levelReset();
    void victoryGame();
    
  signals:
  	void scoreChange(int score);
  	void levelChange(int level);
  	void lifeChange(int life);
  	
  private:
    int x;
    int y;
    int life;
    int score;
    int level;
    int bubbleCount;
    int timerId;
    bool gameVictory;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;


};

#endif

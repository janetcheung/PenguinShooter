#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QtGui>
#include <QFrame>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>

#include "game.h"

class Game;

class gameWindow : public QWidget
{
	Q_OBJECT

	public:
		gameWindow();
		
	private:
		QLabel *createLabel(const QString &text);
		Game *game;
		QLCDNumber *Score;
		QLCDNumber *Level;
		QLCDNumber *Lives;
		QPushButton *startButton;
		QPushButton *quitButton;
		QPushButton *pauseButton;
};

#endif

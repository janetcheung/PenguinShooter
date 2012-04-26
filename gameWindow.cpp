#include <QtGui>
#include <QDesktopWidget>
#include <QApplication>
#include <QGridLayout>
#include "game.h"
#include "gameWindow.h"

gameWindow::gameWindow()
{
	game = new Game(this);
	
	Score = new QLCDNumber(5);
	Score->setSegmentStyle(QLCDNumber::Filled);
	Level = new QLCDNumber(2);
	Level->setSegmentStyle(QLCDNumber::Filled);
	Lives = new QLCDNumber(2);
	Lives->setSegmentStyle(QLCDNumber::Filled);
	
	startButton =new QPushButton(tr("&Start"));
	startButton->setFocusPolicy(Qt::NoFocus);
	quitButton = new QPushButton(tr("&Quit"));
	quitButton->setFocusPolicy(Qt::NoFocus);
	pauseButton = new QPushButton(tr("&Pause"));
	pauseButton->setFocusPolicy(Qt::NoFocus);
	
	connect(startButton, SIGNAL(clicked()), game, SLOT(startGame()));
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pauseButton, SIGNAL(clicked()), game, SLOT(pauseGame()));
    connect(game, SIGNAL(scoreChange(int)), Score, SLOT(display(int)));
    connect(game, SIGNAL(levelChange(int)), Level, SLOT(display(int)));
    connect(game, SIGNAL(lifeChange(int)), Lives, SLOT(display(int)));
    
    QGridLayout *layout = new QGridLayout;
    
    layout->addWidget(game, 0, 0, 10, 3, 0);
    layout->addWidget(Level, 11, 0, 0);
    layout->addWidget(Score, 11, 1, 0);
    layout->addWidget(Lives, 11, 2, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 12, 0, 0);
    layout->addWidget(createLabel(tr("SCORE")), 12, 1, 0);
    layout->addWidget(createLabel(tr("LIVES")), 12, 2, 0);
    layout->addWidget(startButton, 13, 0, 0);
    layout->addWidget(pauseButton, 13, 1, 0);
    layout->addWidget(quitButton, 13, 2, 0);
    layout->setRowStretch(0, 30);
    layout->setRowStretch(11, 3);
    layout->setRowStretch(12, 0);
    layout->setRowStretch(13, 3);
    
    setLayout(layout);
    
    setWindowTitle(tr("Penguin Shooter"));
    //resize(500, 600);
    setFixedSize(530, 740);
}

/*void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 500;
  int HEIGHT = 600;
  

QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth); //- WIDTH) / 2;
  y = (screenHeight);// - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}*/

QLabel *gameWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}


#include "game.h"
#include "gameWindow.h"

#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 500;
  int HEIGHT = 600;
  

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  //Game window;
  gameWindow window;
 // window.setWindowTitle("Bubble Bobble");
  window.show();
 // center(window);

  return app.exec();
}

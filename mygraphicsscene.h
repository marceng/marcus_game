#ifndef MY_GRAPHICS_SCENE_H
#define MY_GRAPHICS_SCENE_H

#include <QGraphicsScene>

class MainWindow;

class MyGraphicsScene : public QGraphicsScene
	{
	public:
		MyGraphicsScene(MainWindow *p);
	
   protected:
   	void keyReleaseEvent(QKeyEvent *event);
   	
   private:
   	MainWindow *parent;
	};

#endif

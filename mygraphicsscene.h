#ifndef MY_GRAPHICS_SCENE_H
#define MY_GRAPHICS_SCENE_H

#include <QGraphicsScene>

class MainWindow;

class MyGraphicsScene : public QGraphicsScene
	{
	public:
		/** The constructor for MyGraphicsScene*/
		MyGraphicsScene(MainWindow *p);
	
   protected:
   	/** Method that overrides default keyReleaseEvent*/
   	void keyReleaseEvent(QKeyEvent *event);
   	
   private:
   	MainWindow *parent;
	};

#endif

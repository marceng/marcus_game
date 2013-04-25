#include "mygraphicsscene.h"
#include "mainwindow.h"

/** Constructor for the MyGraphicsScene object
 	* @param MainWindow* a pointer to the parent window
 	* @return nothing
 	*/
MyGraphicsScene::MyGraphicsScene(MainWindow *p)
	{
	parent = p;
	}

/** A method that intercepts key events and passes them to the main window
 	* @param QKeyEvent* a keystroke event
 	* @return nothing
 	*/
void MyGraphicsScene::keyReleaseEvent(QKeyEvent *event)
	{
   QGraphicsScene::keyReleaseEvent(event);

   if(event->key() == Qt::Key_Space)
   	{
   	parent->spacePressed();
   	}
   else if(event->key() == Qt::Key_P)
   	{
   	parent->pause();
   	}
	}

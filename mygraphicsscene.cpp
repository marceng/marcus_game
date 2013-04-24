#include "mygraphicsscene.h"
#include "mainwindow.h"

MyGraphicsScene::MyGraphicsScene(MainWindow *p)
	{
	parent = p;
	}

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

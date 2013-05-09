/*
Copyright (C) 2013  MARCUS ENG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

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

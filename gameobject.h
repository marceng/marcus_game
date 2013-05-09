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

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QtGui>
#include <cmath>

class GameObject : public QGraphicsPixmapItem
	{
	public:
		/** Constructor to create an object*/
		GameObject(QPixmap *i, char o, double x, double y, double lb, double rb, bool direction, double speed);
		/** Sets the X position*/
		void setX( double x );
		/** Sets the Y position*/
		void setY( double y );
		/** Returns a char to let program know what object it is*/
		char getObject();
		/** Returns x coordinate*/
	 	double getX();
	 	/** Returns y coordinate*/
		double getY();
		/** Returns object's width*/
		double getWidth();
		/** Returns object's height*/
		double getHeight();
		/** Used to increase movement of objects*/
		void speedUp();
		/** Function to handle object's move*/
		virtual void move() = 0;

	protected:
		char obj;
		double x;
		double y;
		double width;
		double height;
		double leftBound;
		double rightBound;
		bool isLeft;
		double currentSpeed;
		
		/** Checks the objects direction to handle image*/
		void handleDirection();
		/** Flips direction of image on call*/
		void flipImage();
	};

#endif

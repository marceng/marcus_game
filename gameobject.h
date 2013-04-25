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

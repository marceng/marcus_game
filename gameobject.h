#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QtGui>
#include <cmath>

class GameObject : public QGraphicsPixmapItem
	{
	public:
		GameObject(QPixmap *i, char o, double x, double y, double lb, double rb, bool direction);
		void setX( double x );
		void setY( double y );
		char getObject();
	 	double getX();
		double getY();
		double getWidth();
		double getHeight();
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
		
		void handleDirection();
		void flipImage();
	};

#endif

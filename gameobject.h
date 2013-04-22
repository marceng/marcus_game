#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QtGui>

class GameObject : public QGraphicsPixmapItem
	{
	public:
		GameObject(QPixmap *i, double x, double y, double lb, double rb, bool direction);
		void setX( double x );
		void setY( double y );
	 	double getX();
		double getY();
		double getWidth();
		double getHeight();
		virtual void move() = 0;

	protected:
		double x;
		double y;
		double width;
		double height;
		double leftBound;
		double rightBound;
		bool isLeft;
		
		void flipImage();
	};

#endif

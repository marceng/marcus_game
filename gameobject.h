#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QtGui>

class GameObject : public QGraphicsPixmapItem
	{
	public:
		GameObject(QPixmap *i, int x, int y, int lb, int rb, bool direction);
		void setX( int x );
		void setY( int y );
	 	int getX();
		int getY();
		virtual void move() = 0;

	protected:
		int x;
		int y;
		int width;
		int height;
		int leftBound;
		int rightBound;
		bool isLeft;
	};

#endif

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QtGui>

class GameObject : public QGraphicsPixmapItem
	{
	public:
		GameObject(QPixmap *i, double x, double y, double w, double h);
		void setPixmap(QPixmap *i);
		void setX( int x );
		void setY( int y );
	 	int getX();
		int getY();
		virtual void move() = 0;

	protected:
		QPixmap *image;
		int x;
		int y;
		int width;
		int height;
	};

#endif

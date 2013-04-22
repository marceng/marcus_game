#include "gameobject.h"

GameObject::GameObject(QPixmap *i, int x_, int y_, int lb, int rb, bool direction) : 
	QGraphicsPixmapItem(*i)
	{
	QGraphicsPixmapItem::setPos(x_, y_);
	
	x = x_;
	y = y_;
	width = i->width();
	height = i->height();
	
	leftBound = lb;
	rightBound = rb;
	isLeft = direction;
	}

void GameObject::setX( int x_ )
	{
	x = x_;
	QGraphicsPixmapItem::setX(x_);
	}
	
void GameObject::setY( int y_ )
	{
	y = y_;
	QGraphicsPixmapItem::setY(y_);
	}
	
int GameObject::getX()
	{
	return x;
	}

int GameObject::getY()
	{
	return y;
	}

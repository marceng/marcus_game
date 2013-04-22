#include "gameobject.h"

GameObject::GameObject(QPixmap *i, char o, double x_, double y_, double lb, double rb, bool direction) : 
	QGraphicsPixmapItem(*i)
	{
	QGraphicsPixmapItem::setPos(x_, y_);
	
	obj = o;
	x = x_;
	y = y_;
	width = i->width();
	height = i->height();
	
	leftBound = lb;
	rightBound = rb;
	isLeft = direction;
	
	if(!direction)
		{
		flipImage();
		}
	}

void GameObject::setX( double x_ )
	{
	x = x_;
	QGraphicsPixmapItem::setX(x_);
	}
	
void GameObject::setY( double y_ )
	{
	y = y_;
	QGraphicsPixmapItem::setY(y_);
	}

char GameObject::getObject()
	{
	return obj;
	}

double GameObject::getX()
	{
	return x;
	}

double GameObject::getY()
	{
	return y;
	}

double GameObject::getWidth()
	{
	return width;
	}

double GameObject::getHeight()
	{
	return height;
	}

void GameObject::handleDirection()
	{
	if(x <= leftBound)
		{
		flipImage();
		isLeft = false;
		}
		
	if(x+width >= rightBound)
		{
		flipImage();
		isLeft = true;
		}
	}

void GameObject::flipImage()
	{
	QGraphicsPixmapItem::setPixmap(QPixmap::fromImage(this->pixmap().toImage().mirrored(true, false)));
	}

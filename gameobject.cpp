#include "gameobject.h"

GameObject::GameObject(QPixmap *i, double x_, double y_, double w, double h) : 
	QGraphicsPixmapItem(*i, this)
	{
	image = i;
	x = x_;
	y = y_;
	width = w;
	height = h;
	}
	
void GameObject::setPixmap(QPixmap *i)
	{
	image = i;
	}
	
void GameObject::setX( int x_ )
	{
	x = x_;
	}
	
void GameObject::setY( int y_ )
	{
	y = y_;
	}
	
int GameObject::getX()
	{
	return x;
	}
int GameObject::getY()
	{
	return y;
	}

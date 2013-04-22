#include "staticobject.h"

StaticObject::StaticObject(QPixmap *i, char o, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, o, x, y, lb, rb, direction)
	{
	if(direction)
		{
		x = rb - width;
		setPos(x, y);
		}
	}

void StaticObject::move()
	{/*
	++y;
	
	if(isLeft)
		{
		x = rightBound - width;
		}
	
	setPos(x, y);*/
	}

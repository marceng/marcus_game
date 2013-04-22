#include "staticobject.h"

StaticObject::StaticObject(QPixmap *i, char o, double y, double lb, double rb, bool direction) :
	GameObject(i, o, 0, y, lb, rb, direction)
	{
	if(direction)
		{
		x = rb - width;
		setPos(x, y);
		}
	else
		{
		x = lb;
		}
	}

void StaticObject::move()
	{
	++y;
	setPos(x, y);
	}

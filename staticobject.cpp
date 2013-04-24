#include "staticobject.h"

StaticObject::StaticObject(QPixmap *i, char o, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, o, 0, y, lb, rb, direction, speed)
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
	y += currentSpeed;
	setPos(x, y);
	}

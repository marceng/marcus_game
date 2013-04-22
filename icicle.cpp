#include "icicle.h"

Icicle::Icicle(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, x, y, lb, rb, direction)
	{
	if(direction)
		{
		x = rb - width;
		setPos(x, y);
		}
	}

void Icicle::move()
	{
	++y;
	
	if(isLeft)
		{
		x = rightBound - width;
		}
	
	setPos(x, y);
	}

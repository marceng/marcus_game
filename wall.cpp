#include "wall.h"

Wall::Wall(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, x, y, lb, rb, direction)
	{
	if(direction)
		{
		x = rb - width;
		setPos(x, y);
		}
	}

void Wall::move()
	{/*
	y = y + .5;
	
	if(isLeft)
		{
		x = rightBound - width;
		}
	
	setPos(x, y);*/
	}

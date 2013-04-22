#include "monkey.h"

Monkey::Monkey(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, 'm', x, y, lb, rb, direction)
	{
	
	}

void Monkey::move()
	{
	handleDirection();

	if(isLeft)
		{
		--x;
		}
	
	else
		{
		++x;
		}
	
	this->setPos(x, y);
	}

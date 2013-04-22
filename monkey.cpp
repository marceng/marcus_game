#include "monkey.h"

Monkey::Monkey(QPixmap *i, double y, double lb, double rb, bool direction) :
	GameObject(i, 'm', 0, y, lb, rb, direction)
	{
	if(direction)
		{
		x = rb - i->width();
		}
	else
		{
		x = lb;
		}
	}

void Monkey::move()
	{
	int number = (int) rand() % 700;
	if(number < 10)
		{
		y -= 20;
		}

	++y;
	this->setPos(x, y);
	}

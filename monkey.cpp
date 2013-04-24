#include "monkey.h"

Monkey::Monkey(QPixmap *i, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, 'm', 0, y, lb, rb, direction, speed)
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
		y -= 15*currentSpeed;
		}

	y += currentSpeed;
	this->setPos(x, y);
	}

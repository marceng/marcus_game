#include "bird.h"

Bird::Bird(QPixmap *i, double x, double y, bool direction) :
	GameObject(i, 'b', x, y, 0, 0, direction)
	{
	}

void Bird::move()
	{
	if(isLeft)
		{
		x -= 2;
		}

	else
		{
		x += 2;
		}
		
	y = 300 - pow(x,2)/1000;
	this->setPos(x, y);
	}

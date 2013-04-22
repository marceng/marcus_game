#include "bird.h"

Bird::Bird(QPixmap *i, double x, double y, bool direction) :
	GameObject(i, x, y, 0, 0, direction)
	{
	}

void Bird::move()
	{
	if(isLeft)
		{
		--x;
		}
	
	else
		{
		++x;
		}
	
	y = sqrt(x);
	this->setPos(x, y);
	}

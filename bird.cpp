#include "bird.h"

Bird::Bird(QPixmap *i, double x, double y, bool direction, double speed) :
	GameObject(i, 'b', x, y, 0, 0, direction, speed)
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
		
	y = 400 - pow(x,2)/800;
	
	this->setPos(x, y);
	}

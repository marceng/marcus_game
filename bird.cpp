#include "bird.h"

Bird::Bird(QPixmap *i, double x, double y, bool direction) :
	GameObject(i, 'b', x, y, 0, 0, direction)
	{
	}

void Bird::move()
	{
	handleDirection();
	
	y = sqrt(x);
	this->setPos(x, y);
	}

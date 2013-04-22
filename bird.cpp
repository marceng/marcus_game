#include "bird.h"

Bird::Bird(QPixmap *i, double x, double y, bool direction) :
	GameObject(i, x, y, 0, 0, direction)
	{
	}

void Bird::move()
	{/*
	if(x == leftBound)
		{
		isLeft = false;
		flipImage();
		}
		
	if(x+width == rightBound)
		{
		isLeft = true;
		flipImage();
		}*/

	if(isLeft)
		{
		--x;
		this->setPos(x, y);
		}
	
	else
		{
		++x;
		this->setPos(x, y);
		}
	}

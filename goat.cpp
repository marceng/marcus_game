#include "goat.h"

Goat::Goat(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, x, y, lb, rb, direction)
	{
	
	}

void Goat::move()
	{
	if(x == leftBound)
		{
		isLeft = false;
		flipImage();
		}
		
	if(x+width == rightBound)
		{
		isLeft = true;
		flipImage();
		}

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

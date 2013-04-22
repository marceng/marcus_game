#include "star.h"

Star::Star(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, x, y, lb, rb, direction)
	{
	
	}

void Star::move()
	{
	if(x == leftBound)
		{
		isLeft = false;
		}
		
	if(x+width == rightBound)
		{
		isLeft = true;
		}

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

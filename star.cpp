#include "star.h"

Star::Star(QPixmap *i, int x, int y, int lb, int rb, bool direction) :
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
		this->setPos(x, y);
		}
	
	else
		{
		++x;
		this->setPos(x, y);
		}
	}

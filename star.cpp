#include "star.h"

#include <iostream>
using namespace std;

Star::Star(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, 's', x, y, lb, rb, direction)
	{
	
	}

void Star::move()
	{
	if(x == leftBound)
		{
		flipImage();
		isLeft = false;
		}
		
	if(x+width == rightBound)
		{
		flipImage();
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
		
	y = y-.1;
	this->setPos(x, y);
	}

#include "star.h"

#include <iostream>
using namespace std;

Star::Star(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, 's', x, y, lb, rb, direction)
	{
	
	}

void Star::move()
	{
	handleDirection();
	
	if(isLeft)
		{
		x = x-2;
		}
	
	else
		{
		x = x+2;
		}
		
	y = y+.5;
	this->setPos(x, y);
	}

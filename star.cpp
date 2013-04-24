#include "star.h"

#include <iostream>
using namespace std;

Star::Star(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, 's', x, y, lb, rb, direction, speed)
	{
	
	}

void Star::move()
	{
	handleDirection();
	
	if(isLeft)
		{
		x -= 2*currentSpeed;
		}
	
	else
		{
		x += 2*currentSpeed;
		}
		
	y += .5*currentSpeed;
	this->setPos(x, y);
	}

#include "goat.h"

Goat::Goat(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, 'g', x, y, lb, rb, direction, speed)
	{
	
	}

void Goat::move()
	{
	handleDirection();

	if(isLeft)
		{
		x -= .5*currentSpeed;
		}
	
	else
		{
		x += .5*currentSpeed;
		}
	
	int number = (int) rand() % 4000;
	
	if(number < 10)
		{
		flipImage();
		
		if(isLeft)
			{
			isLeft = false;
			}
		
		else
			{
			isLeft = true;
			}
		}
	
	y += currentSpeed;
	this->setPos(x, y);
	}

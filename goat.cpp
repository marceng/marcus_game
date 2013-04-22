#include "goat.h"

Goat::Goat(QPixmap *i, double x, double y, double lb, double rb, bool direction) :
	GameObject(i, 'g', x, y, lb, rb, direction)
	{
	
	}

void Goat::move()
	{
	handleDirection();

	if(isLeft)
		{
		x = x - .5;
		}
	
	else
		{
		x = x + .5;
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
	
	//++y;
	this->setPos(x, y);
	}

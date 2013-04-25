#include "monkey.h"

/** Constructor to initialize bird object
 	* @param QPixmap a pointer to the image
 	* @param double the x coordinate
 	* @param double the y coordinate
 	* @param bool the direction of the object
 	* @param double the rate of movement
 	* @return nothing
 	*/
Monkey::Monkey(QPixmap *i, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, 'm', 0, y, lb, rb, direction, speed)
	{
	if(direction)
		{
		x = rb - i->width();
		}
	else
		{
		x = lb;
		}
	}

/** The Monkeys's move function.
 	* @param nothing
 	* @return nothing
 	*/
void Monkey::move()
	{
	int number = (int) rand() % 700;
	
	if(number < 10)
		{
		y -= 15*currentSpeed;
		}

	y += currentSpeed;
	this->setPos(x, y);
	}

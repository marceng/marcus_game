#include "goat.h"

/** Constructor to initialize bird object
 	* @param QPixmap a pointer to the image
 	* @param double the x coordinate
 	* @param double the y coordinate
 	* @param bool the direction of the object
 	* @param double the rate of movement
 	* @return nothing
 	*/
Goat::Goat(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, 'g', x, y, lb, rb, direction, speed)
	{
	
	}

/** The Goats's move function.
 	* @param nothing
 	* @return nothing
 	*/
void Goat::move()
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
	
	y += 4*currentSpeed;
	this->setPos(x, y);
	}

#include "star.h"

/** Constructor to initialize bird object
 	* @param QPixmap a pointer to the image
 	* @param double the x coordinate
 	* @param double the y coordinate
 	* @param bool the direction of the object
 	* @param double the rate of movement
 	* @return nothing
 	*/
Star::Star(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, 's', x, y, lb, rb, direction, speed)
	{
	
	}

/** The Stars's move function.
 	* @param nothing
 	* @return nothing
 	*/
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

#include "bird.h"

/** Constructor to initialize bird object
 	* @param QPixmap a pointer to the image
 	* @param double the x coordinate
 	* @param double the y coordinate
 	* @param bool the direction of the object
 	* @param double the rate of movement
 	* @return nothing
 	*/
Bird::Bird(QPixmap *i, double x, double y, bool direction, double speed) :
	GameObject(i, 'b', x, y, 0, 0, direction, speed)
	{
	}

/** The bird's move function.
 	* @param nothing
 	* @return nothing
 	*/
void Bird::move()
	{
	if(isLeft)
		{
		x -= 2;
		}

	else
		{
		x += 2;
		}
		
	y = 400 - pow(x,2)/800;
	
	this->setPos(x, y);
	}

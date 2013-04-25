#include "staticobject.h"

/** Constructor to initialize bird object
 	* @param QPixmap a pointer to the image
 	* @param char a char to identify the object
 	* @param double the x coordinate
 	* @param double the y coordinate
 	* @param bool the direction of the object
 	* @param double the rate of movement
 	* @return nothing
 	*/
StaticObject::StaticObject(QPixmap *i, char o, double y, double lb, double rb, bool direction, double speed) :
	GameObject(i, o, 0, y, lb, rb, direction, speed)
	{
	if(direction)
		{
		x = rb - width;
		setPos(x, y);
		}
	else
		{
		x = lb;
		}
	}
/** The Static Objects's move function.
 	* @param nothing
 	* @return nothing
 	*/
void StaticObject::move()
	{
	y += currentSpeed;
	setPos(x, y);
	}

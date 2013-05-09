/*
Copyright (C) 2013  MARCUS ENG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

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
	y += 4*currentSpeed;
	setPos(x, y);
	}

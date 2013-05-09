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
		x -= 5;
		}

	else
		{
		x += 5;
		}
		
	y = 600 - pow(x,2)/500;
	
	this->setPos(x, y);
	}

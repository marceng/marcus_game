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

#include "climber.h"

/** Constructor to initialize bird object
 	* @param QPixmap* a pointer to the first image
 	* @param QPixmap* a pointer to the second image
 	* @param double the left boundary coordinate
 	* @param double the right boundary coordinate
 	* @param double the rate of movement
 	* @return nothing
 	*/
Climber::Climber(QPixmap *i, QPixmap *j, double lb, double rb, double speed) :
	GameObject(i, 'c', rb - i->width(), 380, lb, rb, false, speed)
	{
	a = i;
	b = j;
	toggle = false;
	counter = 0;
	invincible = false;
	}

/** The Climbers's move function.
 	* @param nothing
 	* @return nothing
 	*/
void Climber::move()
	{
	if(x <= leftBound || x + width >= rightBound)
		{
		isLeft = !isLeft;
		flipImage();
		}
		
	if(!isLeft)
		{
		x += 40;
		}
		
	else
		{
		x -= 40;
		}
	
	this->setPos(x, y);
	}

/** A function to handle the switching of the character's image
 	* @param nothing
 	* @return nothing
 	*/
void Climber::update()
	{
	if(counter >= 15)
		{
		if(toggle)
			{
			QGraphicsPixmapItem::setPixmap(*a);
			}
		
		else
			{
			QGraphicsPixmapItem::setPixmap(*b);
			}

		if(!isLeft)
			{
			flipImage();
			}
			
		toggle = !toggle;
		counter = 0;
		}
		
	else
		{
		++counter;
		}
	
	}

/** A function to check the state of the player
 	* @param nothing
 	* @return bool whether or not the player is invincible
 	*/
bool Climber::isInvincible()
	{
	return invincible;
	}

/** A function to set the invincibility state of the plaer
 	* @param bool whether or not the player is to become invincible or not
 	* @return nothing
 	*/
void Climber::setInvincible(bool inv)
	{
	invincible = inv;
	}

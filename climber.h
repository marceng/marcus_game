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

#ifndef CLIMBER_H
#define CLIMBER_H

#include "gameobject.h"

class Climber : public GameObject
	{	
	public:
		/** Constructor for the climber object*/
		Climber(QPixmap *i, QPixmap *j, double lb, double rb, double speed);
		/** Climber's move function*/
		void move();
		/** Function to update the image*/
		void update();
		/** Function that handles the invincability of the climber*/
		void setInvincible(bool inv);
		/** Function that tells program if invincible or not*/
		bool isInvincible();

	private:
		QPixmap *a;
		QPixmap *b;
		bool toggle;
		int counter;
		bool invincible;
	};

#endif

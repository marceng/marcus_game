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

#ifndef MONKEY_H
#define MONKEY_H

#include "gameobject.h"

class Monkey : public GameObject
	{	
	public:
		/** Constructor for the Monkey object*/
		Monkey(QPixmap *i, double y, double lb, double rb, bool direction, double speed);
		/** Method to move the Monkey*/
		void move();

	protected:
	};

#endif

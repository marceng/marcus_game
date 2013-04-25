#ifndef GOAT_H
#define GOAT_H

#include "gameobject.h"

class Goat : public GameObject
	{	
	public:
		/** Constructor for the Goat object*/
		Goat(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed);
		/** Method to move the goat*/
		void move();
	};

#endif

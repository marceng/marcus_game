#ifndef BIRD_H
#define BIRD_H

#include "gameobject.h"

class Bird : public GameObject
	{	
	public:
		/** Constructor for the bird object*/
		Bird(QPixmap *i, double x, double y, bool direction, double speed);
		/** Method to move the bird*/
		void move();
	};

#endif

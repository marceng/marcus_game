#ifndef BIRD_H
#define BIRD_H

#include "gameobject.h"

class Bird : public GameObject
	{	
	public:
		Bird(QPixmap *i, double x, double y, bool direction);
		void move();

	protected:
	};

#endif

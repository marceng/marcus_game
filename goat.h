#ifndef GOAT_H
#define GOAT_H

#include "gameobject.h"

class Goat : public GameObject
	{	
	public:
		Goat(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed);
		void move();

	protected:
	};

#endif

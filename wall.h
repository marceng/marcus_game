#ifndef WALL_H
#define WALL_H

#include "gameobject.h"

class Wall : public GameObject
	{	
	public:
		Wall(QPixmap *i, double x, double y, double lb, double rb, bool direction);
		void move();

	protected:
	};

#endif

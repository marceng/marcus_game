#ifndef STAR_H
#define STAR_H

#include "gameobject.h"

class Star : public GameObject
	{	
	public:
		Star(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed);
		void move();

	protected:
	};

#endif

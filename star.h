#ifndef STAR_H
#define STAR_H

#include "gameobject.h"

class Star : public GameObject
	{	
	public:
		Star(QPixmap *i, int x, int y, int lb, int rb, bool direction);
		void move();

	protected:
	};

#endif

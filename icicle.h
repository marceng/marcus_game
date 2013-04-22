#ifndef ICICLE_H
#define ICICLE_H

#include "gameobject.h"

class Icicle : public GameObject
	{	
	public:
		Icicle(QPixmap *i, double x, double y, double lb, double rb, bool direction);
		void move();

	protected:
	};

#endif

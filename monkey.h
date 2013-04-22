#ifndef MONKEY_H
#define MONKEY_H

#include "gameobject.h"

class Monkey : public GameObject
	{	
	public:
		Monkey(QPixmap *i, double x, double y, double lb, double rb, bool direction);
		void move();

	protected:
	};

#endif

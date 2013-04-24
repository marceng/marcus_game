#ifndef MONKEY_H
#define MONKEY_H

#include "gameobject.h"

class Monkey : public GameObject
	{	
	public:
		Monkey(QPixmap *i, double y, double lb, double rb, bool direction, double speed);
		void move();

	protected:
	};

#endif

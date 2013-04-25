#ifndef MONKEY_H
#define MONKEY_H

#include "gameobject.h"

class Monkey : public GameObject
	{	
	public:
		/** Constructor for the Monkey object*/
		Monkey(QPixmap *i, double y, double lb, double rb, bool direction, double speed);
		/** Method to move the Monkey*/
		void move();

	protected:
	};

#endif

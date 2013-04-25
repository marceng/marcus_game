#ifndef STAR_H
#define STAR_H

#include "gameobject.h"

class Star : public GameObject
	{	
	public:
		/** Constructor for the Star object*/
		Star(QPixmap *i, double x, double y, double lb, double rb, bool direction, double speed);
		/** Method to move the Star*/
		void move();

	protected:
	};

#endif

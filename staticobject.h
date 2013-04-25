#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "gameobject.h"

class StaticObject : public GameObject
	{	
	public:
		/** Constructor for the Static Object*/
		StaticObject(QPixmap *i, char o, double y, double lb, double rb, bool direction, double speed);
		/** Method to move the static object*/
		void move();
	};

#endif

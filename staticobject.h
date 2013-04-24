#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "gameobject.h"

class StaticObject : public GameObject
	{	
	public:
		StaticObject(QPixmap *i, char o, double y, double lb, double rb, bool direction, double speed);
		void move();

	protected:
	};

#endif

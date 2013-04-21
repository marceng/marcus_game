#ifndef STAR_H
#define STAR_H

#include "gameobject.h"

class Star : public GameObject
	{
	public:
		Star(QPixmap *i, double x, double y, double w, double h);
		void move();

	protected:
	};

#endif

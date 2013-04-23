#ifndef CLIMBER_H
#define CLIMBER_H

#include "gameobject.h"

class Climber : public GameObject
	{	
	public:
		Climber(QPixmap *i, QPixmap *j, double lb, double rb);
		void move();
		void update();

	protected:
		QPixmap *a;
		QPixmap *b;
		bool toggle;
		int counter;
	};

#endif

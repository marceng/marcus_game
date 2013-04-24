#ifndef CLIMBER_H
#define CLIMBER_H

#include "gameobject.h"

class Climber : public GameObject
	{	
	public:
		Climber(QPixmap *i, QPixmap *j, double lb, double rb, double speed);
		void move();
		void update();
		void setInvincible(bool inv);
		bool isInvincible();

	private:
		QPixmap *a;
		QPixmap *b;
		bool toggle;
		int counter;
		bool invincible;
	};

#endif

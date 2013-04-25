#ifndef CLIMBER_H
#define CLIMBER_H

#include "gameobject.h"

class Climber : public GameObject
	{	
	public:
		/** Constructor for the climber object*/
		Climber(QPixmap *i, QPixmap *j, double lb, double rb, double speed);
		/** Climber's move function*/
		void move();
		/** Function to update the image*/
		void update();
		/** Function that handles the invincability of the climber*/
		void setInvincible(bool inv);
		/** Function that tells program if invincible or not*/
		bool isInvincible();

	private:
		QPixmap *a;
		QPixmap *b;
		bool toggle;
		int counter;
		bool invincible;
	};

#endif

#include "climber.h"

Climber::Climber(QPixmap *i, QPixmap *j, double lb, double rb) :
	GameObject(i, 'c', rb - i->width(), 380, lb, rb, false)
	{
	a = i;
	b = j;
	toggle = false;
	counter = 0;
	}

void Climber::move()
	{

	}

void Climber::update()
	{
	if(counter >= 20)
		{
		if(toggle)
			{
			QGraphicsPixmapItem::setPixmap(*a);
			}
		
		else
			{
			QGraphicsPixmapItem::setPixmap(*b);
			}

		if(!isLeft)
			{
			flipImage();
			}
			
		toggle = !toggle;
		counter = 0;
		}
		
	else
		{
		++counter;
		}
	}

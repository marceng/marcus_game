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
	if(x <= leftBound || x + width >= rightBound)
		{
		isLeft = !isLeft;
		flipImage();
		}
		
	if(!isLeft)
		{
		x += 10;
		}
		
	else
		{
		x -= 10;
		}
	
	this->setPos(x, y);
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

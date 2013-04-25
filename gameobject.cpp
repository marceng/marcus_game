#include "gameobject.h"

/** Constructor to initialize bird object
 	* @param QPixmap a pointer to the image
 	* @param char a character to identify the object
 	* @param double the x coordinate
 	* @param double the y coordinate
 	* @param bool the direction of the object
 	* @param double the rate of movement
 	* @return nothing
 	*/
GameObject::GameObject(QPixmap *i, char o, double x_, double y_, double lb, double rb, bool direction, double speed) : 
	QGraphicsPixmapItem(*i)
	{
	QGraphicsPixmapItem::setPos(x_, y_);
	
	obj = o;
	x = x_;
	y = y_;
	width = i->width();
	height = i->height();
	
	leftBound = lb;
	rightBound = rb;
	isLeft = direction;
	currentSpeed = speed;
	
	
	if(!direction)
		{
		flipImage();
		}
	}

/** Function to set the x value
 	* @param double the desired x location
 	* @return nothing
 	*/
void GameObject::setX( double x_ )
	{
	x = x_;
	QGraphicsPixmapItem::setX(x_);
	}

/** Function to set the y value
 	* @param double the desired y location
 	* @return nothing
 	*/
void GameObject::setY( double y_ )
	{
	y = y_;
	QGraphicsPixmapItem::setY(y_);
	}

/** A function to get the identity of the object
 	* @param nothing
 	* @return char the identity of the object
 	*/
char GameObject::getObject()
	{
	return obj;
	}

/** A function to get the object's x coordinate
 	* @param nothing
 	* @return double the x coodinate
 	*/
double GameObject::getX()
	{
	return x;
	}

/** A function to get the object's y coordinate
 	* @param nothing
 	* @return double the y coordinate
 	*/
double GameObject::getY()
	{
	return y;
	}

/** A function to get the object's width
 	* @param nothing
 	* @return double the width of the object
 	*/
double GameObject::getWidth()
	{
	return width;
	}

/** A function to get the object's height
 	* @param nothing
 	* @return double the height of the object
 	*/
double GameObject::getHeight()
	{
	return height;
	}

/** A function to handle the movement speed of the object
 	* @param nothing
 	* @return nothing
 	*/
void GameObject::speedUp()
	{
	currentSpeed += .5;
	}

/** A function to handle the direction of the object and update its image accordingly
 	* @param nothing
 	* @return nothing
 	*/
void GameObject::handleDirection()
	{
	if(x <= leftBound)
		{
		flipImage();
		isLeft = false;
		}
		
	if(x+width >= rightBound)
		{
		flipImage();
		isLeft = true;
		}
	}

/** A function to flip the object's image
 	* @param nothing
 	* @return nothing
 	*/
void GameObject::flipImage()
	{
	QGraphicsPixmapItem::setPixmap(QPixmap::fromImage(this->pixmap().toImage().mirrored(true, false)));
	}

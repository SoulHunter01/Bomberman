#ifndef Shape_H_
#define Shape_H_

#include "Board.h"
#include "util.h"

class Shape
{
protected:
	float x_co;
	float y_co;
	float radius;
	float height;
	int color;
	int speed;
	int direction;
	int resourceType;
public:
	virtual void Draw() = 0;
	virtual void setInitialLocation(float, float) = 0;
	virtual void setSize(float, float) = 0;
	virtual void setColor(int) = 0;
	virtual void move() = 0;
	virtual void setSpeedAndInitialDirection(int, int) = 0;
	virtual void BoundaryCollision() = 0;
	bool checkAndProcessCollision(Shape * ptr, bool &ptrDeleted) {
		bool colliding = true;

		/*
		if (ptr lies at the right of this shape) {
			colliding = false;
		} else if (ptr lies at the left of this shape) {
			colliding = false;
		} else if (ptr lies above this shape) {
			colliding = false;
		} else if (ptr lies below this shape) {
			colliding = false;
		}
		*/

		if (colliding) {
			if (resourceType == ptr->resourceType && color == ptr->color) {
				if (resourceType == 1) {
					radius++;
				} else if (resourceType == 2) {
					height++;
				}

				ptrDeleted = true;
				delete ptr;
			} else {
				// Deflection
				if (direction == 0) {
					if (ptr->direction == 0) {
						direction = 2;
					} else if (ptr->direction == 1) {
						direction = 2;
						ptr->direction = 0;
					} else if (direction == 2) {
						direction = 2;
						ptr->direction = 0;
					} else if (direction == 3) {
						direction = 3;
						ptr->direction = 1;
					}
				} else if (direction == 1) {
					if (ptr->direction == 0) {
						direction = 3;
						ptr->direction = 1;
					} else if (ptr->direction == 1) {
						direction = 3;
					} else if (ptr->direction == 2) {
						direction = 2;
						ptr->direction = 0;
					} else if (ptr->direction == 3) {
						direction = 3;
						ptr->direction = 1;
					}
				} else if (direction == 2) {
					if (ptr->direction == 0) {
						direction = 0;
						ptr->direction = 2;
					} else if (ptr->direction == 1) {
						direction = 1;
						ptr->direction = 3;
					} else if (ptr->direction == 2) {
						ptr->direction = 0;
					} else if (ptr->direction == 3) {
						direction = 3;
						ptr->direction = 1;
					}
				} else {
					if (ptr->direction == 0) {
						direction = 0;
						ptr->direction = 2;
					} else if (ptr->direction == 1) {
						direction = 1;
						ptr->direction = 3;
					} else if (ptr->direction == 2) {
						direction = 2;
						ptr->direction = 0;
					} else if (ptr->direction == 3) {
						ptr->direction = 1;
					}
				}
			}
		}
	}




};

#endif
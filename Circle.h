#ifndef Circle_H_
#define Circle_H_

#include "Shape.h"

class Circle : public Shape
{
private:
	bool isHittingRightWall();
	bool isHittingLeftWall();
	bool isHittingTopWall();
	bool isHittingBottomWall();
public:
	Circle();
	Circle(float, float, float, int, int, int);
	void Draw();
	void setInitialLocation(float, float);
	void setColor(int);
	void setSize(float, float);
	void move();
	void setSpeedAndInitialDirection(int, int);
	void BoundaryCollision();
	void detectCollision(Shape *);
	~Circle();
};

#endif
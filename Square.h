#ifndef Square_H_
#define Square_H_

#include "Shape.h"

class Square : public Shape
{
private:
	bool isHittingRightWall();
	bool isHittingLeftWall();
	bool isHittingTopWall();
	bool isHittingBottomWall();
public:
	Square();
	Square(float, float, float, float, int, int, int);
	void Draw();
	void setInitialLocation(float, float);
	void setColor(int);
	void setSize(float, float);
	void setSpeedAndInitialDirection(int, int);
	void move();
	void BoundaryCollision();
	~Square();
};

#endif
#include "Circle.h"

using namespace std;

Circle::Circle() {
	this->x_co = 0.0;
	this->y_co = 0.0;
	this->radius = 0.0;
	this->color = 0;
	this->speed = 0;
	this->direction = 0;
	this-resourceType = 1;
}

Circle::Circle(float x_co, float y_co, float radius, int color, int speed, int direction) {
	this->x_co = x_co;
	this->y_co = y_co;
	this->radius = radius;
	this->color = color;
	this->speed = speed;
	this->direction = direction;
	this-resourceType = 1;
}

void Circle::Draw() {
	//cout << endl << x_co << " " << y_co << endl;
	DrawCircle(this->x_co, this->y_co, radius, colors[color]);
}

void Circle::setInitialLocation(float x, float y) {
	this->x_co = x;
	this->y_co = y;
}

void Circle::setColor(int color) {
	this->color = color;
}
void Circle::setSize(float radius, float hieght) {
	this->radius = radius;
}

void Circle::setSpeedAndInitialDirection(int speed, int direction) {
	this->speed = speed;
	this->direction = direction;
}

bool Circle::isHittingRightWall() {
	return (y_co < 810 && x_co >= 990);
}

bool Circle::isHittingTopWall() {
	return (y_co >= 810 && x_co < 990 && x_co > 0);
}

bool Circle::isHittingBottomWall() {
	return (y_co <= 0 && x_co > 0 && x_co < 990);
}

bool Circle::isHittingLeftWall() {
	return (x_co <= 0 && y_co < 810);
}

// TODO: Why 2 separate implementations of BoundaryCollision function. Why shoudnt we define this in shape class?
void Circle::BoundaryCollision() {
	if (direction == 0) {
		if (isHittingTopWall()) {
			direction = 1;
		} else if (isHittingRightWall()) {
			direction = 3;
		}
	} else if (direction == 1) {
		if (isHittingRightWall()) {
			direction = 2;
		} else if (isHittingBottomWall()) {
			direction = 0;
		}
	} else if (direction == 2) {
		if(isHittingBottomWall()) {
			direction = 3;
		} else if (isHittingLeftWall()) {
			direction = 1;
		}
	} else if (direction == 3) {
		if (isHittingLeftWall()) {
			direction = 0;
		} else if (isHittingTopWall()) {
			direction = 2;
		}
	}
}
// TODO: Why 2 separate implementations of move function. Why shoudnt we define this in shape class?
void Circle::move() {
	if (direction == 0) {
		x_co += speed;
		y_co += speed;
	}
	if (direction == 1) {
		x_co += speed;
		y_co -= speed;
	}
	if (direction == 2)
	{
		x_co -= speed;
		y_co -= speed;
	}
	if (direction == 3) {
		x_co -= speed;
		y_co += speed;
	}

	glutPostRedisplay();
}

Circle::~Circle() {
	x_co = 0.0;
	y_co = 0.0;
	color = 0;
}
#include "Square.h"

using namespace std;

Square::Square() {
	this->x_co = 0.0;
	this->y_co = 0.0;
	this->radius = 0.0;
	this->height = 0.0;
	this->color = 0;
	this->speed = 0;
	this->direction = 0;
	this-resourceType = 2;
}

Square::Square(float x_co, float y_co, float radius, float height, int color, int speed, int direction) {
	this->x_co = x_co;
	this->y_co = y_co;
	this->radius = radius;
	this->height = height;
	this->color = color;
	this->speed = speed;
	this->direction = direction;
	this-resourceType = 2;
}

void Square::Draw() {
	DrawRoundRect(this->x_co, this->y_co, radius, height, colors[color]);
	cout << x_co << " " << y_co << endl;
}

void Square::setInitialLocation(float x, float y) {
	this->x_co = x;
	this->y_co = y;
}

void Square::setColor(int color) {
	this->color = color;
}
void Square::setSize(float radius, float height) {
	this->radius = radius;
	this->height = height;
}

void Square::setSpeedAndInitialDirection(int speed, int direction) {
	this->speed = speed;
	this->direction = direction;
}

bool Square::isHittingRightWall() {
	return (y_co < 810 && x_co >= 990);
}

bool Square::isHittingTopWall() {
	return (y_co >= 810 && x_co < 990 && x_co > 0);
}

bool Square::isHittingBottomWall() {
	return (y_co <= 0 && x_co > 0 && x_co < 990);
}

bool Square::isHittingLeftWall() {
	return (x_co <= 0 && y_co < 810);
}

void Square::move() {
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

void Square::BoundaryCollision() {
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

Square::~Square() {
	x_co = 0.0;
	y_co = 0.0;
	color = 0;
}
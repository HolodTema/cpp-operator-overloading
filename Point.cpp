#include <cmath>
#include <iostream>
#include "Point.h"


bool Point::isEqual(const Point &anotherPoint) const noexcept {
	return x_ == anotherPoint.getX() && y_ == anotherPoint.getY();
}

double Point::distanceTo(const Point &anotherPoint) const noexcept {
	double deltaX = x_ - anotherPoint.getX();
	double deltaY = y_ - anotherPoint.getY();
	return std::pow(deltaX*deltaX + deltaY*deltaY, 0.5);
}

Point& Point::move(int delta) noexcept {
	x_ += delta;
	y_ += delta;
	return *this;
}

bool operator == (const Point &point1, const Point &point2) {
	return point1.isEqual(point2);
}

std::istream& operator >> (std::istream &is, Point &point) {
	int x = 0;
	int y = 0;
	is >> x >> y;

	point.setX(x);
	point.setY(y);
	return is;
}

std::ostream& operator << (std::ostream &os, const Point &point) {
	os << "(" << point.getX() << "," << point.getY() << ")";
	return os;
}

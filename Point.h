
#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
	double x_;
	double y_;

public:
	Point():
		x_(0),
		y_(0)
	{
	
	}

	Point(double x, double y):
		x_(x),
		y_(y)
	{
	
	}
	
	double getX() const noexcept {
		return x_;
	}

	double getY() const noexcept {
		return y_;
	}

	void setX(double x) noexcept {
		x_ = x;
	}

	void setY(double y) noexcept {
		y_ = y;
	}

	
	bool isEqual(const Point &anotherPoint) const noexcept;

	double distanceTo(const Point &anotherPoint) const noexcept;

	Point& move(int delta) noexcept;
};

bool operator == (const Point &point1, const Point &pointg);

std::istream& operator >> (std::istream &is, Point &point);

std::ostream& operator << (std::ostream &os, const Point &point);
#endif


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Point.h"

class Triangle {
private:
	Point pointA_;
	Point pointB_;
	Point pointC_;

	double ab_;
	double ac_;
	double bc_;

public:
	Triangle() { }

	Triangle(Point pointA, Point pointB, Point pointC):
		pointA_(pointA),
		pointB_(pointB),
		pointC_(pointC)
	{
		ab_ = pointA_.distanceTo(pointB_);
		bc_ = pointB_.distanceTo(pointC_);
		ac_ = pointA_.distanceTo(pointC_);
	}


	const Point& getPointA() const noexcept {
		return pointA_;
	}

	const Point& getPointB() const noexcept {
		return pointB_;
	}

	const Point& getPointC() const noexcept {
		return pointC_;
	}

	void setPointA(Point pointA) noexcept {
		pointA_ = pointA;
		ab_ = pointA_.distanceTo(pointB_);
		ac_ = pointA_.distanceTo(pointC_);
	}

	void setPointB(Point pointB) noexcept {
		pointB_ = pointB;
		bc_ = pointB_.distanceTo(pointC_);
		ab_ = pointA_.distanceTo(pointB_);

	}

	void setPointC(Point pointC) noexcept {
		pointC_ = pointC;
		ac_ = pointA_.distanceTo(pointC_);
		bc_ = pointB_.distanceTo(pointC_);

	}

	bool isCorrect() const noexcept;

	double square() const noexcept;
	
	double perimeter() const noexcept;

	Triangle& move(int delta);
};

bool operator == (const Triangle &triangle1, const Triangle &triangle2);

bool operator < (const Triangle &triangle1, const Triangle &triangle2);

Triangle& operator += (Triangle &triangle, int delta);

std::istream& operator >> (std::istream &is, Triangle &triangle);

std::ostream& operator << (std::ostream &os, const Triangle &triangle);

#endif

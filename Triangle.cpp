#include <cmath>
#include <iostream>
#include "Triangle.h"

bool Triangle::isCorrect() const noexcept {
	if (ab_ > ac_) {
		if (ab_ > bc_) {
			return ab_ < bc_ + ac_;
		}
		else {
			return bc_ < ab_ + ac_;
		}
	}
	else {
		if (ac_ > bc_) {
			return ac_ < ab_ + bc_;
		} 
		else {
			return bc_ < ab_ + ac_;
		}
	}
}


double Triangle::perimeter() const noexcept {
	return ab_ + bc_ + ac_;
}

double Triangle::square() const noexcept {
	double p = perimeter() / 2;
	
	double expr = p*(p - ab_)*(p - bc_)*(p - ac_);
	return std::pow(expr, 0.5);
}

Triangle& Triangle::move(int delta) {
	pointA_.move(delta);
	pointB_.move(delta);
	pointC_.move(delta);
	return *this;
}

bool operator == (const Triangle &triangle1, const Triangle &triangle2) {
	return triangle1.getPointA() == triangle2.getPointA()
		&& triangle1.getPointB() == triangle2.getPointB()
		&& triangle1.getPointC() == triangle2.getPointC();
}

bool operator < (const Triangle &triangle1, const Triangle &triangle2) {
	double square1 = triangle1.square();
	double square2 = triangle2.square();
	return square1 < square2;
}

Triangle& operator += (Triangle &triangle, int delta) {
	triangle.move(delta);
	return triangle;
}
	



std::istream& operator >> (std::istream &is, Triangle &triangle) {
	Point pointA = Point();
	Point pointB = Point();
	Point pointC = Point();
	
	is >> pointA >> pointB >> pointC;
	
	triangle.setPointA(pointA);
	triangle.setPointB(pointB);
	triangle.setPointC(pointC);

	return is;
}

std::ostream& operator << (std::ostream &os, const Triangle &triangle) {
	std::cout << triangle.getPointA() << triangle.getPointB() << triangle.getPointC();
	return os;
}

	

	

#include <iostream>

#include "Point.h"
#include "Triangle.h"

int main() {
	Triangle triangle1 = Triangle();
	std::cin >> triangle1;

	if (!triangle1.isCorrect()) {
		std::cout << "ERROR: it is impossible to construct a triangle from given points\n";
		return 1;
	}

	Triangle triangle2 = Triangle();
	std::cin >> triangle2;

	if (!triangle2.isCorrect()) {
		std::cout << "ERROR: it is impossible to construct a triangle from given points\n";
		return 1;
	}

	if (triangle1 == triangle2) {
		std::cout << "The triangles are equal\n";
	}
	else {
		std::cout << "The triangles are not equal\n";
	}

	if (triangle1 < triangle2) {
		std::cout << "The area of the first triangle is less than the second\n";
	}
	else {
		std::cout << "The area of the first triangle is NOT less than the second\n";
	}

	int k = 0;
	std::cin >> k;
	triangle1 += k;
	
	std::cout << "Triangle1 moved, new vertices=" << triangle1 << "\n";

	return 0;
}

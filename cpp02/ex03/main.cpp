#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point shape[3] = {Point(1, 1), Point(4, 5), Point(7, 1)};
	Point a(4, 2); // TRUE, inside the traingle
	Point b(1, 4); // FALSE, outside the triangle
	Point c(3, 1); // FALSE, on edge of triangle

	std::cout << std::boolalpha;
	std::cout << bsp(shape[0], shape[1], shape[2], a) << std::endl;
	std::cout << bsp(shape[0], shape[1], shape[2], b) << std::endl;
	std::cout << bsp(shape[0], shape[1], shape[2], c) << std::endl;
	return 0;
}	
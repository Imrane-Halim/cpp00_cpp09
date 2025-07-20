#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}
Point::Point(const float x, const float y): _x(x), _y(y) {}
Point::Point(const Point &other): _x(other._x), _y(other._y) {}
Point::~Point() { /*not needed but added anyway*/ }

Point	&Point::operator=(const Point &other) {
	(void)other;
	return *this;
}

const Fixed	Point::x(void) const { return _x; }
const Fixed	Point::y(void) const  { return _y; }

void	Point::print(void) {
	std::cout << "x: " << _x << ", y: " << _y << std::endl;
}
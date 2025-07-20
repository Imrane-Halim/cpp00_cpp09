#include "Point.hpp"
#include <cstdio>

// area = (1/2) (x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2))
Fixed	trangleArea(Point const &p1, Point const &p2, Point const &p3) {
	Fixed area = Fixed(0.5f) * ( p1.x() * (p2.y() - p3.y()) +
								 p2.x() * (p3.y() - p1.y()) +
								 p3.x() * (p1.y() - p2.y()));
	return (area < 0) ? area * -1: area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed t1 = trangleArea(a, b, point);
	Fixed t2 = trangleArea(b, c, point);
	Fixed t3 = trangleArea(c, a, point);

	Fixed total = t1 + t2 + t3;
	Fixed og_tri = trangleArea(a, b, c);

	if ((t1 * t2 * t3) == 0)
		return false;
	if (total != og_tri)
		return false;
	return true;
}

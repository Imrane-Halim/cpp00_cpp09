#pragma once
#ifndef __POINT__
# define __POINT__

#include "Fixed.hpp"

class Point {
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(const Point &other);
	Point(const float x, const float y);
	~Point();

	Point	&operator=(const Point &other);
	
	const Fixed	x(void) const;
	const Fixed	y(void) const;

	void	print(void);
};

#endif
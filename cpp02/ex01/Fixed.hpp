#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {
	int					_value;
	static const int 	_bitsCount;
public:
	Fixed();

	Fixed(int const num);
	Fixed(float const num);

	Fixed(const Fixed &other);
	~Fixed();

	Fixed	&operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
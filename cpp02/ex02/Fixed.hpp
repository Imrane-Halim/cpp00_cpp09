#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

# include <iostream>

class Fixed {
	int					_value;
	static const int 	_bitsCount;

	static	Fixed		_formNewClass(int RawBits);
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

	Fixed	operator+(const Fixed &other) const;
	Fixed	operator-(const Fixed &other) const;
	Fixed	operator*(const Fixed &other) const;
	Fixed	operator/(const Fixed &other) const;

	bool	operator>(const Fixed &other) const;
	bool	operator<(const Fixed &other) const;
	bool	operator>=(const Fixed &other) const;
	bool	operator<=(const Fixed &other) const;
	bool	operator==(const Fixed &other) const;
	bool	operator!=(const Fixed &other) const;

	// ++a; --a;
	Fixed	&operator++();
	Fixed	&operator--();

	// a++; a--;
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);

	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
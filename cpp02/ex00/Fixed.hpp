#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {
	int					_value;
	static const int 	_bitsCount;
public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	Fixed	&operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
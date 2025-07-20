#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define SCALING_FACTOR (1 << Fixed::_bitsCount)

const int Fixed::_bitsCount = 8;

Fixed::Fixed(): _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(float const point): _value(roundf(point * SCALING_FACTOR)) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int const point): _value(point * SCALING_FACTOR) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float Fixed::toFloat(void) const	{ return (float)_value / SCALING_FACTOR; }
int Fixed::toInt(void) const		{ return _value / SCALING_FACTOR; }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
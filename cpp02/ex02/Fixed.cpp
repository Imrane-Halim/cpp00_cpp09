#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define SCALING_FACTOR  (1 << Fixed::_bitsCount)
#define EPSILLON        1

const int Fixed::_bitsCount = 8;

Fixed::Fixed(): _value(0) { }
Fixed::Fixed(float const point): _value(roundf(point * SCALING_FACTOR)) { }
Fixed::Fixed(int const point): _value(point * SCALING_FACTOR) { }
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed::~Fixed() { }

Fixed &Fixed::operator=(const Fixed &other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return (*this);
}

int Fixed::getRawBits(void) const { return _value; }
void Fixed::setRawBits(int const raw) { _value = raw; }


float Fixed::toFloat(void) const	{ return (float)_value / SCALING_FACTOR; }
int Fixed::toInt(void) const		{ return _value / SCALING_FACTOR; }

Fixed   Fixed::_formNewClass(int rawBits) { Fixed New; New.setRawBits(rawBits); return New; }

Fixed	Fixed::operator+(const Fixed &other) const { return _formNewClass(this->_value + other._value); }
Fixed	Fixed::operator-(const Fixed &other) const { return _formNewClass(this->_value - other._value); }
Fixed	Fixed::operator*(const Fixed &other) const {
    return _formNewClass((int64_t)this->_value * (int64_t)other._value >> _bitsCount);
}
Fixed	Fixed::operator/(const Fixed &other) const {
    if (other._value == 0) {
        std::cout << "Divistion by 0!" << std::endl;
        return _formNewClass(0);
    }
    return _formNewClass(((int64_t)this->_value << _bitsCount ) / (int64_t)other._value);
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}

bool   Fixed::operator>(const Fixed &other) const { return (this->getRawBits() > other.getRawBits()); }
bool   Fixed::operator<(const Fixed &other) const { return (this->getRawBits() < other.getRawBits()); }
bool   Fixed::operator>=(const Fixed &other) const { return (this->getRawBits() >= other.getRawBits()); }
bool   Fixed::operator<=(const Fixed &other) const { return (this->getRawBits() <= other.getRawBits()); }
bool   Fixed::operator==(const Fixed &other) const { return (this->getRawBits() == other.getRawBits()); }
bool   Fixed::operator!=(const Fixed &other) const { return (this->getRawBits() != other.getRawBits()); }

// pre
Fixed   &Fixed::operator++() { return _value += EPSILLON, *this; }
Fixed   &Fixed::operator--() { return _value -= EPSILLON, *this; }

// post
Fixed   Fixed::operator++(int) {
    Fixed tmp = *this;
    _value += EPSILLON;
    return tmp;
}
Fixed   Fixed::operator--(int) {
    Fixed tmp = *this;
    _value -= EPSILLON;
    return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }
Fixed	&Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) { return a < b ? a : b; }
Fixed const &Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }
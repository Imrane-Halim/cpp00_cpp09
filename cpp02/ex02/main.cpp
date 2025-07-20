#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout <<  "a value        : " << a.toFloat() << std::endl;
	std::cout <<  "b value        : " << b.toFloat() << std::endl;

	
	std::cout <<  "c = a + b value: " << (a + b) << std::endl;
	std::cout <<  "c = a - b value: " << (a - b) << std::endl;
	std::cout <<  "c = a * b value: " << (a * b) << std::endl;
	std::cout <<  "c = a / b value: " << (a / b) << std::endl;

	
	std::cout << std::boolalpha;
	std::cout << a << " > " << b << " = " << (a > b) << std::endl;
	std::cout << a << " < " << b << " = " << (a < b) << std::endl;
	std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
	std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
	std::cout << a << " == " << b << " = " << (a == b) << std::endl;
	std::cout << a << " != " << b << " = " << (a != b) << std::endl;
	std::cout << std::noboolalpha;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	return 0;
}	
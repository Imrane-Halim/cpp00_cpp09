#include "ScalarConverter.hpp"

eTypes	ScalarConverter::_type = INVALID;
bool	ScalarConverter::_isPseudoLiteral = false;
long	ScalarConverter::_i = 0;
char	ScalarConverter::_c = 0;
float	ScalarConverter::_f = 0;
double	ScalarConverter::_d = 0;

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter::~ScalarConverter() {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

#include <cstdio>

eTypes	ScalarConverter::getType(const char *str)
{
	char *end;

	_i = strtol(str, &end, 10);
	if (_i >= INT_MIN && _i <= INT_MAX && *end == '\0')
		return INT;
	
	_d = strtod(str, &end);
	if (_d >= __FLT_MIN__ && _d <= __FLT_MAX__ 
		&& (*end == 'f' || *end == 'F'))
		return _f = _d, FLOAT;
	
	if (*end == '\0')
		return DOUBLE;
	return INVALID;
}

void	ScalarConverter::convert(const std::string &str)
{
	eTypes type = getType(str.c_str());
	std::cout << "type: " << type << std::endl;
}

void	ScalarConverter::printScalar(void)
{
	//std::cout << ScalarConverter::_d << std::endl;
}
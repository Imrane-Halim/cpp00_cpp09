#include "ScalarConverter.hpp"
#include <cstdio>

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

bool	ScalarConverter::_checkRange(double n, double min, double max)
{
	return (n >= min && n <= max);
}

eTypes	ScalarConverter::getType(std::string&  str)
{
	char *end;

	if (str.empty())
		return INVALID;

	_i = strtol(str.c_str(), &end, 10);
	if (_checkRange(_i, INT_MIN, INT_MAX) && *end == '\0')
		return INT;
	
	_f = strtof(str.c_str(), &end);
	if (_checkRange(_f, __FLT_MIN__, __FLT_MAX__)
		&& (*end == 'f' || *end == 'F'))
		return FLOAT;

	_d = strtod(str.c_str(), &end);
	if (_checkRange(_d, __DBL_MIN__, __DBL_MAX__)
		&& *end == '\0')
		return DOUBLE;

	if (std::isinf(_f) && (*end == 'F' || *end == 'f'))
		return FLOAT;

	if (std::isinf(_d))
		return DOUBLE;

	if (std::isnan(_d) || std::isnan(_f))
		return DNAN;

	return INVALID;
}

void	ScalarConverter::convert(std::string str)
{
	eTypes type = getType(str);

	_type = type;

	switch (type)
	{
	case INT:
		_d = static_cast<double>(_i);
		_f = static_cast<float>(_i);
		_c = static_cast<char>(_i);
		break;
	case FLOAT:
		_d = static_cast<double>(_f);
		_i = static_cast<int>(_f);
		_c = static_cast<char>(_f);
	case DOUBLE:
		_i = static_cast<float>(_d);
		_f = static_cast<float>(_d);
		_c = static_cast<char>(_d);
	default:
		break;
	}
}

void	ScalarConverter::printScalar(void)
{
	if (_type == INVALID)
	{
		std::cout << "Invalid Input!" << std::endl;
		return;
	}

	if (_checkRange(_i, INT_MIN, INT_MAX) && _type != DNAN)
		std::cout << "int   : " << _i << std::endl;
	else
		std::cout << "int   : impossible" << std::endl;

	if (std::isprint(_c))
		std::cout << "char  : " << _c << std::endl;
	else
		std::cout << "char  : impossible" << std::endl;

	std::cout << "float : " << _f << 'f' << std::endl;
	std::cout << "double: " << _d << std::endl;
}

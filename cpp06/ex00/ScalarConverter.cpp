#include "ScalarConverter.hpp"
#include <cstdio>

eTypes	ScalarConverter::_type = INVALID;
long	ScalarConverter::_i = 0;
char	ScalarConverter::_c = 0;
float	ScalarConverter::_f = 0;
double	ScalarConverter::_d = 0;

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::_checkRange(double n, double min, double max)
{
	return (n >= min && n <= max);
}

bool	ScalarConverter::_isEnd(const char *end)
{
	return *end == '\0';
}

eTypes	ScalarConverter::getType(std::string&  str)
{
	char *end;

	if (str.empty())
		return INVALID;

	_i = strtol(str.c_str(), &end, 10);
	if (_checkRange(_i, INT_MIN, INT_MAX) && _isEnd(end))
		return INT;
	
	_f = strtof(str.c_str(), &end);
	if (_checkRange(_f, __FLT_MIN__, __FLT_MAX__)
		&& (*end == 'f' || *end == 'F'))
		if (_isEnd(end + 1))
			return FLOAT;

	_d = strtod(str.c_str(), &end);
	if (_checkRange(_d, __DBL_MIN__, __DBL_MAX__)
		&& _isEnd(end))
		return DOUBLE;

	if (std::isinf(_d) || std::isinf(_f))
	{
		if ((*end == 'f' || *end == 'F') && _isEnd(end + 1))
			return FLOAT;
		else if (_isEnd(end))
			return DOUBLE;
	}

	if (std::isnan(_d) || std::isnan(_f))
	{
		if ((*end == 'f' || *end == 'F') && _isEnd(end + 1))
			return DNAN;
		else if (_isEnd(end))
			return DNAN;
	}

	return (*end != '\0' ? INVALID : DOUBLE);
}

void	ScalarConverter::convert(std::string str)
{
	_type = getType(str);

	switch (_type)
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

	if (!_checkRange(_i, 0, 127) || std::isnan(_i))
		std::cout << "char  : impossible" << std::endl;
	else if (std::isprint(_c))
		std::cout << "char  : " << _c << std::endl;
	else
		std::cout << "char  : non displayable" << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float : " << _f;
	if (_f == _i)
		std::cout << ".0";
	std::cout << 'f' << std::endl;

	std::cout << "double: " << _d;
	if (_d == _i)
		std::cout << ".0";
	std::cout << std::endl;
}

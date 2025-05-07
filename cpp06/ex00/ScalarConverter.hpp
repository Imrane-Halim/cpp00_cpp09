#pragma once
#ifndef	__SCALARCONVETER__
#define __SCALARCONVETER__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cerrno>
#include <climits>

enum eTypes
{
	INVALID,
	DNAN,
	FLOAT,
	DOUBLE,
	INT,
};

class ScalarConverter
{
	static eTypes	_type;
	static bool		_isPseudoLiteral;

	static long		_i;
	static char		_c;
	static float	_f;
	static double	_d;

	static	bool	_checkRange(double n, double min, double max);
	public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	~ScalarConverter();
	
	ScalarConverter	&operator=(const ScalarConverter&);
	
	static	eTypes	getType(const char*);
	static	void	convert(const std::string &);
	static	void	printScalar(void);
};

#endif
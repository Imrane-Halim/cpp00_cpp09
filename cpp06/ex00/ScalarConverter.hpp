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

	static long		_i;
	static char		_c;
	static float	_f;
	static double	_d;

	static	bool	_checkRange(double n, double min, double max);
	static	bool	_isEnd(const char *);
	
	ScalarConverter();
	~ScalarConverter();
public:
	
	static	eTypes	getType(std::string&);
	static	void	convert(std::string);
	static	void	printScalar(void);
};

#endif
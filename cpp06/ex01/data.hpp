#pragma once
#ifndef	__DATA__
#define	__DATA__

#include <iostream>

enum eGender { MALE, FEMALE };
enum eMaritalStatus { SINGLE, MARRIED, WIDOW, DIVORCED };

struct Data
{
	std::string		first_name;
	std::string		last_name;
	unsigned short	age;
	eGender			gender;
	eMaritalStatus	status;
};

#endif
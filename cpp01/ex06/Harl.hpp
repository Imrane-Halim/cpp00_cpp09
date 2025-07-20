#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

enum levels { DEBUG, INFO, WARNING, ERROR, UNKNOWN };

class Harl {

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	levels	_getLevel(std::string level);
public:
	void	complain(std::string level);
};

#endif
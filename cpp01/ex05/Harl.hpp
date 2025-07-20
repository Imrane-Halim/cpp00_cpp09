#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

class Harl {

	struct stFunctions;
	
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	void	complain(std::string level);
};

#endif
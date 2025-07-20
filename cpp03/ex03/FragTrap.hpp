#pragma once
#ifndef __FRAGTRAP__
#define __FRAGTRAP__

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &copy);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &copy);

	void	highFivesGuys(void);
};

#endif
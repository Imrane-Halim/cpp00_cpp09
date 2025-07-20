#pragma once
#ifndef __SCAVTRAP__
#define __SCAVTRAP__

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &copy);
	~ScavTrap();

	ScavTrap	&operator=(const ScavTrap &copy);
	void	attack(const std::string &target);
	void	guardGate();
};

#endif
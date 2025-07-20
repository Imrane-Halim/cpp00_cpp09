#pragma once
#ifndef __DIAMONDTRAP__
#define __DIAMONDTRAP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap();
 
	DiamondTrap	&operator=(const DiamondTrap &copy);

	void	whoAmI();
};

#endif
#pragma once
#ifndef __CLAPTRAP__
#define __CLAPTRAP__

#include <iostream>

class ClapTrap {
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	int				_attack_damage;
public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &other);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
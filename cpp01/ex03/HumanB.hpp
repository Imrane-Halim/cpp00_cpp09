#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class HumanB {
	std::string	_name;
	Weapon		*_weapn;
public:
	HumanB(std::string Name);
	~HumanB();

	void	attack(void);
	void	setWeapon(Weapon &Weapon);
};

#endif
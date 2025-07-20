#pragma once
#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.hpp"

class HumanA {
	std::string	_name;
	Weapon		&_weapn;
public:
	HumanA(std::string Name, Weapon &weapon);
	~HumanA();

	void	attack(void);
};

#endif
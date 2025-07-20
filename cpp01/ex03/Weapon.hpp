#pragma once
#ifndef __WEAPHON_H__
#define __WEAPHON_H__

#include <iostream>

class Weapon {
	std::string _type;
public:
	Weapon();
	Weapon(std::string Type);
	~Weapon();

	void				setType(std::string NewType);
	const std::string	&getType(void);
};

#endif
#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>

class Zombie {
	std::string _name;
public:
	Zombie(std::string Name);
	~Zombie();

	void	announce(void);
};

#endif
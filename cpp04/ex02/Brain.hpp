#pragma once
#ifndef __BRAIN__
#define __BRAIN__

#include <iostream>

class Brain {
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain	&operator=(const Brain &copy);
};

#endif
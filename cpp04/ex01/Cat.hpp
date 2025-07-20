#pragma once
#ifndef __CAT__
#define __CAT__

#include "Animal.hpp"

class Cat: public Animal {
	Brain	*_brain;
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat	&operator=(const Cat &other);
	void	makeSound() const ;
};

#endif
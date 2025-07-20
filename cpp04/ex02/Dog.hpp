#pragma once
#ifndef __DOG__
#define __DOG__

#include "AAnimal.hpp"

class Dog: public AAnimal {
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog	&operator=(const Dog &other);
	void	makeSound() const ;
};

#endif
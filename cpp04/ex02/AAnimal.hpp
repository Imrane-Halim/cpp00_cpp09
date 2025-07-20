#pragma once
#ifndef __AANIMAL__
#define __AANIMAL__

#include <iostream>
#include "Brain.hpp"

// this is an INTERFACE/ ABSTRACT CLASS/ CONTRACT CLASS
// bcz it has the a pure virtual function (aka '= 0')
class AAnimal {
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();

	AAnimal	&operator=(const AAnimal &copy);

	virtual void	makeSound() const = 0;

	std::string		getType(void) const;
};

#endif
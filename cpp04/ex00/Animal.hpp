#pragma once
#ifndef __ANIMAL__
#define __ANIMAL__

#include <iostream>

// this is an INTERFACE/ ABSTRACT CLASS/ CONTRACT CLASS
// bcz it has the a pure virtual function (aka '= 0')
class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &copy);
	virtual ~Animal();

	Animal	&operator=(const Animal &copy);

	virtual void	makeSound() const;

	std::string		getType(void) const;
};

#endif
#pragma once
#ifndef __WRONGANIMAL__
#define __WRONGANIMAL__

#include <iostream>

class WrongAnimal {
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();

	WrongAnimal	&operator=(const WrongAnimal &copy);

	void	makeSound() const;
};

#endif
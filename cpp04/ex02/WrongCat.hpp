#pragma once
#ifndef __WRONGCAT__
#define __WRONGCAT__

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	~WrongCat();

	WrongCat	&operator=(const WrongCat &other);
	void	makeSound() const ;
};

#endif
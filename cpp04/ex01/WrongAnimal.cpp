#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("NO_WRONG_ANIML")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal Paramterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this != &copy)
		_type = copy._type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal is Making a Sound" << std::endl;
}

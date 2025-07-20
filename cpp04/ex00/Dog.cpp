#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{ std::cout << "Dog Default constructor called!" << std::endl; }

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog Copy constructor called!" << std::endl;
	*this = copy;
}

Dog::~Dog()
{ std::cout << "Dog Destructor called!" << std::endl; }

Dog	&Dog::operator=(const Dog &copy) {
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

void	Dog::makeSound() const
{ std::cout << "Dog is Barking!!" << std::endl; }
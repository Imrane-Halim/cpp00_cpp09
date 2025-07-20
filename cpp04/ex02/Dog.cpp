#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
	std::cout << "Dog Default constructor called!" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog Copy constructor called!" << std::endl;
	_brain = new Brain(*copy._brain);
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called!" << std::endl;
	delete _brain;
}

Dog	&Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		AAnimal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Dog is Barking!!" << std::endl;
}
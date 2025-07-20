#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat")
{
	std::cout << "Cat Default constructor called!" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat Copy constructor called!" << std::endl;
	_brain = new Brain(*copy._brain);
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called!" << std::endl;
	delete _brain;
}

Cat	&Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		AAnimal::operator=(copy);
		delete _brain;
		_brain = new Brain(*copy._brain);
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Cat is Meowing!!" << std::endl;
}
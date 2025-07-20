#include "Animal.hpp"

// TODO: add messages
Animal::Animal(): _type("NO_ANIMAL")
{ std::cout << "Animal Default constructor called!" << std::endl; }

Animal::Animal(std::string type): _type(type)
{ std::cout << "Animal Parameterized constructor called!" << std::endl; }

Animal::Animal(const Animal &copy) {
	std::cout << "Animal Copy construcor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{ std::cout << "Animal Destructor called!" << std::endl; }

Animal	&Animal::operator=(const Animal &copy) {
	if (this != &copy) _type = copy._type;
	return *this;
}

std::string	Animal::getType(void) const { return _type; }

void	Animal::makeSound() const {
	std::cout << "Animal is making Sound" << std::endl;
}
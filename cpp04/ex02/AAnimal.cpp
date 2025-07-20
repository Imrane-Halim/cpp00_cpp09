#include "AAnimal.hpp"

// TODO: add messages
AAnimal::AAnimal(): _type("NO_AANIMAL")
{ std::cout << "AAnimal Default constructor called!" << std::endl; }

AAnimal::AAnimal(std::string type): _type(type)
{ std::cout << "AAnimal Parameterized constructor called!" << std::endl; }

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << "AAnimal Copy construcor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal()
{ std::cout << "AAnimal Destructor called!" << std::endl; }

AAnimal	&AAnimal::operator=(const AAnimal &copy) {
	if (this != &copy) _type = copy._type;
	return *this;
}

std::string	AAnimal::getType(void) const { return _type; }

void	AAnimal::makeSound() const {
	std::cout << "AAnimal is making Sound" << std::endl;
}
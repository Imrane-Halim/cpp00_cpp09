#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}
Ice::Ice(const Ice &copy) { *this = copy; }
Ice::~Ice() {}

Ice	&Ice::operator=(const Ice &copy) {
	if (this != &copy) AMateria::operator=(copy);
	return *this;
}

Ice	*Ice::clone() const { return new Ice(); }

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots and ice bolt at ";
	std::cout << target.getName();
	std::cout << " *" << std::endl;
}
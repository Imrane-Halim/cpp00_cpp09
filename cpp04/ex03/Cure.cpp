#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}
Cure::Cure(const Cure &copy) { *this = copy; }
Cure::~Cure() {}

Cure	&Cure::operator=(const Cure &copy) {
	if (this != &copy) AMateria::operator=(copy);
	return *this;
}

Cure	*Cure::clone() const { return new Cure(); }

void	Cure::use(ICharacter &target) {
	std::cout << "* heals ";
	std::cout << target.getName();
	std::cout << "'s wounds *" << std::endl;
}
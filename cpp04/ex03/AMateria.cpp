#include "AMateria.hpp"

AMateria::AMateria(): _Type("NO_TYPE") {}
AMateria::AMateria(std::string const &type): _Type(type) {}
AMateria::~AMateria() {}

AMateria	&AMateria::operator=(const AMateria &copy) {
	if (this != &copy) _Type = copy._Type;
	return *this;
}

std::string	const &AMateria::getType() const { return _Type; }

void	AMateria::use(ICharacter &target) {
	(void)target;
}
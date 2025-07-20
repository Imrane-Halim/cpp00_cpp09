#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::Weapon(std::string Type): _type(Type) {}
Weapon::~Weapon() {}

void				Weapon::setType(std::string NewType) { _type = NewType; }
const std::string	&Weapon::getType(void) { return (_type); }
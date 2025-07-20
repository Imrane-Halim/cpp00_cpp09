#include "HumanB.hpp"

HumanB::HumanB(std::string Name): _name(Name), _weapn(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack(void) {
	std::cout << _name << " attacks with their " << _weapn->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon) { _weapn = &Weapon; }
#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &WeaponType): _name(Name), _weapn(WeaponType) {}
HumanA::~HumanA() {}

void	HumanA::attack(void) {
	std::cout << _name << " attacks with their " << _weapn.getType() << std::endl;
}
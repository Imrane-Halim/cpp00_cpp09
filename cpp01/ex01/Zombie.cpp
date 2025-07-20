#include "Zombie.hpp"

Zombie::Zombie(): _name("") {}
Zombie::Zombie(std::string Name): _name(Name) {}
Zombie::~Zombie() {
	std::cout << _name << " is dead" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string Name) { _name = Name; }
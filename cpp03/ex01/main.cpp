#include "ScavTrap.hpp"

int main(void) {
	ScavTrap obj("Jamal");
	ScavTrap nnn = obj;

	nnn.attack("Mohammed");
	nnn.beRepaired(100);
	nnn.takeDamage(3);
	nnn.guardGate();
	return 0;
}
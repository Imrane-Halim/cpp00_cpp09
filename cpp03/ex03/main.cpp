#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap nnn("DIAMOND");

	nnn.highFivesGuys();
	nnn.attack("Jamal");
	nnn.takeDamage(30);
	nnn.beRepaired(10);
	nnn.whoAmI();

	return 0;
}
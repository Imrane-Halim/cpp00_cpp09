#include "ClapTrap.hpp"

int main(void) {
	ClapTrap obj("Jamal");
	ClapTrap nnn = obj;

	nnn.attack("Mohammed");
	nnn.beRepaired(100);
	nnn.takeDamage(3);

	//obj.attack("Mohammed");
	//obj.takeDamage(10);
	return 0;
}
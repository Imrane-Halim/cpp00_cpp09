#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void) {

	// delete newZombie("Mohammed Ali Clay");
	Zombie *obj = newZombie("Jamal");
	obj->announce();
	randomChump("Tesla");
	delete obj;
	return (0);
}
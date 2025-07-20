#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void) {
	int N = 3;
	Zombie *hord = zombieHorde(N, "Mongol");
	
	for (int i = 0; i < N; i++)
		hord[i].announce();
	
	delete[] hord;
	return (0);
}
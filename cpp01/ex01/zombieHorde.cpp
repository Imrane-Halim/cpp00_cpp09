#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *hord = new Zombie[N];
	for (int i = 0; i < N; i++)
		hord[i].setName(name);
	return (hord);
}
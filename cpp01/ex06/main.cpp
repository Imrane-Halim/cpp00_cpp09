#include <iostream>
#include "Harl.hpp"

int main(int ac, char **av) {
	
	if (ac != 2)
	{
		std::cout << "usage: ./HarlFilter <LEVEL>" << std::endl;
		return (1);
	}

	Harl 		moron;

	moron.complain(std::string(av[1]));
		
	return (0);
}
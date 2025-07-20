#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called!" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap &copy) { 
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap	&FragTrap::operator=(const FragTrap &copy) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap() {std::cout << "FragTrap Destructor called !" << std::endl;}

void	FragTrap::highFivesGuys(void) {
	std::cout << "High fives, guys!" << std::endl;
}
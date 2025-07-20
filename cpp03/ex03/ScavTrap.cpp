#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called!" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) {
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &copy) { 
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << "SavTrap assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap() {std::cout << "ScavTrap Destructor called !" << std::endl;}

void	ScavTrap::attack(const std::string &target) {
	if (!_energy_points) {
		std::cout << "No energy points" << std::endl;
		return;
	}
	if (!_hit_points)
	{
		std::cout << "No Hit Points" << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ScavTrap " << _name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << _attack_damage;
	std::cout << " points of damage! ";
	std::cout << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
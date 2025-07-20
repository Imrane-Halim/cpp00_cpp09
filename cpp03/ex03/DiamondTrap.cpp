#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	_name = "NO_NAME";
	ClapTrap::_name += "_clap_name";
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
}
DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	std::cout << "diamondTrap paramterized contructor" << std::endl;
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) { 
	std::cout << "Diamond copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy) {
	if (this != &copy) {
		ClapTrap::operator=(copy);
		_name = copy._name;
	}
	return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name;
	std::cout << ", ClapTrap name: " << ClapTrap::_name;
	std::cout << std::endl;
}

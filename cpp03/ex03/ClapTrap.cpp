#include "ClapTrap.hpp"

ClapTrap::ClapTrap():	_name("NO_NAME"), _hit_points(10),
_energy_points(10), _attack_damage(0) {
	std::cout << "clapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hit_points(10),
_energy_points(10), _attack_damage(0) {
	std::cout << "clapTrap Parameterized constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) { 
	std::cout << "clapTrap Copy constructor called!" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() { std::cout << "clapTrap Destructor called!" << std::endl; }

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this == &other)
		return *this;
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
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
	std::cout << "ClapTrap " << _name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << _attack_damage;
	std::cout << " points of damage! ";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!_hit_points) {
		std::cout << "No Hit Points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name;
	std::cout << " took " << amount;
	std::cout << " of damage!" << std::endl;
	_hit_points = (_hit_points < amount) ? 0 : _hit_points - amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!_energy_points) {
		std::cout << "No energy points" << std::endl;
		return;
	}
	if (!_hit_points)
	{
		std::cout << "No Hit Points" << std::endl;
		return;
	}
	std::cout << "ClapTrap Repaired!" << std::endl;
	_hit_points += amount;
}

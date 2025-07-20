#include "Character.hpp"

Character::Character(std::string const &name):
_name(name), _numOfDropped(0) {
	// initializing the array to fix conditional jump
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	_dropped = NULL;
}

Character::Character(const Character &copy) { *this = copy; }
Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _materias[i];
	for (unsigned int i = 0; i < _numOfDropped; i++)
		delete _dropped[i];
	delete[] _dropped;
}

Character	&Character::operator=(const Character &copy) {
	if (this != &copy) {
		_name = copy._name;
		for (int i = 0; i < 4; i++) {
			delete _materias[i];
			if (copy._materias[i])
				_materias[i] = copy._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

std::string	const	&Character::getName() const { return _name; }

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL) {
			_materias[i] = m->clone();
			return;
		}
	}
}

void	Character::_addToDropped(AMateria *m) {
	AMateria **tmp = new AMateria*[_numOfDropped + 1];

	for (unsigned int i = 0; i < _numOfDropped; i++)
		tmp[i] = _dropped[i];
	tmp[_numOfDropped] = m;
	delete[] _dropped;
	_dropped = tmp;
	_numOfDropped++;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx >= 4)
		return;
	if (_materias[idx] == NULL)
		return;
	_addToDropped(_materias[idx]);
	_materias[idx] = NULL;
} 

void	Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4) {
		std::cout << "Index out of range!(0-3)" << std::endl;
		return;
	}
	if (_materias[idx] == NULL) {
		std::cout << "Empty slot!" << std::endl;
		return;
	}
	_materias[idx]->use(target);
}
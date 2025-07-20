#include "MateriaSource.hpp"

MateriaSource::MateriaSource():
 _index(-1), _numOfL(0) {
	for (int i = 0; i < 4; i++)
		_learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) { *this = copy; }

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _numOfL; i++)
		delete _learned[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy) {
	if (this != &copy) {
		_numOfL = copy._numOfL;
		_index = copy._index;
		for (int i = 0; i < 4; i++) {
			delete _learned[i];
			if (copy._learned[i])
				_learned[i] = copy._learned[i]->clone();
			else
				_learned[i] = NULL;
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m) {
	_index = (_index + 1) % 4;
	if (_numOfL < 4)
		_numOfL++;
	delete _learned[_index];
	_learned[_index] = m->clone();
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < _numOfL; i++) {
		if (_learned[i]->getType() == type)
			return _learned[i]->clone();
	}
	return NULL;
}
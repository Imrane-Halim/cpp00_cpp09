#pragma once
#ifndef __MATERIASOURCE__
#define __MATERIASOURCE__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	AMateria		*_learned[4];
	unsigned short _index;
	unsigned short _numOfL;
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &copy);
	void			learnMateria(AMateria *m);
	AMateria		*createMateria(std::string const &type);
};

#endif
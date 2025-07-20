#pragma once
#ifndef __IMATERIASOURCE__
#define __IMATERIASOURCE__

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
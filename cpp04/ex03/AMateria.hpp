#pragma once
#ifndef __AMATERIA__
#define __AMATERIA__

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string	_Type;
public:
	AMateria();
	AMateria(std::string const &type);
	virtual ~AMateria();

	AMateria			&operator=(const AMateria &copy);

	std::string const	&getType() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
};

#endif
#pragma once
#ifndef	__CHARACHTER__
#define __CHARACHTER__

#include "ICharacter.hpp"

class Character: public ICharacter {
	std::string		_name;
	AMateria		*_materias[4];

	unsigned int	_numOfDropped;
	AMateria		**_dropped;
	void			_addToDropped(AMateria *m);
public:
	Character(std::string const &name);
	Character(const Character &copy);
	~Character();

	Character	&operator=(const Character &copy);

	std::string const	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
};

#endif
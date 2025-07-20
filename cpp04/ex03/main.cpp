#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();

	src->learnMateria(ice);
	src->learnMateria(cure);

	ICharacter* me = new Character("me");
	AMateria *tmp1, *tmp2;

	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	me->equip(tmp2);
	me->equip(tmp2);
	me->equip(tmp2);
	me->equip(tmp2);
	me->equip(tmp2);
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(4);
	me->unequip(3);

	delete bob;
	delete me;
	
	delete src;

	delete ice;
	delete cure;

	delete tmp1;
	delete tmp2;

	return 0;
}
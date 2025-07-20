#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// vtable and vptr can be seen using:
// -fdump-lang-class flag with g++ compiler
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\n\nAnimal Types: \n" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << "\n\nAnimal Sounds: \n" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	//-----------------------------------------------

	std::cout << "\n\nWrong Stuff:" << std::endl;
	const WrongAnimal* obj = new WrongCat();
	obj->makeSound(); // should output cat insted of animal

	//-----------------------------------------------
	std::cout << "\n\nDeleting objs: \n" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete obj;
	return 0;
}
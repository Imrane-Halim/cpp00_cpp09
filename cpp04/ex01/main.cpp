#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// vtable and vptr can be seen using:
// -fdump-lang-class flag with g++ compiler
int main()
{
	unsigned short SIZE = 2;
	Animal	*arr[SIZE];

	// fill half with dogs
	for (int i = 0; i < SIZE / 2; i++)
		arr[i] = new Dog();
	
		// fill half with cats
	for (int i = SIZE / 2; i < SIZE; i++)
		arr[i] = new Cat();
	
	std::cout << std::endl;
	for (int i = 0; i < SIZE; i++)
		arr[i]->makeSound();
	std::cout << std::endl;

	// freeing all allocated memory
	for (int i = 0; i < SIZE; i++)
		delete arr[i];
	return 0;
}
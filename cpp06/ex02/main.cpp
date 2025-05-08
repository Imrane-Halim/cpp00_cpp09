#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

Base	*generate(void)
{
	int num = rand() % 3;

	if (num == 0)
		return /*printf("A class is created"),*/ new A();
	if (num == 1)
		return /*printf("B class is created"),*/ new B();
	return /*printf("C class is created"),*/ new C();
}

void	identify(Base* p)
{
	std::cout << "this class type is: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Invalid";
	std::cout << std::endl;
}

void	identify(Base& p)
{
	std::cout << "this class type is: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch(...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch(...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch(...) {}
	std::cout << std::endl;
}

int main(void)
{
	srand(time(NULL));

	Base	*base = generate();
	
	identify(base);
	identify(*base);

	delete base;
	return 0;
}
#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat moron("jamal", 150);
	std::cout << moron;
	moron.decrementGrade();
	moron.decrementGrade();
	moron.decrementGrade();
	std::cout << moron;

	std::cout << "execution continues even thought an exception was thrown" << std::endl;
}
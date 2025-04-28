#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat moron("jamal", 151);
	std::cout << moron;
	std::cout << "execution continues even thought an exception was thrown" << std::endl;
}
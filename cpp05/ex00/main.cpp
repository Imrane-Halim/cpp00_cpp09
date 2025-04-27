#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat moron("jamal", 2);
	std::cout << moron.getGrade() << std::endl;
	std::cout << "execution continues even thought an exception was thrown" << std::endl;
}
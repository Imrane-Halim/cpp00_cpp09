#include "ScalarConverter.hpp"

// -------- tests
int main(int ac, char **av) {
	if (ac != 2)
	{
		std::cerr << "usage: ./convert <INPUT>" << std::endl;
		return EXIT_FAILURE;
	}

	ScalarConverter::convert(av[1]);
	ScalarConverter::printScalar();

	return 0;
}
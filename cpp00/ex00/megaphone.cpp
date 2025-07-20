#include <iostream>

int	main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; av[i]; i++)
	{
		std::string arg = av[i];
		for (int j = 0; arg[j]; j++)
			arg[j] = toupper(arg[j]);
		std::cout << arg;
	}

	std::cout << std::endl;

	return (0);
}
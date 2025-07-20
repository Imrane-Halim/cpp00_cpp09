#include <fstream>
#include <cstring>
#include <cerrno>
#include <iostream>

std::string my_replace(std::string Line, std::string Old, std::string New) {
	size_t		pos;

	while ((pos = Line.find(Old)) != std::string::npos)
	{
		Line.erase(pos, Old.length());
		Line.insert(pos, New);
	}
	return (Line);
}

int	main(int ac, char **av) {
	if (ac != 4)
	{
		std::cout << "usage: ./repace <FILE_NAME> <STRING1> <STRING2>" << std::endl;
		return (1);
	}

	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cout << av[1] << ": " << strerror(errno) << std::endl;
		return (1);
	}

	std::string filename = std::string(av[1]) + ".replace";
	std::ofstream otfile(filename.c_str());
	if (!otfile.is_open())
	{
		std::cout << filename << ": " << strerror(errno) << std::endl;
		return (1);
	}

	std::string s1(av[2]);
	std::string s2(av[3]);
	std::string line;

	while (std::getline(infile, line))
		otfile << my_replace(line, s1, s2) << std::endl;

	infile.close();
	otfile.close();
	return (0);
}
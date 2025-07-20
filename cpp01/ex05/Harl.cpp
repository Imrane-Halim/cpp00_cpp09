#include "Harl.hpp"

struct Harl::stFunctions {
	std::string _name;
	void		(Harl::*fun)(void);
};

void	Harl::debug(void) {
	std::cout << "[\e[0;34mDEBUG\e[0m]\t\t: debuging message" << std::endl; 
}
void	Harl::info(void) {
	std::cout << "[\e[0;32mINFO\e[0m]\t\t: info message" << std::endl; 
}
void	Harl::warning(void) {
	std::cout << "[\e[0;33mWARNING\e[0m]\t: warning message" << std::endl; 
}
void	Harl::error(void) {
	std::cout << "[\e[0;31mERROR\e[0m]\t\t: error message" << std::endl; 
}

void	Harl::complain(std::string level) {
	static Harl::stFunctions list[] =
	{
		{"debug", &Harl::debug},
		{"info", &Harl::info},
		{"warning", &Harl::warning},
		{"error", &Harl::error}
	};

	for (int i = 0; i < 4; i++)
	{
		if (list[i]._name == level)
			return (this->*list[i].fun)();
	}
	std::cout << level;
	std::cout << ": Unknown level!" << std::endl;
}

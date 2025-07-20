#include "Harl.hpp"

void	Harl::debug(void) { std::cout << "[\e[0;34mDEBUG\e[0m]\ndebuging message\n" << std::endl; }
void	Harl::info(void) { std::cout << "[\e[0;32mINFO\e[0m]\ninfo message\n" << std::endl; }
void	Harl::warning(void) { std::cout << "[\e[0;33mWARNING\e[0m]\nwarning message\n" << std::endl; }
void	Harl::error(void) { std::cout << "[\e[0;31mERROR\e[0m]\nerror message\n" << std::endl; }

levels	Harl::_getLevel(std::string level) {
	return (level == "INFO" ? INFO : 
			level == "DEBUG" ? DEBUG : 
			level == "WARNING" ? WARNING : 
			level == "ERROR" ? ERROR : UNKNOWN);
}

void	Harl::complain(std::string level) {
	switch (Harl::_getLevel(level))
	{
	case DEBUG:
		debug();
	case INFO:
		info();
		break;
	case WARNING:
		warning();
	case ERROR:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

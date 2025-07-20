#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

std::string	readUserInput(std::string msg)
{
	std::string input = "";

	while (input.empty() && !std::cin.eof())
	{
		std::cout << msg;
		std::getline(std::cin, input);
	}
	return (input);
}

void	cmd_add(PhoneBook &book)
{
	book.addContact();
}

void	cmd_search(PhoneBook &book)
{
	int			index = 0;
	std::string leftovers = "";

	book.displayAllContacts();

	std::stringstream iss(readUserInput("Enter index: "));

	iss >> index;
	if (iss.fail() || (iss >> leftovers))
	{
		std::cout << "Not a valid number!" << std::endl;
		return; 
	}
	if (index < 1 || index > 8)
	{
		std::cout << "Index out of range! (1-8)" << std::endl;
		return ;
	}
	book.displayTargetIndex(index - 1);
}

int main(void)
{
	PhoneBook	book;
	std::string		cmd;

	while (true)
	{
		cmd = readUserInput("Enter a command (ADD, SEARCH, EXIT): ");

		if (cmd.empty())
		{
			std::cout << std::endl;
			std::cout << "Exiting . . ." << std::endl;
			break;
		}
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			cmd_add(book);
		else if (cmd == "SEARCH")
			cmd_search(book);
		else
			std::cout << "Invalid Command!" << std::endl;
	}

	return (0);
}
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _size(0), _index(-1)
{
	for (int i = 0; i < 8; i++)
		_list[i] = Contact();
}

void	PhoneBook::displayTargetIndex(short index)
{
	if (index > _size - 1)
	{
		std::cout << std::endl;
		std::cout << "--> No contactInformation" << std::endl;
		std::cout << std::endl;
		return;
	}
	_list[index].displayInfo();
}

void	PhoneBook::_print_clm(std::string s)
{
	std::cout << "|";
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i + s.length() < 10)
			std::cout << " ";
		else if (i == 9 && s.length() >= 10)
			std::cout << ".";
		else
			std::cout << s[j++];
	}
}

void	PhoneBook::_print_row(short index, Contact &n)
{
	std::cout << "|        " << index;
	_print_clm(n.getFirstName());
	_print_clm(n.getLastName());
	_print_clm(n.getNickName());
	std::cout << "|" << std::endl;
}

void	PhoneBook::displayAllContacts(void)
{
	std::cout << std::endl;
	std::cout << "+---------+----------+----------+----------+" << std::endl;
	std::cout << "|  Index  | First N  |  Last N  |  Nick N  |" << std::endl;
	std::cout << "+---------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < _size; i++)
		_print_row(i + 1, _list[i]);
	std::cout << "+---------+----------+----------+----------+" << std::endl;
	std::cout << std::endl;
}

bool	PhoneBook::_is_valid_phone(std::string Phone)
{
	int i = 0;

	if (Phone[i] == '+')
		i++;
	while (Phone[i])
	{
		if (!isdigit(Phone[i]))
			return (false);
		i++;
	}
	return (true);
}

void	PhoneBook::_readContactInfo(Contact &n)
{
	std::string Fname = readUserInput("Enter first name : ");
	std::string Lname = readUserInput("Enter last name  : ");
	std::string Nname = readUserInput("Enter Nick name  : ");
	std::string Phone = readUserInput("Enter Phone      : ");
	
	if (!_is_valid_phone(Phone))
	{
		if (_size < 8)
			_size--;
		_index--;
		std::cout << "Wrong Phone Num!" << std::endl;
		return ;
	}

	std::string Secrt = readUserInput("Enter Dark secret: ");

	n.setFirstName(Fname);
	n.setLastName(Lname);
	n.setNeckName(Nname);
	n.setPhoneNum(Phone);
	n.setDarkestSecret(Secrt);
}

void	PhoneBook::addContact(void)
{
	if (_size < 8)
		_size++;
	_index = (_index + 1) % 8;
	_readContactInfo(_list[_index]);
}
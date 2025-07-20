#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

std::string	readUserInput(std::string msg);

class PhoneBook
{
	Contact	_list[8];
	short	_size;
	short	_index;

	bool	_is_valid_phone(std::string phone);
	void	_readContactInfo(Contact &n);
	void	_print_row(short index, Contact &n);
	void	_print_clm(std::string s);
public:
	PhoneBook();

	void	displayTargetIndex(short Index);
	void	displayAllContacts(void);
	void	addContact(void);
};

#endif
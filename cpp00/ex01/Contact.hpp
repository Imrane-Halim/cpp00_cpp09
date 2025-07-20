#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>

// ************************************************************************** //
//                            Contact Class                                   //
// ************************************************************************** //

class Contact
{
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NeckName;
	std::string	_PhoneNum;
	std::string	_DarkestSecret;
public:

	Contact();
	
	void	setFirstName(std::string new_value);
	void	setLastName(std::string new_value);
	void	setNeckName(std::string new_value);
	void	setPhoneNum(std::string new_value);
	void	setDarkestSecret(std::string new_value);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNum(void) const;
	std::string	getDarkestSecret(void) const;

	void	displayInfo(void);
};

#endif
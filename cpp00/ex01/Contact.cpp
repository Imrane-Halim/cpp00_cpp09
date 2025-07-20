#include "Contact.hpp"

Contact::Contact(): _FirstName(""), _LastName(""),
	_NeckName(""), _PhoneNum(""), _DarkestSecret("") {}

void	Contact::displayInfo(void)
{
	std::cout << std::endl;
	std::cout << "--> Contact Information:" << std::endl;
	std::cout << "First name : " << _FirstName << std::endl;
	std::cout << "Last name  : " << _LastName << std::endl;
	std::cout << "Nick name  : " << _NeckName << std::endl;
	std::cout << "Phone Num  : " << _PhoneNum << std::endl;
	std::cout << "Secrect    : " << _DarkestSecret << std::endl;
	std::cout << std::endl;
}

void	Contact::setFirstName(std::string new_value) {_FirstName = new_value;}
void	Contact::setLastName(std::string new_value) {_LastName = new_value;}
void	Contact::setNeckName(std::string new_value) {_NeckName = new_value;}
void	Contact::setPhoneNum(std::string new_value) {_PhoneNum = new_value;}
void	Contact::setDarkestSecret(std::string new_value) {_DarkestSecret = new_value;}

std::string	Contact::getFirstName(void) const {return (_FirstName);}
std::string	Contact::getLastName(void) const {return (_LastName);}
std::string	Contact::getNickName(void) const {return (_NeckName);}
std::string	Contact::getPhoneNum(void) const {return (_PhoneNum);}
std::string	Contact::getDarkestSecret(void) const {return (_DarkestSecret);}
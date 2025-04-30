#pragma once
#ifndef __PRESIDENTIALPARDONFORM__
#define __PRESIDENTIALPARDONFORM__

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	std::string	_target;
	void		_pardon(void) const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target, const std::string &name);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	void	execute(const Bureaucrat &execute) const;
};

#endif
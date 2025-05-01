#pragma once
#ifndef __SHRUBBERY_CREATION_FORM__
#define __SHRUBBERY_CREATION_FORM__

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	std::string	_target;
	void		_drawTree(void) const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

	void	execute(const Bureaucrat &execute) const;
};

#endif
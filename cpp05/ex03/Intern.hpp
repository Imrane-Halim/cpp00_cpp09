#pragma once
#ifndef __INTERN__
#define __INTERN__

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	struct sForms
	{
		std::string _name;
		AForm		*(Intern::*func)(const std::string &target);
	};

	AForm	*_shrubbery(const std::string &target);
	AForm	*_robotonomy(const std::string &target);
	AForm	*_pardon(const std::string &target);

public:
	Intern();
	Intern(const Intern &cpy);
	~Intern();

	Intern	&operator=(const Intern &copy);

	AForm*	makeForm(const std::string &name, const std::string &target);
};

#endif
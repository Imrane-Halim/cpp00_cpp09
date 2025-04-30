#pragma once
#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	std::string	_target;
	void		_robotomize(void) const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target, const std::string &name);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

	void	execute(const Bureaucrat &execute) const;
};

#endif
#pragma once
#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_signed;
	short			_signGrade;
	short			_execGrade;

	class GradeTooHighException: public std::exception {
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		const char*	what() const throw();
	};

	void	_setGrade(short &target, short grade);
public:
	Form();
	Form(const std::string &name, short signGrade, short execGrade);
	Form(const Form &copy);
	~Form();

	Form	&operator=(const Form &copy);

	void	beSigned(const Bureaucrat &obj);

	const std::string	&getName(void) const;
	bool				getSignStatus(void) const;
	short			getSignGrade(void) const;
	short			getExecGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
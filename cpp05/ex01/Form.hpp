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
	const short			_signGrade;
	const short			_execGrade;

	class GradeTooHighException: public std::exception {
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		const char*	what() const throw();
	};

public:
	Form(const std::string &name, short signGrade, short execGrade);
	Form(const Form &copy);
	~Form();

	Form	&operator=(const Form &copy);

	void	beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
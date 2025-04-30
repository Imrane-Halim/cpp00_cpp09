#pragma once
#ifndef __AFORM__
#define __AFORM__

#include <iostream>
#include <exception>
#include <fstream>
#include <cerrno>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	const std::string	_name;
	bool				_signed;
	const short			_signGrade;
	const short			_execGrade;

public:
	class GradeTooHighException: public std::exception {
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		const char*	what() const throw();
	};
	class UnsignedForm: public std::exception {
	public:
		const char*	what() const throw();
	};

public:
	AForm(const std::string &name, short signGrade, short execGrade);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm	&operator=(const AForm &copy);

	void			beSigned(const Bureaucrat &obj);
	virtual void	execute(const Bureaucrat &execute) const = 0;

	const std::string	&getName(void) const;
	bool				getSignStatus(void) const;
	short			getSignGrade(void) const;
	short			getExecGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
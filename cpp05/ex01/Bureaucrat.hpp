#pragma once
#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
	const std::string	_name;
	short int			_grade;

	class GradeTooHighException: public std::exception {
	public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		const char*	what() const throw();
	};

	void	_setGrade(short int grade);
public:
	Bureaucrat(const std::string &name, short int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &copy);

	const std::string		&getName(void) const;
	const short	&getGrade(void) const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(const Form &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
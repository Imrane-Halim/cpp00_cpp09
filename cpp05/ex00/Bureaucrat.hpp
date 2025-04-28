#pragma once
#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <exception>

class Bureaucrat {
	short int	_grade;
	const std::string	_name;

	class GradeTooHighException: public std::exception {
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception {
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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
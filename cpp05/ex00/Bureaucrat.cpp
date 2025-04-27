#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, unsigned short int grade):
_name(name)
{
	_setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

void		Bureaucrat::_setGrade(unsigned short int grade)
{
	try
	{
		Bureaucrat::GradeTooLowException	lowGrade;
		Bureaucrat::GradeTooHighException	highGrade;
		if (grade < 1)
			throw highGrade;
		if (grade > 150)
			throw lowGrade;
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		// this is 'const std::string'
		//_name = copy._name;
		_setGrade(copy._grade);
	}
	return *this;
}

const std::string	&Bureaucrat::getName(void) const
{
	return _name;
}

const unsigned short int	&Bureaucrat::getGrade(void) const
{
	return _grade;
}
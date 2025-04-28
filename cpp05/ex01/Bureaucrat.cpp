#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, short int grade):
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

void		Bureaucrat::_setGrade(short int grade)
{
	try
	{
		if (grade < 1) throw GradeTooHighException();
		if (grade > 150) throw GradeTooLowException();
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		if (_grade < 1 || _grade > 150)
			_grade = -1;
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

const short int	&Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	_setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	_setGrade(_grade + 1);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}
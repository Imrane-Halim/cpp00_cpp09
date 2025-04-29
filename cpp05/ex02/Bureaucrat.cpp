#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, short int grade):
_name(name)
{
	_setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
_name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

void		Bureaucrat::_setGrade(short int grade)
{
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		_grade = copy._grade;
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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName();
		std::cout << " because of low grade." << std::endl;
	}
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}
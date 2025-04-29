#include "Form.hpp"

Form::Form(const std::string &name, short signGrade, short execGrade):
_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {}

Form::Form(const Form &copy):
_signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
}

Form::~Form() {}

Form	&Form::operator=(const Form &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

void	Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException";
}

const std::string	&Form::getName(void) const { return _name; }
bool				Form::getSignStatus(void) const { return _signed; }
short				Form::getSignGrade(void) const { return _signGrade; }
short				Form::getExecGrade(void) const { return _execGrade; }

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "form name                     : " << obj.getName() << std::endl;
	os << "form signed                   : " << obj.getSignStatus() << std::endl;
	os << "form requred signing grade    : " << obj.getSignGrade() << std::endl;
	os << "form required execution grade : " << obj.getExecGrade() << std::endl;

	return os;
}
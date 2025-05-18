#include "AForm.hpp"

AForm::AForm():
	_name("NO_NAME"),
	_signed(false),
	_signGrade(1),
	_execGrade(1) {}
AForm::AForm(const std::string &name, short signGrade, short execGrade):
	_name(name),
	_signed(false)
{		
	_setGrade(_signGrade, signGrade);
	_setGrade(_execGrade, execGrade);
}

AForm::AForm(const AForm &copy):
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
	*this = copy;
}

AForm::~AForm() {}

AForm	&AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return *this;
}

void		AForm::_setGrade(short &target, short grade)
{
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	target = grade;
}

void	AForm::beSigned(const Bureaucrat &obj)
{
	if (_signed) return;
	if (obj.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException";
}

const char*	AForm::UnsignedForm::what() const throw() {
	return "AForm::UnsignedForm";
}

const std::string	&AForm::getName(void) const { return _name; }
bool				AForm::getSignStatus(void) const { return _signed; }
short				AForm::getSignGrade(void) const { return _signGrade; }
short				AForm::getExecGrade(void) const { return _execGrade; }

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "Aform name                     : " << obj.getName() << std::endl;
	os << "Aform signed                   : " << obj.getSignStatus() << std::endl;
	os << "Aform requred signing grade    : " << obj.getSignGrade() << std::endl;
	os << "Aform required execution grade : " << obj.getExecGrade() << std::endl;

	return os;
}
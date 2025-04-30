#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("NO_NAME", -1, -1), _target("NO_TARGET") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target, const std::string &name):
AForm(name, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
AForm(copy.getName(), 25, 5), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return *this;
}

void	PresidentialPardonForm::_pardon(void) const
{
	std::cout << _target;
	std::cout << " has been pardoned by Zaphod Beeblebrox\n";
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSignStatus() == false)
		throw UnsignedForm();
	_pardon();
}
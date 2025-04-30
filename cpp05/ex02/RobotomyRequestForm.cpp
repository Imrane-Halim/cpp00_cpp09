#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
AForm("NO_NAME", -1, -1), _target("NO_TARGET")
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target, const std::string &name):
AForm(name, 72, 45), _target(target)
{
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
AForm(copy.getName(), 72, 45), _target(copy._target)
{
	srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return *this;
}

void	RobotomyRequestForm::_robotomize(void) const
{
	std::cout << "DRILLING NOISE ...... !\n";

	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully";
	else
		std::cout << "robotomy failed";
		
	std::cout << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSignStatus() == false)
		throw UnsignedForm();
	_robotomize();
}
#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &copy) { *this = copy; }
Intern::~Intern() {}

Intern&	Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

AForm	*Intern::_shrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}
AForm	*Intern::_robotonomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}
AForm	*Intern::_pardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm	*form;
	static const sForms forms[] =
	{
		{"robotonomy request", &Intern::_robotonomy},
		{"shruberry creation", &Intern::_shrubbery},
		{"presidential pardon", &Intern::_pardon},
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i]._name == name)
		{
			form = (this->*forms[i].func)(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cout << "the form name does not exist" << std::endl;
	
	return NULL;
}

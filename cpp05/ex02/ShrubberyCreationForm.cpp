#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("NO_NAME", -1, -1), _target("NO_TARGET") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target, const std::string &name):
AForm(name, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
AForm(copy.getName(), 145, 137), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		_target = cpy._target;
	}
	return *this;
}

void	ShrubberyCreationForm::_drawTree(void) const
{
	std::string		f_name = _target + "_shurbbery";
	std::ofstream	file(f_name.c_str());

	if (!file.is_open())
	{
		std::perror("Error");
		return;
	}

    std::string tree[] = {
        "          &&& &&  & &&",
        "      && &\\/&\\|& ()|/ @, &&",
        "      &\\/(/&/&||/& /_/)_&/_&",
        "   &() &\\/&|()|/&\\/ '%\" & ()",
        "  &_\\_&&_\\ |& |&&/&__%_/_& &&",
        "&&   && & &| &| /& & % ()& /&&",
        " ()&_---()&\\&\\|&&-&&--%---()~",
        "     &&     \\|||",
        "             |||",
        "             |||",
        "             |||",
		"_____________+++________________"
    };
	
	for (int i = 0; i < 12; i++)
		file << tree[i] << '\n';
	file.close();
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSignStatus() == false)
		throw UnsignedForm();
	_drawTree();
}
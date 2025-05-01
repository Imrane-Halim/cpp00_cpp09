#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
    // -----------><---------------
    std::cout << "test 1:" << std::endl;
    try {
        Bureaucrat  moron("jamal", 1);
        ShrubberyCreationForm form("me");

        moron.signForm(form);
        form.execute(moron);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } 

    // -----------><---------------
    std::cout << "\n\ntest 2:" << std::endl;
    Bureaucrat  moron("jamal", 1);
    RobotomyRequestForm form("me");
    for (int i = 0; i < 5; i++)
    {
        try {
            moron.signForm(form);
            form.execute(moron);
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    
    // -----------><---------------
    std::cout << "\n\ntest 3:" << std::endl;
    try {
        Bureaucrat  moron("jamal", 1);
        PresidentialPardonForm form("me");

        moron.signForm(form);
        form.execute(moron);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } 

    // -----------><---------------
    std::cout << "\n\ntest 4:" << std::endl;
    Bureaucrat  man("jamal", 1);
    PresidentialPardonForm obj("me");

    man.signForm(obj);
    man.executeForm(obj);

    return 0;
}
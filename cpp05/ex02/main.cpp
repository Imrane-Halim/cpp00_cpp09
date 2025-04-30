#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    try {
        Bureaucrat  moron("jamal", 1);
        ShrubberyCreationForm form("me", "pardon", 2, 2);

        moron.signForm(form);
        form.execute(moron);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
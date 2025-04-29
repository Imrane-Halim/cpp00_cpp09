#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    try {
        Bureaucrat  moron("jamal", 1);
        Form        form("license", 2, 2);

        std::cout << moron;
        std::cout << form;
        moron.signForm(form);
        std::cout << form;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
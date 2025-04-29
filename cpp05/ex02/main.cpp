#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void) {
    try {
        Bureaucrat  moron("jamal", 3);
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
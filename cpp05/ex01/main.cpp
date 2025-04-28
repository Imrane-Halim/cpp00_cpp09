#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat moron("jamal", 150);
        std::cout << moron;
        moron.decrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
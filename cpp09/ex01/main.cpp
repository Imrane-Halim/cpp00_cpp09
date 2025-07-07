#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "usage: ./RPN <exprestion>\n";
        return EXIT_FAILURE;
    }

    try
    {
        std::stringstream ss(av[1]);
        std::cout << solve(ss) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return EXIT_SUCCESS;
}
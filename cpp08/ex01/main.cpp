#include "Span.hpp"

int main()
{
    // try
    // {
    //     Span small(1);
    //     small.addNumber(1);
    //     small.addNumber(1);
    // }
    // catch(const std::exception& e)
    // { std::cerr << "Error: " << e.what() << '\n'; }

    // try
    // {
    //     Span big(50000);
    //     big.addRange(1, 50000);
    //     big.print();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    Span nums(5);

    nums.addNumber(1);
    nums.addNumber(19);
    nums.addNumber(17);
    nums.addNumber(9);
    nums.addNumber(2);

    std::cout << "longest  span: " << nums.longestspan() << std::endl;
    std::cout << "shortest span: " << nums.shortestSpan() << std::endl;

    return 0;
}
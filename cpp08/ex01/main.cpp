#include "Span.hpp"
#include <list>

int main()
{

    try
    {
        Span big(10);
        std::list<int> range;
    
        big.addNumber(9999);
        big.addNumber(345);
        
        for (int i = 1; i < 7; ++i)
            range.push_back(i * 23);
        
        big.addRange(range.begin(), range.end());

        std::cout << "shortest span: " << big.shortestSpan() << '\n';
        std::cout << "longest span : " << big.longestSpan() << '\n';
    }
    catch(const std::exception& e)
    { std::cerr << e.what() << '\n'; }

    return 0;
}
#include "Span.hpp"
#include <bits/stdc++.h>
int main()
{
    // Span span;
    std::vector<int> v(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(61713);
    try
    {
        /* code */
        std::cout << std::find(v.begin(), v.end(), 33)[1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
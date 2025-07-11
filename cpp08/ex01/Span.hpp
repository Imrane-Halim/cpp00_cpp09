#ifndef __SPAN__
#define __SPAN__

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>

class Span
{
    std::vector<int> _vec;
    unsigned int     _max;

public:
    Span();
    Span(unsigned int max);
    Span(const Span& other);
    ~Span();

    Span&   operator=(const Span& other);

    void    addNumber(int num);
    void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int     shortestSpan();
    int     longestspan();

    void    print(void) const;
};

#endif
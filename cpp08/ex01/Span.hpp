#ifndef __SPAN__
#define __SPAN__

#include <iostream>
#include <vector>

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
    int     shortestSpan();
    int     longestspan();
};

#endif
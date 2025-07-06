#ifndef __SPAN__
#define __SPAN__

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>

int _numGen();

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
    void    addRange(int n_elem);
    int     shortestSpan();
    int     longestspan();

    void    print(void) const;
};

#endif
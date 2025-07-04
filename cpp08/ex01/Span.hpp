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

    class _NumGen {
        int     _num;
    public:
        _NumGen(int num);
        int operator()();
    };

public:
    Span();
    Span(unsigned int max);
    Span(const Span& other);
    ~Span();

    Span&   operator=(const Span& other);

    void    addNumber(int num);
    void    addRange(int start, int end);
    int     shortestSpan();
    int     longestspan();

    void    print(void) const;
};

#endif
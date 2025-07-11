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
    
    template<typename inputIterator>
    void    addRange(inputIterator begin, inputIterator end)
    {
        int	dist = std::distance(begin, end);

        if (_vec.size() + dist > _max)
            throw(std::runtime_error("Can't add range"));
        _vec.insert(_vec.end(), begin, end );
    }

    long     shortestSpan();
    long    longestSpan();

};

#endif
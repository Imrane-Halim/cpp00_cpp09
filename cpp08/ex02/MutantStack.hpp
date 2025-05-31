#pragma once
#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <iostream>
#include <exception>
#include <stack>


template<typename _t>
class MutantStack: public std::stack<_t>
{
public:
    typedef typename std::stack<_t>::container_type  container;
    typedef typename container::iterator             iterator;
    typedef typename container::const_iterator       const_iterator;
    typedef typename container::reverse_iterator     reverse_iterator;
public:
    MutantStack() { }
    // paramerized constructor is not needed
    MutantStack(const MutantStack& other): std::stack<_t>(other) { }
    ~MutantStack() { }

    MutantStack&    operator=(const MutantStack& other)
    {
        if (this != &other)
            std::stack<_t>::operator=(other);
        return *this;
    }

    iterator    begin(void) { return std::stack<_t>::c.begin(); }
    iterator    end(void)   { return std::stack<_t>::c.end(); }
    
    iterator    cbegin(void) const { return std::stack<_t>::c.cbegin(); }
    iterator    cend(void) const { return std::stack<_t>::c.cend(); }
    
    iterator    rbegin(void) { return std::stack<_t>::c.rbegin(); }
    iterator    rend(void)   { return std::stack<_t>::c.rend(); }
    
};

#endif
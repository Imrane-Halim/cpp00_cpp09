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
    MutantStack(const MutantStack& other): std::stack<_t>(other) { }
    ~MutantStack() { }

    MutantStack&    operator=(const MutantStack& other)
    {
        if (this != &other)
            this->operator=(other);
        return *this;
    }

    iterator    begin(void) { return this->c.begin(); }
    iterator    end(void)   { return this->c.end(); }
    
    iterator    cbegin(void) const { return this->c.cbegin(); }
    iterator    cend(void) const { return this->c.cend(); }
    
    iterator    rbegin(void) { return this->c.rbegin(); }
    iterator    rend(void)   { return this->c.rend(); }
    
};

#endif
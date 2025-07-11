#pragma once
#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <iostream>
#include <exception>
#include <stack>


template<typename T>
class MutantStack: public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type      container;
    typedef typename container::iterator                iterator;
    typedef typename container::const_iterator          const_iterator;
    typedef typename container::reverse_iterator        reverse_iterator;
    typedef typename container::const_reverse_iterator  const_reverse_iterator;

public:
    MutantStack() { }
    MutantStack(const MutantStack& other): std::stack<T>(other) { }
    ~MutantStack() { }

    MutantStack&    operator=(const MutantStack& other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

    iterator    begin(void) { return this->c.begin(); }
    iterator    end(void)   { return this->c.end(); }
    
    const_iterator  cbegin(void) const { return this->c.begin(); }
    const_iterator  cend(void) const { return this->c.end(); }
    
    reverse_iterator    rbegin(void) { return this->c.rbegin(); }
    reverse_iterator    rend(void)   { return this->c.rend(); }

    const_reverse_iterator crbegin() const { return this->c.rbegin(); }
    const_reverse_iterator crend() const { return this->c.rend(); }
    
};

#endif
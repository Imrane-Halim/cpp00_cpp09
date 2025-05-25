#pragma once
#ifndef __MUTANTSTACK__
#define __MUTANTSTACK__

#include <iostream>
#include <exception>
#include <stack>

template<typename _t>
class Iterator
{
    _t*     _ptr;

public:
    Iterator(): _ptr(NULL) { }
    Iterator(const _t* ptr): _ptr(const_cast<_t*>(ptr)) { }
    Iterator(const Iterator& other): _ptr(other._ptr) { }
    ~Iterator() {}

    _t&     operator*() { return *_ptr; }
    _t*     operator->() { return _ptr; }

    // pre:  ++foo
    Iterator&   operator++()
    {
        ++_ptr;
        return *this;
    }  
    Iterator&   operator--()
    {
        --_ptr;
        return *this;
    }

    // post: foo++
    Iterator    operator++(int)
    {
        Iterator    tmp = *this;
        ++(*this);
        return tmp;
    }
    Iterator    operator--(int)
    {
        Iterator    tmp = *this;
        --(*this);
        return tmp;
    }

    bool        operator==(const Iterator& other)
    {
        return this->_ptr == other._ptr;
    }
    bool        operator!=(const Iterator& other)
    {
        return this->_ptr != other._ptr;
    }

};


template<typename _t>
class MutantStack: public std::stack<_t>
{
public:
    typedef Iterator<_t> iterator;
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

    iterator    begin(void)
    {
        return iterator(&this->top() - (this->size() + 1));
    }
    
    iterator    end(void)
    {
        return iterator(&this->top());
    }
};

#endif
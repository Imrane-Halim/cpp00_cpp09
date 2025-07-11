#include "MutantStack.hpp"
#include <list>

typedef std::list<int> list;

int main()
{

    list lst;
    MutantStack<int> stk;

    for (int i = 0; i < 10; ++i)
    {
        lst.push_back(i * 23);
        stk.push(i * 23);
    }

    for (list::iterator i = lst.begin(); i != lst.end(); ++i)
        *i += (*i % 2) ? 10 : -10;
    // std::list<int>::const_iterator cit;
    for (list::reverse_iterator i = lst.rbegin(); i != lst.rend(); ++i)
        *i *= (*i % 2) ? 83 : 11;
    // std::list<int>::const_reverse_iterator crit;

    // --------------------------------------------------

    for (MutantStack<int>::iterator i = stk.begin(); i != stk.end(); ++i)
        *i += (*i % 2) ? 10 : -10;
    // MutantStack<int>::const_iterator cit;
    for (MutantStack<int>::reverse_iterator i = stk.rbegin(); i != stk.rend(); ++i)
        *i *= (*i % 2) ? 83 : 11;
    // MutantStack<int>::const_reverse_iterator crit;

    std::cout << "  lst\t|\tmyStack\n";
    std::cout << "----------------------\n";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << lst.back() << "\t|\t" << stk.top() << "\n";
        lst.pop_back();
        stk.pop();
    }

    return 0;
}
#ifndef __PMERGEME__
#define __PMERGEME__

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <algorithm>
#include <set>

int*    initArr(int* arr, int ac, char** av);

template<typename _t>
void    printNums(_t lst, int size, const std::string& msg)
{
    std::cout << msg;
    for (int i = 0; i < size; i++)
        std::cout << lst[i] << " ";
    std::cout << '\n';
}

#endif
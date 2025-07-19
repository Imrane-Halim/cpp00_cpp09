#ifndef __PMERGEME__
#define __PMERGEME__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <algorithm>
#include <set>
#include <deque>
#include <ctime>
#include <iomanip>

int*    initArr(int* arr, int ac, char** av);

template<typename T>
void    printNums(T lst, int size, const std::string& msg)
{
    std::cout << msg;
    for (int i = 0; i < size; i++)
        std::cout << lst[i] << " ";
    std::cout << '\n';
}

template<typename T>
T insertOrder(int n)
{
    T seq;
    seq.push_back(0);
    seq.push_back(1);

    int prev = 1;
    int next = 3;
    while ((int)seq.size() < n)
    {
        for (int i = (next >= n ? n - 1: next); i > prev; --i)
        {
            seq.push_back(i);
            if ((int)seq.size() == n) break;
        }
        prev = next;
        next = next + 2 * prev;
    }
    return seq;
}

void    sortDeque(std::deque<int>& vc);
void    sortVector(std::vector<int>& vc);

#endif
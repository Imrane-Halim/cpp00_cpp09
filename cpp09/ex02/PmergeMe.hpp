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

typedef std::vector<int> vec;
typedef std::deque<int> deq;

int*    initArr(int* arr, int ac, char** av);

template<typename _t>
void    printNums(_t lst, int size, const std::string& msg)
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

    int next = 3;
    while ((int)seq.size() <= n)
    {
        if (next < n)
        {
            seq.push_back(next);
            continue;
        }

        int prev = seq[seq.size() - 2];

        for (int i = next - 1; i > prev; --i)
        {
            seq.push_back(i);
            if ((int)seq.size() == n) break;
        }
        next = next + 2 * prev;
    }

    return seq;
}

#endif
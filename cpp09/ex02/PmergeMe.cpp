#include "PmergeMe.hpp"

int*    initArr(int* arr, int ac, char** av)
{
    char*   end = NULL;
    long    tmp;
    std::set<int> seen;

    for (int i = 0; i < ac; i++)
    {
        tmp = strtol(av[i], &end, 10);
        if (*end != '\0')
            throw(std::runtime_error("invalid number: " + std::string(av[i])));
        if (tmp > INT_MAX || tmp < INT_MIN || errno == ERANGE)
            throw(std::runtime_error("range error: " + std::string(av[i])));   
        if (!seen.insert(tmp).second)
            throw(std::runtime_error("duplicates: " + std::string(av[i])));
        arr[i] = tmp;
    }

    return arr;
}

void    sortDeque(std::deque<int>& vc)
{
    if (vc.size() == 1) return;

    std::deque<int> bigs;
    std::deque<int> smls;
    for (int i = 0; i < (int)vc.size() - 1; i += 2)
    {
        if (vc[i] > vc[i + 1])
            std::swap(vc[i], vc[i + 1]);
        bigs.push_back(vc[i + 1]);
        smls.push_back(vc[i]);
    }
    int hasLeftover = vc.size() % 2;
    int leftover = hasLeftover ? vc.back() : 0;

    sortDeque(bigs);

    std::deque<int> S = bigs;

    if (smls.size())
    {
        std::deque<int> order = insertOrder<std::deque<int> >((int)smls.size());
        for (int i = 0; i < (int)smls.size(); ++i)
        {
            int idx = order[i];
            std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), smls[idx]);
            S.insert(pos, smls[idx]);
        }
    }

    if (hasLeftover)
    {
        std::deque<int>::iterator pos = std::lower_bound(S.begin(), S.end(), leftover);
        S.insert(pos, leftover);
    }

    vc = S;
}

void    sortVector(std::vector<int>& vc)
{
    if (vc.size() == 1) return;

    std::vector<int> bigs;
    std::vector<int> smls;
    for (int i = 0; i < (int)vc.size() - 1; i += 2)
    {
        if (vc[i] > vc[i + 1])
            std::swap(vc[i], vc[i + 1]);
        bigs.push_back(vc[i + 1]);
        smls.push_back(vc[i]);
    }
    int hasLeftover = vc.size() % 2;
    int leftover = hasLeftover ? vc.back() : 0;

    sortVector(bigs);

    std::vector<int> S = bigs;

    if (smls.size())
    {
        std::vector<int> order = insertOrder<std::vector<int> >((int)smls.size());
        for (int i = 0; i < (int)smls.size(); ++i)
        {
            int idx = order[i];
            std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), smls[idx]);
            S.insert(pos, smls[idx]);
        }
    }

    if (hasLeftover)
    {
        std::vector<int>::iterator pos = std::lower_bound(S.begin(), S.end(), leftover);
        S.insert(pos, leftover);
    }

    vc = S;
}


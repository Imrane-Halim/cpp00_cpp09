#include "PmergeMe.hpp"

// void    sortList(std::list<int>& lst)
// {
//     (void)lst;
//     // todo
// }

vec insertOrder(int n)
{
    std::vector<int> seq;
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

void    sortVector(vec& vc)
{
    if (vc.size() == 1) return;

    vec bigs;
    vec smls;
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

    vec S = bigs;

    if (smls.size())
    {
        std::vector<int> order = insertOrder((int)smls.size());
        for (int i = 0; i < (int)smls.size(); ++i)
        {
            int idx = order[i];
            vec::iterator pos = std::lower_bound(S.begin(), S.end(), smls[idx]);
            S.insert(pos, smls[idx]);
        }
    }

    if (hasLeftover)
    {
        vec::iterator pos = std::lower_bound(S.begin(), S.end(), leftover);
        S.insert(pos, leftover);
    }

    vc = S;
}


int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cerr << "Usage: ./PmergeMe <NUM_LIST>\n";
        std::cerr << "Note : you need at least 2 number!\n";
        return EXIT_FAILURE;
    }

    int*   arr = new int[ac - 1];

    try {
        arr = initArr(arr, ac - 1, av + 1);
        printNums(arr, ac - 1, "Before: ");
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        delete[] arr;
        return EXIT_FAILURE;
    }
    
    vec vc(arr, arr + ac - 1);
    sortVector(vc);
    printNums(vc, vc.size(), "After : ");
    // std::list<int> lst(arr, arr + ac - 1);

    delete[] arr;

    return EXIT_SUCCESS;
}
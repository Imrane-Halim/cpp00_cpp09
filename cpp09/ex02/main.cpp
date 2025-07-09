#include "PmergeMe.hpp"

// void    sortList(std::list<int>& lst)
// {
//     (void)lst;
//     // todo
// }

std::vector<size_t> jacobSeq(size_t n)
{
    std::vector<size_t> seq;

    seq.push_back(0);
    seq.push_back(1);

    for (size_t i = 0; i < n; ++i)
    {
        size_t idx = seq.size() - 1;
        size_t next = seq[idx] + 2 * seq[idx - 1];
        seq.push_back(next);
    }
    
    return seq;
}

void    sortVector(vec& vc)
{
    if (vc.size() == 1) return;
    
    // 1. group elements of vc to [vc.size() / 2] pairs, if size is odd
    // leave one unpaired
    // 2. perform n/2 comparisons to find the larger of the 2 elements
    // in this case: paris[big, small]
    vec bigs;
    vec smls;
    for (size_t i = 0; i < vc.size() - 1; i += 2)
    {
        if (vc[i] > vc[i + 1])
            std::swap(vc[i], vc[i + 1]);
        bigs.push_back(vc[i + 1]);
        smls.push_back(vc[i]);
    }
    int hasLeftover = vc.size() % 2;
    int leftover = hasLeftover ? vc.back() : 0;

    // 3. recursively sort n/2 larger elements from each pair
    sortVector(bigs);

    // 4. insert the start of S  the element that was paired with 
    // the first and smallest element of S
    // todo;
    vec S = bigs;

    // 5. insert the remainin n/2-1 elements of vc/s into S, one at a time
    // using some jacobsthal seqecuence
    if (smls.size())
    {
        std::vector<size_t> order = jacobSeq(smls.size());
        for (int i = 0; i < (int)smls.size(); ++i)
        {
            size_t idx = order[i];
            vec::iterator pos = std::lower_bound(S.begin(), S.end(), smls[idx]);
            S.insert(pos, smls[i]);
        }
    }

    // 6. insert the leftover element
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
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <NUM_LIST>\n";
        return EXIT_FAILURE;
    }

    int*   arr = new int[ac - 1];

    try {
        arr = initArr(arr, ac - 1, av + 1);
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        delete[] arr;
        return EXIT_FAILURE;
    }
    
    std::vector<int> vc(arr, arr + ac - 1);
    sortVector(vc);

    std::deque<int> dq(arr, arr + ac - 1);
    sortDeque(dq);

    printNums(arr, ac - 1, "Before: ");
    printNums(vc, vc.size(), "After : ");

    delete[] arr;

    return EXIT_SUCCESS;
}
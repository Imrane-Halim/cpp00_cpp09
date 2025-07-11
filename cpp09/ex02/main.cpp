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
    
    std::clock_t start, end;
    double       vc_time, dq_time;

    start = std::clock();
    std::vector<int> vc(arr, arr + ac - 1);
    sortVector(vc);
    end = std::clock();
    vc_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    start = std::clock();
    std::deque<int> dq(arr, arr + ac - 1);
    sortDeque(dq);
    end = std::clock();
    dq_time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printNums(arr, ac - 1, "Before: ");
    printNums(vc, vc.size(), "After : ");
    std::cout << std::fixed;
    std::cout << "std::vecotr time: " << vc_time << "s\n";
    std::cout << "std::deque time : " << dq_time << "s\n";

    delete[] arr;

    return EXIT_SUCCESS;
}
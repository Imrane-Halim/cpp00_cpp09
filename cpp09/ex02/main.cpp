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
    vc_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
    
    start = std::clock();
    std::deque<int> dq(arr, arr + ac - 1);
    sortDeque(dq);
    end = std::clock();
    dq_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
    
    printNums(arr, ac - 1, "Before: ");
    printNums(vc, vc.size(), "After : ");
    std::cout << "Time to process " << ac - 1 
        << " elements with std::vector: " 
        << std::fixed << std::setprecision(5) << vc_time << " us\n";

    std::cout << "Time to process " << ac - 1 
        << " elements with std::deque: " 
        << std::fixed << std::setprecision(5) << dq_time << " us\n";


    delete[] arr;

    return EXIT_SUCCESS;
}
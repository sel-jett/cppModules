#include "PmergeMe.hpp"
#include <ctime>
#include <unistd.h>

int main(int ac, char **av) {
    if (ac >= 2) {
        PmergeMe pmerge;
        pmerge.ft_parcing(av);
        if ((pmerge.getVector()).size() > 0) {
            std::cout << "Before: ";
            pmerge.printVector();
            clock_t start = clock();
            // sleep(1.2);
            pmerge.setVector2(pmerge.getVector());
            pmerge.sortVector();
            clock_t end = clock();
            clock_t start2 = clock();
            pmerge.setDeque(pmerge.getVector());
            pmerge.sortDeque();
            clock_t end2 = clock();
            std::cout << "After: ";
            pmerge.printVector2();
            std::cout << "Time to process a range of " << pmerge.getVector().size() << " elements with std::vector : "
                      << static_cast<float>(end - start) * 1000000.0 / CLOCKS_PER_SEC << " us" << std::endl;
            std::cout << "Time to process a range of " << pmerge.getDeque().size() << " elements with std::deque : "
                      << static_cast<float>(end2 - start2) * 1000000.0 / CLOCKS_PER_SEC << " us" << std::endl;
        }
        else {
            std::cout << "Error" << std::endl;
            return -1;
        }
    }
    else {
        std::cout << "Commande example : ./PmergeMe 1 2 3 4 5 6 7 8 9 10" << std::endl;
        return -1;
    }
    return 0;
}


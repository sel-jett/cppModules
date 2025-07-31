#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac >= 2) {
        PmergeMe pmerge;
        pmerge.ft_parcing(av);
        if ((pmerge.getVector()).size() > 0) {
            std::cout << "Before: ";
            pmerge.printVector();
        }
        else {
            std::cout << "Error1" << std::endl;
            return -1;
        }
    }
    else {
        std::cout << "Error2" << std::endl;
        return -1;
    }
    return 0;
}


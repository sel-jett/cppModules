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
        std::cout << "Commande example : ./PmergeMe 1 2 3 4 5 6 7 8 9 10" << std::endl;
        return -1;
    }
    return 0;
}


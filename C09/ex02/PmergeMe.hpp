#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <climits>

class PmergeMe {
    private:
        std::vector<int> myvector;
        std::vector<int> myvector2;
        std::deque<int> mydeque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void setVector(std::vector<int> vvector);
        std::vector<int> getVector() const;
        void ft_parcing(char **av);
        void printVector() const;
        // void sortVector();
        // void sortDeque();
};

int	ft_atoi(const char *str);
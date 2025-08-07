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
        void setVector2(std::vector<int> vvector);
        std::vector<int> getVector() const;
        std::vector<int> getVector2() const;
        void setDeque(std::deque<int> deque);
        std::deque<int> getDeque() const;
        std::vector<int> getSequence(size_t size);
        std::vector<int> insertionPos(size_t size);
        
        void ft_parcing(char **av);
        void printVector() const;
        void sortVector();
        // void sortDeque();
};

int	ft_atoi(const char *str);
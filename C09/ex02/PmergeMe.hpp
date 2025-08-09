#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>

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
        void setDeque(std::vector<int> deque);
        std::deque<int> getDeque() const;
        std::vector<int> getSequenceVec(size_t size);
        std::deque<int> getSequenceDeq(size_t size);
        std::vector<int> insertPosVec(size_t size);
        std::deque<int> insertPosDeq(size_t size);

        void ft_parcing(char **av);
        void printVector() const;
        void printDeque() const;
        void printVector2() const;
        void sortVector();
        void sortDeque();
        // void sortDeque();
};

int	ft_atoi(const char *str);
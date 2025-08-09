#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        myvector = other.myvector;
        myvector2 = other.myvector2;
        mydeque = other.mydeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::ft_parcing(char **av) {
    int i = 0;
    char *p = NULL;
    std::vector<int> vvector;

    while (av[++i]) {
        p = strtok(av[i], " \r\t");
        if (!p) {
            std::cerr << "Error" << std::endl;
            return;
        }
        while (p) {
            vvector.push_back(ft_atoi(p));
            p = strtok(NULL, " \r\t");
        }
    }
    setVector(vvector);
}

void PmergeMe::printVector() const {
    for (std::vector<int>::const_iterator it = myvector.begin(); it != myvector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVector2() const {
    for (std::vector<int>::const_iterator it = myvector2.begin(); it != myvector2.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int	ft_atoi(const char *str) {
    int			i = 0;
    long int	num = 0;
    int			signe = 1;

    if (str[i] == '-' || str[i] == '+')
    {
        (str[i] == '-') && (signe = -1);
        i++;
    }
    if (!str[i] || str[i] == '\0' || signe == -1){
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        num = (num * 10) + (str[i] - 48);
        if (num > INT_MAX || num < INT_MIN) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        i++;
    }
    if (str[i]) {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    return (num);
}

// Done parcing

std::vector<int> PmergeMe::getVector() const {
    return myvector;
}

std::vector<int> PmergeMe::getVector2() const {
    return myvector;
}

void PmergeMe::setVector(std::vector<int> vvector) {
    this->myvector = vvector;
}

void PmergeMe::setVector2(std::vector<int> vvector) {
    this->myvector2 = vvector;
}

std::deque<int> PmergeMe::getDeque() const {
    return mydeque;
}

void PmergeMe::setDeque(std::deque<int> deque) {
    this->mydeque = deque;
}

std::vector<int> PmergeMe::getSequenceVec(size_t size) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    for (size_t i = 2; i < size; i++) {
        sequence.push_back((pow(2, (i + 1)) + pow((-1), i)) / 3);
    }
    return sequence;
}

std::deque<int> PmergeMe::getSequenceDeq(size_t size) {
    std::deque<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    for (size_t i = 2; i < size; i++) {
        sequence.push_back((pow(2, (i + 1)) + pow((-1), i)) / 3);
    }
    return sequence;
}

std::vector<int> PmergeMe::insertPosVec(size_t size) {
    if (size <= 1) return std::vector<int>();
    std::vector<int> sequence = getSequenceVec(size);
    std::vector<int> result;
    std::vector<char> mark(size, 0);
    mark[0] = 1;

    #define insertUnused(idx) \
        if ((idx) >= 0 && (idx) < (int)size && !mark[(idx)]) { \
            mark[(idx)] = 1; \
            result.push_back((idx)); \
        }

    for (size_t k = 1; k < sequence.size() && sequence[k] < static_cast<int>(size); ++k) {
        insertUnused(sequence[k]);
        int upper = sequence[k];
        int lower = sequence[k - 1];
        for (int idx = upper - 1; idx > lower; --idx) {
            insertUnused(idx);
        }
    }

    for (int idx = 1; idx < static_cast<int>(size); ++idx) {
        insertUnused(idx);
    }

    return result;
}


std::deque<int> PmergeMe::insertPosDeq(size_t size) {
    if (size <= 1) return std::deque<int>();
    std::deque<int> sequence = getSequenceDeq(size);
    std::deque<int> result;
    std::deque<char> mark(size, 0);
    mark[0] = 1;

    #define insertUnused(idx) \
        if ((idx) >= 0 && (idx) < (int)size && !mark[(idx)]) { \
            mark[(idx)] = 1; \
            result.push_back((idx)); \
        }

    for (size_t k = 1; k < sequence.size() && sequence[k] < static_cast<int>(size); ++k) {
        insertUnused(sequence[k]);
        int upper = sequence[k];
        int lower = sequence[k - 1];
        for (int idx = upper - 1; idx > lower; --idx) {
            insertUnused(idx);
        }
    }

    for (int idx = 1; idx < static_cast<int>(size); ++idx) {
        insertUnused(idx);
    }

    return result;
}

void PmergeMe::sortVector() {
    std::vector<int> mainchain;
    std::vector<int> pendchain;
    std::vector<std::pair<int, int> > pairs;
    
    int straggler = -1;
    if (myvector2.size() % 2 == 1) {
        straggler = myvector2.back();
        myvector2.pop_back();
    } 
    for (size_t i = 0; i < myvector2.size(); i += 2) {
        int pair1 = myvector2[i];
        int pair2 = myvector2[i + 1];
        if (pair2 > pair1) {
            std::swap(pair1, pair2);
        }
        pairs.push_back(std::make_pair(pair1, pair2));
    }
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainchain.push_back(pairs[i].first);
        pendchain.push_back(pairs[i].second);
    }
    
    if (mainchain.size() > 1) {
        myvector2 = mainchain;
        sortVector();
        mainchain = myvector2;
    }
    
    std::vector<int> result = mainchain;

    if (!pendchain.empty()) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendchain[0]);
        result.insert(pos, pendchain[0]);
    }
    
    if (pendchain.size() > 1) {
        std::vector<int> insertionOrder = insertPosVec(pendchain.size());
    
        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            if (idx > 0 && idx < (int)pendchain.size())
            {
                std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  pendchain[idx]);
                result.insert(pos,  pendchain[idx]);
            }
        }
    }
    
    if (straggler != -1) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    
    myvector2 = result;
}

void PmergeMe::sortDeque() {
    std::deque<int> mainchain;
    std::deque<int> pendchain;
    std::deque<std::pair<int, int> > pairs;
    
    int straggler = -1;
    if (mydeque.size() % 2 == 1) {
        straggler = mydeque.back();
        mydeque.pop_back();
    } 
    for (size_t i = 0; i < mydeque.size(); i += 2) {
        int pair1 = mydeque[i];
        int pair2 = mydeque[i + 1];
        if (pair2 > pair1) {
            std::swap(pair1, pair2);
        }
        pairs.push_back(std::make_pair(pair1, pair2));
    }
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainchain.push_back(pairs[i].first);
        pendchain.push_back(pairs[i].second);
    }
    
    if (mainchain.size() > 1) {
        mydeque = mainchain;
        sortVector();
        mainchain = mydeque;
    }
    
    std::deque<int> result = mainchain;

    if (!pendchain.empty()) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendchain[0]);
        result.insert(pos, pendchain[0]);
    }
    
    if (pendchain.size() > 1) {
        std::deque<int> insertionOrder = insertPosDeq(pendchain.size());
    
        for (size_t i = 0; i < insertionOrder.size(); i++)
        {
            int idx = insertionOrder[i];
            if (idx > 0 && idx < (int)pendchain.size())
            {
                std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  pendchain[idx]);
                result.insert(pos,  pendchain[idx]);
            }
        }
    }
    
    if (straggler != -1) {
        std::deque<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    
    mydeque = result;
}
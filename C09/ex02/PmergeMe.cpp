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

std::vector<int> PmergeMe::getSequence(size_t size) {
    std::vector<int> sequence;
    sequence.push_back(0);
    sequence.push_back(1);

    while (sequence.back() < static_cast<int>(size)) {
        sequence.push_back((sequence.back() + 2 * sequence[sequence.size() - 2]));
    }

    return sequence;
}

std::vector<int> PmergeMe::insertionPos(size_t size) {
    std::vector<int> sequence = getSequence(size);
    std::vector<int> order;
    std::vector<bool> used(size, false);
    used[0] = true;

    for (size_t i = 1; i < sequence.size() && sequence[i] < static_cast<int>(size); i++)
    {
        if (!used[sequence[i]]) {
            order.push_back(sequence[i]);
            used[sequence[i]] = true;
        }
        
        for (int j = sequence[i] - 1; j > sequence[i-1]; j--) {
            if (j < (int)size && !used[j]) {
                order.push_back(j);
                used[j] = true;
            }
        }
    }

    for (size_t i = 1; i < size; i++) {
        if (!used[i]) {
            order.push_back(i);
        }
    }

    return order;
}

void PmergeMe::sortVector() {
    std::vector<int> mainchain;
    std::vector<int> pendchain;
    std::vector<std::pair<int, int> > pairs;
    
    int straggler = -1;
    (void)straggler;
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
        // std::cout << pairs[i].first << std::endl;
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
        // std::vector<int> insertionOrder = getInser
        std::vector<int> insertionOrder = insertionPos(pendchain.size());
        
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
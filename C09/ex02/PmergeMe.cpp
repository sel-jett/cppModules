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

void PmergeMe::sortVector() {
    std::vector<int> mainchain;
    std::vector<int> pendchain;
    std::vector<int> result;
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
        std::cout << pairs[i].first << std::endl;
    }

    if (mainchain.size() > 1) {
        myvector2 = mainchain;
        sortVector();
        mainchain = myvector2;
    }

    if (!pendchain.empty()) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), pendchain[0]);
        result.insert(pos, pendchain[0]);
    }

    if (straggler != -1) {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    myvector2 = result;
}
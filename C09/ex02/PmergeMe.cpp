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

std::vector<int> PmergeMe::getVector() const {
    return myvector;
}

void PmergeMe::setVector(std::vector<int> vvector) {
    this->myvector = vvector;
}

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

#include "iter.hpp"

void    print(int i) {
    std::cout << i << " ";
}

void    printStr(std::string i) {
    std::cout << i << " ";
}

int main ( void ) {
    // ======================================== Test 1 ===============================================
	std::cout << "\033[1;32m// ======================================== Test 1 ===============================================\033[0m" << std::endl;
    int array[] = {1, 2, 3, 4};
    size_t sizee = sizeof(array) / sizeof(int);
    ::iter(array, sizee, print);
    std::cout << std::endl;

    // ======================================== Test 2 ===============================================
	std::cout << "\033[1;32m// ======================================== Test 2 ===============================================\033[0m" << std::endl;
    std::string array2[] = {"1", "2", "3", "4"};
    size_t sizee2 = sizeof(array2) / sizeof(std::string);
    ::iter(array2, sizee2, printStr);
    std::cout << std::endl;
    

    return (0);
}
#include "easyfind.hpp"
#include <vector>
#include <algorithm>

int main( void ) {
    std::vector<int> test;
    test.push_back(1);
    test.push_back(20);
    try {
        // ======================================== Test 1 ===============================================
	std::cout << "\033[1;32m// ======================================== Test 1 ===============================================\033[0m" << std::endl;
    int n = easyfind(test, 200);
    std::cout << "Found occ of " << n << std::endl;
    } catch ( std::string& e ) {
        std::cerr << e << std::endl;
    }
    try
    {
        // ======================================== Test 2 ===============================================
    std::cout << "\033[1;32m// ======================================== Test 2 ===============================================\033[0m" << std::endl;
    int n = easyfind(test, 20);
    std::cout << "Found occ of " << n << std::endl;
    }
    catch(std::string& e)
    {
        std::cerr << e << '\n';
    }

    try
    {
        // ======================================== Test 3 ===============================================
    std::cout << "\033[1;32m// ======================================== Test 3 ===============================================\033[0m" << std::endl;
    int n = easyfind(test, 1);
    std::cout << "Found occ of " << n << std::endl;
    }
    catch(std::string& e)
    {
        std::cerr << e << '\n';
    }
    
    
    return (0);
}
#include "BitcoinExchange.hpp"

int main (int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.readData(av[1]);
    // btc.printData();
    // std::cout << "data printed" << std::endl;
    return 0;
}
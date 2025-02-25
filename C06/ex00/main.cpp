#include "ScalarConverter.hpp"


int main (int ac, char **av) {
    if (ac < 2) {
        std::cerr << "No arguments were given" << std::endl;
        return 0;
    }
    ScalarConverter b;
    b.convert(std::string(av[1]));
    return 0;
}
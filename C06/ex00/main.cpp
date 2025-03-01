#include "ScalarConverter.hpp"

int main ( int ac, char **av ) {
    if (ac != 2) {
        std::cerr << "command : ./Converter <arg>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
}